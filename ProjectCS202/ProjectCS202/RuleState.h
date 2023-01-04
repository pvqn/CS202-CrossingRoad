#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class RuleState
{
private:
    sf::RenderWindow* window;
    sf::VideoMode* vm;
    sf::Event ev;

    // background
    sf::Sprite rule;
    sf::Texture ruleTex;

    //buttons vector
    std::vector<sf::Sprite> Buttons;
    std::vector<sf::Texture> ButtonsTex;

    // Mouse
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    void initWindow();
    void initRuleMenu();
    void initButtons();

public:
    RuleState();
    void updateMousePos();
    const bool isRunning() const;
    void loadButton(int index, std::string file);
    void pollEvents();
    void update();
    void render();
    ~RuleState();
};

