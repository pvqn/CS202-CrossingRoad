#include "FinishedWinState.h"
FinishedWinState::FinishedWinState(GameDataRef data) : _data(data)
{
}

void FinishedWinState::Init()
{

    this->_data->assets.LoadTexture("Win Background", FINISHED_WIN_BACKGROUND_FILEPATH);
    this->_data->assets.LoadTexture("Win Title", FINISHED_TITLE_BACKGROUND_FILEPATH);

    _background.setTexture(this->_data->assets.GetTexture("Win Background"));
    _title.setTexture(this->_data->assets.GetTexture("Win Title"));
    _title.setPosition(268.5f, 294.0f);
}

void FinishedWinState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }
        if (clock.getElapsedTime().asSeconds() >= BEFORE_GAME_APPEAR_TIME)
        {
            _data->machine.AddState(StateRef(new GameState(_data)), true);
        }
    }
}

void FinishedWinState::Update(float dt)
{
}

void FinishedWinState::Draw(float dt)
{
    this->_data->window.clear(sf::Color::Red);

    this->_data->window.draw(this->_background);
    this->_data->window.draw(this->_title);
    this->_data->window.display();
}