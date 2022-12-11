#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "State.hpp"
#include "Game.hpp"

#define Max_main_menu 7

/*class MainMenuState {
private:
    sf::RenderWindow* window;
    sf::VideoMode* vm;
    sf::Event ev;

      background
    sf::Sprite MainMenu;
    sf::Texture mainMenuTex;

     buttons vector
    std::vector<sf::Sprite> Buttons;
    std::vector<sf::Texture> ButtonsTex;

      Mouse
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    int curMenu;
    void initWindow();
    void initMainMenu();
    void initButtons();

public:
    MainMenuState();
    void updateMousePos();
    const bool isRunning() const;
    void loadButton(int index, std::string file);
    void loadSelectedButton(int index);
    void loadPreviousButton(int index);
    void pollEvents();
    void update();
    void render();
    ~MainMenuState();
};
*/
	 class MainMenuState : public State
	  {
	  public:
	  	MainMenuState(GameDataRef data);

	  	void Init();

	  	void HandleInput();
	  	void Update(float dt);
	  	void Draw(float dt);

	  private:
	  	GameDataRef _data;

	  	sf::Sprite _background;
      sf::Sprite _menuTitle;

	  	sf::Sprite _playButton;
      sf::Sprite _rankButton;
      sf::Sprite _loadButton;
      sf::Sprite _ruleButton;

      sf::Sprite _menuButton;
      sf::Sprite _exitButton;

	  };
