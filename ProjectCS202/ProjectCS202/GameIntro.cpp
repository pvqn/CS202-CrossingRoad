#include"GameIntro.h"

void mainMenu::initWindow()
{
    this->vm = new sf::VideoMode(1024, 728);
    this->window = new sf::RenderWindow(*this->vm, "ProjectCS202", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

void mainMenu::initText()
{
    if (!this->font.loadFromFile("Resources/fonts/Quicksand-Regular.otf"))
        std::cout << "ERROR::GAME::INITTEXT::failed to load font from file\n";
    this->text.setFillColor(sf::Color(102,153,0));//669900
    this->text.setFont(this->font);
    this->text.setCharacterSize(30);
    this->text.setString("Press Enter to continue...");
    this->text.setPosition(330.0f,375.0f);
}

void mainMenu:: initMainMenu(){
    if (this->mainMenuTex.loadFromFile("Resources/res/background1.png") == false)
        std::cout << "GAME:: Failed to load texture"
                  << "\n";
    std::cout << "SUCCESS\n";
    this->MainMenu.setTexture(this->mainMenuTex);
}

mainMenu:: mainMenu(){
    initWindow();
    initMainMenu();
    initText();
}

const bool mainMenu::isRunning() const
{
    return this->window->isOpen();
}

void mainMenu::pollEvents()
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
                Game game;
                while (game.isRunning())
                {
                    game.update();
                    game.render();
                }
            }
            break;
        default:
            break;
        }
    }
}

void mainMenu::update()
{
    this->pollEvents();
}

void mainMenu:: render(){
    this->window->clear();
    this->window->draw(MainMenu);
    this->renderText(*this->window);
    this->window->display();
}

void mainMenu::renderText(sf::RenderTarget &target)
{
    target.draw(this->text);
}

mainMenu:: ~mainMenu(){}