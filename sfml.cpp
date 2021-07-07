#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Windmill!");
    
    int i = 0;
    
    

    while (window.isOpen())
    {
        sf::CircleShape shape(50.f,3);
        shape.setPosition(100.f, 100.f);
        shape.setOrigin(50.f,50.f);
        shape.setFillColor(sf::Color::Red);
        shape.setRotation(1.f+i);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(shape);
       
        window.display();
        
        if (event.type == sf::Event::EventType::KeyPressed)
		{
        
        i+=1;

        if (i == 360) i = 0;
        }
	}

    return 0;
}
