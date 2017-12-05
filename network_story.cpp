sf::Text story("A man enters your booth raving about the merrits of long action large calliber rifels for war as compared to the currrently accepted docterine using smaller callibers and supression fire. Believing him to be a high ordinator of the holy church of Kube you feel you should accept him into the city");
sf::Text pass("You allow the man into the city, he thanks you and hands you a spam can filled with ammunation for your duty rifle. As he walks through the barriers to the city you hear him  ranting about sptizer ammunition being the devils pills. You feel the glowing merrits of hardball ammunition in your heart. +1 life");
sf::Text fail("The man declares I am a cardinal of the Kube, Feel the might of 7.62 x 63 After one of the mans bodyguards shoots you, you feel deep pain. Not just from the gaping flesh wound but also deep shame from failing your training and intution. The man and his entourage then walks through your baricade unmolested. -2 life");

      story.draw();
			while(window.pollEvent(event) != sf::Event::Closed)
			{
				if(keyboard.isKeyPressed((sf::Keyboard::Z)){
					fail.draw();
          data.decrementlives();
          data.decrementlives();
					break;
				}
				else if(keyboard.isKeyPressed((sf::Keyboard::X){
					pass.draw();
					break;	
				}
      }
