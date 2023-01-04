#include "RuleState.h"

void RuleState::initWindow()
{
    this->vm = new sf::VideoMode(1024, 728);
    this->window = new sf::RenderWindow(*this->vm, "ProjectCS202", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

void RuleState::initRuleMenu() {
    if (this->ruleTex.loadFromFile("Resources/res/rule.png") == false)
        std::cout << "rule:: Failed to load texture"
        << "\n";
    std::cout << "SUCCESS\n";
    this->rule.setTexture(this->ruleTex);
}

void RuleState::initButtons() {
    this->Buttons.resize(2);
    this->ButtonsTex.resize(2);
    loadButton(0, "Resources/res/exitbutton.png");
    loadButton(1, "Resources/res/menubutton.png");

    this->Buttons[0].setPosition(26.0f, 26.0f);
    this->Buttons[1].setPosition(83.0f, 26.0f);
}

RuleState::RuleState() {
    initWindow();
    initRuleMenu();
    initButtons();
}

const bool RuleState::isRunning() const
{
    return this->window->isOpen();
}

void RuleState::loadButton(int index, std::string file) {
    if (this->ButtonsTex[index].loadFromFile(file) == false)
        std::cout << "rule:: Failed to load button"
        << "\n";
    std::cout << "SUCCESS\n";
    this->Buttons[index].setTexture(this->ButtonsTex[index]);
}

void RuleState::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        case sf::Event::MouseButtonPressed:
            if (this->ev.mouseButton.button == sf::Mouse::Left) {
                for (int i = 0; i < 2; i++)
                {
                    if (this->Buttons[i].getGlobalBounds().contains(this->mousePosView))
                    {
                        switch (i) {
                        case 0: this->window->close();
                            break;
                        case 1: this->window->close();
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        default:
            break;
        }
    }
}

void RuleState::updateMousePos()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void RuleState::update()
{
    this->updateMousePos();
    this->pollEvents();
}

void RuleState::render() {
    this->window->clear();
    this->window->draw(rule);
    for (int i = 0; i < 2; i++) {
        this->window->draw(this->Buttons[i]);
    }
    this->window->display();
}

RuleState:: ~RuleState() {}