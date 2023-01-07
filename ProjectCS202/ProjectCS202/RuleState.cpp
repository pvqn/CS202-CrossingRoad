#include "RuleState.h"

//void RuleState::initWindow()
//{
//    this->vm = new sf::VideoMode(1024, 728);
//    this->window = new sf::RenderWindow(*this->vm, "ProjectCS202", sf::Style::Titlebar | sf::Style::Close);
//
//    this->window->setFramerateLimit(60);
//}

void RuleState::Init() {
    if (this->ruleTex.loadFromFile("Resources/res/rule.png") == false)
        std::cout << "rule:: Failed to load texture" << "\n";
    this->rule.setTexture(this->ruleTex);

    this->Buttons.resize(2);
    this->ButtonsTex.resize(2);
    loadButton(0, "Resources/res/exitbutton.png");
    loadButton(1, "Resources/res/menubutton.png");

    this->Buttons[0].setPosition(26.0f, 26.0f);
    this->Buttons[1].setPosition(83.0f, 26.0f);
}

RuleState::RuleState(GameDataRef data) : _data(data)
{
}

void RuleState::loadButton(int index, std::string file) {
    if (this->ButtonsTex[index].loadFromFile(file) == false)
        std::cout << "rule:: Failed to load button" << "\n";
    this->Buttons[index].setTexture(this->ButtonsTex[index]);
}

void RuleState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type || this->_data->input.IsSpriteClicked(Buttons[0], sf::Mouse::Left, this->_data->window))
        {
            this->_data->window.close();
        }
        if (this->_data->input.IsSpriteClicked(Buttons[1], sf::Mouse::Left, this->_data->window))
        {
            _data->machine.AddState(StateRef(new MainMenuState(_data)), true);
        }
    }
}

void RuleState::Update(float dt)
{
}

void RuleState::Draw(float dt) {
    this->_data->window.clear();
    this->_data->window.draw(rule);
    for (int i = 0; i < 2; i++) {
        this->_data->window.draw(this->Buttons[i]);
    }
    this->_data->window.display();
}

RuleState:: ~RuleState() {}