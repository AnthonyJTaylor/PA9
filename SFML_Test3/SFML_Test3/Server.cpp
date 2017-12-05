#include <SFML/Graphics.hpp>
#include<iostream>
#include <SFML/Network.hpp>
const int port = 303;
std::string ip("192.168.0.100");
sf::TcpSocket socket;
const std::string msg("go");

void server(void)
{
	sf::TcpListener listner;
	listner.setBlocking(true);
	listner.listen(port);
	listner.accept(socket);
}
void pusher(void)
{
	server();
	sf::Packet packet_o;
	while (1)
	{
		std::cin.get(); //get user input, dont do anything
		packet_o << msg; // push string into packet
		socket.send(packet_o);
	}
}
int main(void)
{
	std::cout << "Input output ip: ";
	std::cin >> ip;
	pusher();
}
