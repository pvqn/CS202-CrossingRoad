#include "MainMenuState.hpp"
/*
void MainMenuState::initWindow()
{
    this->vm = new sf::VideoMode(1024, 768);
    this->window = new sf::RenderWindow(*this->vm, "ProjectCS202", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

void MainMenuState::initMainMenu() {
    if (this->mainMenuTex.loadFromFile("Resources/res/background2.png") == false)
        std::cout << "mainMenu:: Failed to load texture"
        << "\n";
    std::cout << "SUCCESS\n";
    this->MainMenu.setTexture(this->mainMenuTex);
}

void MainMenuState::initButtons() {
    this->curMenu = 3;  menu1button
    this->Buttons.resize(Max_main_menu);
    this->ButtonsTex.resize(Max_main_menu);

    loadButton(0, "Resources/res/exitbutton.png");
    loadButton(1, "Resources/res/menubutton.png");
    loadButton(2, "Resources/res/menu1button.png");
    loadButton(3, "Resources/res/playbutton1.png");  playbutton status at the beginning: selected playbutton
    loadButton(4, "Resources/res/loadbutton.png");
    loadButton(5, "Resources/res/rankbutton.png");
    loadButton(6, "Resources/res/rulebutton.png");

    this->Buttons[0].setPosition(26.0f, 26.0f);
    this->Buttons[1].setPosition(83.0f, 26.0f);
    this->Buttons[2].setPosition(425.0f, 230.0f);
    this->Buttons[3].setPosition(460.0f, 306.0f);
    this->Buttons[4].setPosition(460.0f, 363.0f);
    this->Buttons[5].setPosition(450.0f, 420.0f);
    this->Buttons[6].setPosition(460.0f, 480.0f);
}

MainMenuState::MainMenuState() {
    initWindow();
    initMainMenu();
    initButtons();
}

const bool MainMenuState::isRunning() const
{
    return this->window->isOpen();
}

void MainMenuState::loadButton(int index, std::string file) {
    if (this->ButtonsTex[index].loadFromFile(file) == false)
        std::cout << "mainMenu:: Failed to load button"
        << "\n";
    std::cout << "SUCCESS\n";
    this->Buttons[index].setTexture(this->ButtonsTex[index]);
}

void MainMenuState::loadSelectedButton(int index) {
    switch (index) {
    case 3: loadButton(3, "Resources/res/playbutton1.png");
        break;
    case 4: loadButton(4, "Resources/res/loadbutton1.png");
        break;
    case 5: loadButton(5, "Resources/res/rankbutton1.png");
        break;
    case 6: loadButton(6, "Resources/res/rulebutton1.png");
        break;
    default:
        break;
    }
}

void MainMenuState::loadPreviousButton(int index) {
    switch (index) {
    case 3: loadButton(3, "Resources/res/playbutton.png");
        break;
    case 4: loadButton(4, "Resources/res/loadbutton.png");
        break;
    case 5: loadButton(5, "Resources/res/rankbutton.png");
        break;
    case 6: loadButton(6, "Resources/res/rulebutton.png");
        break;
    default:
        break;
    }
}

void MainMenuState::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Enter)
            {
                switch (curMenu)
                {
                case 3:
                {
                    Game game;
                    while (game.isRunning())
                    {
                        game.update();
                        game.render();
                    }
                    break;
                }
                default:
                    break;
                }
            }
            if (this->ev.key.code == sf::Keyboard::Up) {
                loadPreviousButton(curMenu);
                curMenu--;
                if (curMenu < 3) curMenu = Max_main_menu - 1;
                loadSelectedButton(curMenu);

            }
            if (this->ev.key.code == sf::Keyboard::Down) {
                loadPreviousButton(curMenu);
                curMenu++;
                if (curMenu >= Max_main_menu) curMenu = 3;
                loadSelectedButton(curMenu);
            }
            break;
        case sf::Event::MouseButtonPressed:
            if (this->ev.mouseButton.button == sf::Mouse::Left) {
                for (int i = 0; i < Max_main_menu; i++)
                {
                    if (this->Buttons[i].getGlobalBounds().contains(this->mousePosView))
                    {
                        switch (i) {
                        case 0: this->window->close();
                                break;
                        case 1: this->window->close();
                                break;
                        case 3:
                        {
                            Game game;
                            while (game.isRunning())
                            {
                                game.update();
                                game.render();
                            }
                            break;
                        }
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

void MainMenuState::updateMousePos()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void MainMenuState::update()
{
    this->updateMousePos();
    this->pollEvents();
}

void MainMenuState::render() {
    this->window->clear();
    this->window->draw(MainMenu);
    for (int i = 0; i < Max_main_menu; i++) {
        this->window->draw(this->Buttons[i]);
    }
    this->window->display();
}

MainMenuState:: ~MainMenuState() {}
*/
int GameState::_level=1;

