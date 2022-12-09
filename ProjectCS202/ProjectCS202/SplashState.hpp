#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "State.hpp"
#include "Game.hpp"

//put int main() like this to run
/*int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    SplashState splashState;
    while (splashState.isRunning())
    {
        splashState.update();
        splashState.render();
    }

    return 0;
}*/

class SplashState{
private:
    sf::RenderWindow *window;
    sf::VideoMode *vm;
    sf::Event ev;
    // Text and Font
    sf::Font font;
    sf::Text text;
    // Background
    sf::Sprite splashState;
    sf::Texture splashStateTex;
    void initWindow();
    void initText();
    void initSplashState();
	
public:
    SplashState();
    const bool isRunning() const;
    void pollEvents();
    void update();
    void render();
    void renderText(sf::RenderTarget &target);
    ~SplashState();
};

	// class SplashState : public State
	// {
	// public:
	// 	SplashState(GameDataRef data);

	// 	void Init();
		
	// 	void HandleInput();
	// 	void Update(float dt);
	// 	void Draw(float dt);

	// private:
	// 	GameDataRef _data;

	// 	sf::Clock _clock;

	// 	sf::Sprite _background;
	// };