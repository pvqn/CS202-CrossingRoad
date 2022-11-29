
/*#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>
int main()
{
std::cout <<"hello world";   
system("pause"); 
    return 0;
}
*/
#include "DEFINITIONS.hpp"
#include "Game.hpp"
int main()
{
    /*
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    Human *test=new Human;
std::cout <<"hello";

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        test->move();
        test->updateCollision(window);
        test->render(window);
        window.display();
    }
  
 delete test;*/
 Game(SCREEN_WIDTH,SCREEN_HEIGHT,"test");
    return 0;
}