MainMenuState::MainMenuState(GameDataRef data) : _data(data)
{
}

void MainMenuState::Init()
{
    this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
    this->_data->assets.LoadTexture("Menu Title", MENU_TITLE_FILEPATH);

    this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
    this->_data->assets.LoadTexture("Play1 Button", PLAY1_BUTTON_FILEPATH);

    this->_data->assets.LoadTexture("Load Button", LOAD_BUTTON_FILEPATH);
    this->_data->assets.LoadTexture("Load1 Button", LOAD1_BUTTON_FILEPATH);

    this->_data->assets.LoadTexture("Rank Button", RANK_BUTTON_FILEPATH);
    this->_data->assets.LoadTexture("Rank1 Button", RANK1_BUTTON_FILEPATH);

    this->_data->assets.LoadTexture("Rule Button", RULE_BUTTON_FILEPATH);
    this->_data->assets.LoadTexture("Rule1 Button", RULE1_BUTTON_FILEPATH);

    this->_data->assets.LoadTexture("Exit Button", EXIT_BUTTON_FILEPATH);
    this->_data->assets.LoadTexture("Menu Button", MENU_BUTTON_FILEPATH);

    _background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
    _menuTitle.setTexture(this->_data->assets.GetTexture("Menu Title"));

    _playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
    _rankButton.setTexture(this->_data->assets.GetTexture("Rank Button"));
    _ruleButton.setTexture(this->_data->assets.GetTexture("Rule Button"));
    _loadButton.setTexture(this->_data->assets.GetTexture("Load Button"));

    _menuButton.setTexture(this->_data->assets.GetTexture("Menu Button"));
    _exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));

    _exitButton.setPosition(26.0f, 26.0f);
    _menuButton.setPosition(83.0f, 26.0f);

    _menuTitle.setPosition(425.0f, 215.0f);
    _playButton.setPosition(460.0f, 291.0f);
    _loadButton.setPosition(460.0f, 348.0f);
    _rankButton.setPosition(450.0f, 405.0f);
    _ruleButton.setPosition(460.0f, 465.0f);
}

void MainMenuState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }

        // check clicked
        if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
        {
            this->_data->machine.AddState(StateRef(new GameState(_data)), true);
        }

        // check hovered
        if (this->_data->input.IsHover(this->_playButton, this->_data->window))
        {
            _playButton.setTexture(this->_data->assets.GetTexture("Play1 Button"));
        }
        else
            _playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
        if (this->_data->input.IsHover(this->_loadButton, this->_data->window))
        {
            _loadButton.setTexture(this->_data->assets.GetTexture("Load1 Button"));
        }
        else
            _loadButton.setTexture(this->_data->assets.GetTexture("Load Button"));
        if (this->_data->input.IsHover(this->_ruleButton, this->_data->window))
        {
            _ruleButton.setTexture(this->_data->assets.GetTexture("Rule1 Button"));
        }
        else
            _ruleButton.setTexture(this->_data->assets.GetTexture("Rule Button"));
        if (this->_data->input.IsHover(this->_rankButton, this->_data->window))
        {
            _rankButton.setTexture(this->_data->assets.GetTexture("Rank1 Button"));
        }
        else
            _rankButton.setTexture(this->_data->assets.GetTexture("Rank Button"));
    }
}

void MainMenuState::Update(float dt)
{
}

void MainMenuState::Draw(float dt)
{
    this->_data->window.clear(sf::Color::Red);

    this->_data->window.draw(this->_background);
    this->_data->window.draw(this->_menuTitle);

    this->_data->window.draw(this->_exitButton);
    this->_data->window.draw(this->_menuButton);

    this->_data->window.draw(this->_playButton);
    this->_data->window.draw(this->_rankButton);
    this->_data->window.draw(this->_ruleButton);
    this->_data->window.draw(this->_loadButton);

    this->_data->window.display();
}
