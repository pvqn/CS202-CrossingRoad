#pragma once
#include "State.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class RuleState : public State
{
private:
    GameDataRef _data;

    // background
    sf::Sprite rule;
    sf::Texture ruleTex;

    //buttons vector
    std::vector<sf::Sprite> Buttons;
    std::vector<sf::Texture> ButtonsTex;

    // Mouse
    //sf::Vector2i mousePosWindow;
    //sf::Vector2f mousePosView;

    //void initWindow();
    //void initRuleMenu();
    //void initButtons();

public:
    RuleState(GameDataRef data);
    void Init();
    void HandleInput();
    void Update(float dt);
    void Draw(float dt);
    void loadButton(int index, std::string file);
    /*void pollEvents();
    void update();
    void render();*/
    ~RuleState();
};

