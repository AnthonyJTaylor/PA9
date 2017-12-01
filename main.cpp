#include <SFML/Graphics.hpp>
#include<iostream>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
const int port = 303;
const std::string ip("69.166.47.148");
sf::TcpSocket socket;
sf::Mutex mutex; //blocking control


bool client(void)
{
	if (socket.connect(ip, port) == sf::Socket::Done)
	{
		std::cout << "Connected" << std::endl;
		return true;
	}
	return false;
}
void manage(void)
{
	std::string msg;
	sf::Packet in; //input package
	std::cout << "Entering connection controller" << std::endl;
	if (client())
	{
		mutex.lock();
		socket.receive(in);
		in >> msg;
		mutex.unlock();
		if (msg == "package_in")
		{
			std::cout << "Package recieved" << std::endl;
		}
		else
		{
			std::cout << "Incorrect package" << std::endl;
		}
	}
	else
	{
		std::cout << "Failed connection" << std::endl;
	}
}
int main(void)
{
	sf::Thread net_thread(&manage);
	net_thread.launch();
}