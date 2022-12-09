#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include"Game.hpp"
//put int main() like this to run
/*int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    mainMenu MainMenu;
    while (MainMenu.isRunning())
    {
        MainMenu.update();
        MainMenu.render();
    }

    return 0;
}*/
class mainMenu{
private:
    sf::RenderWindow *window;
    sf::VideoMode *vm;
    sf::Event ev;

    // Text and Font
    sf::Font font;
    sf::Text text;

    // Background
    sf::Sprite MainMenu;
    sf::Texture mainMenuTex;
    void initWindow();
    void initText();
    void initMainMenu();

public:
    mainMenu();
    const bool isRunning() const;
    void pollEvents();
    void update();
    void render();
    void renderText(sf::RenderTarget &target);
    ~mainMenu();
};