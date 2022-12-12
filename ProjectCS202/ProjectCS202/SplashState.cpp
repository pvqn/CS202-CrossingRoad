#pragma once

#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"

#include <iostream>
#include "SplashState.hpp"
/*
void SplashState::initWindow()
{
    this->vm = new sf::VideoMode(1024, 768);
    this->window = new sf::RenderWindow(*this->vm, "ProjectCS202", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

void SplashState:: initSplashState(){
    if (this->splashStateTex.loadFromFile("Resources/res/background1.png") == false)
        std::cout << "SplashState:: Failed to load texture"
                  << "\n";
    std::cout << "SUCCESS\n";
    this->splashState.setTexture(this->splashStateTex);
}

void SplashState::initText()
{
    if (!this->font.loadFromFile("Resources/fonts/Quicksand-Regular.otf"))
        std::cout << "ERROR::SplashState::INITTEXT::failed to load font from file\n";
    this->text.setFillColor(sf::Color(102,153,0)); 669900
    this->text.setFont(this->font);
    this->text.setCharacterSize(30);
    this->text.setString("Press Enter to continue...");
    this->text.setPosition(330.0f,400.0f);
}

SplashState:: SplashState(){
    initWindow();
    initSplashState();
    initText();
}

const bool SplashState::isRunning() const
{
    return this->window->isOpen();
}

void SplashState::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Enter){
                MainMenuState mainMenu;
                while (mainMenu.isRunning())
                {
                    mainMenu.update();
                    mainMenu.render();
                }
            }
            break;
        default:
            break;
        }
    }
}

void SplashState::update()
{
    this->pollEvents();
}

void SplashState:: render(){
    this->window->clear();
    this->window->draw(splashState);
    this->renderText(*this->window);
    this->window->display();
}

void SplashState::renderText(sf::RenderTarget &target)
{
    target.draw(this->text);
}
*/


	  SplashState::SplashState(GameDataRef data) : _data(data)
	  {

	  }

	  void SplashState::Init()
	  {
	  	this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
        this->_data->assets.LoadFont("Flappy",FLAPPY_FONT);
        
	  	_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
        _text.setFillColor(sf::Color(242,236,219,255));
        _text.setFont(this->_data->assets.GetFont("Flappy"));
        _text.setCharacterSize(30);
        _text.setString("A PRODUCT OF GROUP 7 APCS2");
        _text.setPosition(300.0f,385.0f);
        _text.setOutlineColor(sf::Color(44,125,59,255));
        _text.setOutlineThickness(1.0f);
        // Press Enter to continue...
        // A product of group 7 APCS2

      }

	  void SplashState::HandleInput()
	  {
	  	sf::Event event;

	  	while (this->_data->window.pollEvent(event))
	  	{
	  		if (sf::Event::Closed == event.type)
	  		{
	  			this->_data->window.close();
	  		}
	  	}
	  }

	  void SplashState::Update(float dt)
	  {
	  	if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	  	{
	  		
	  		this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
	  	}
	  }

	  void SplashState::Draw(float dt)
	  {
	  	this->_data->window.clear(sf::Color::Red);

	  	this->_data->window.draw( this->_background );
        this->_data->window.draw(this->_text);
	  	this->_data->window.display();
	  }

    