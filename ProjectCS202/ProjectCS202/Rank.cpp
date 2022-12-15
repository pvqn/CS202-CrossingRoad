#include "Rank.hpp"


string Player::getStringPlayer() {
    string le = std::to_string(level);
    string h,m,s;
    if(time.hh >= 10) {
        string h1 = to_string(seperate1(time.hh));
        string h2 = to_string(seperate2(time.hh));
        h = h1 + h2;
    } else h = std::to_string(time.hh);
    if(time.mm >= 10) {
        string m1 = to_string(seperate1(time.mm));
        string m2 = to_string(seperate2(time.mm));
        m = m1 + m2;
    } else m = std::to_string(time.mm);
    if(time.ss >= 10) {
        string s1 = to_string(seperate1(time.ss));
        string s2 = to_string(seperate2(time.ss));
        s = s1 + s2;
    } else s = std::to_string(time.ss);
    string str = le + "   " + h + ":" + m + ":" + s;
    return str;
}


bool comparePlayerLevel(Player p1, Player p2) {
    return (p1.level > p2.level);
}
bool comparePlayerTime(Player p1, Player p2) {
    if(p1.time.hh < p2.time.hh) return (p1.time.hh < p2.time.hh);
    else if(p1.time.hh == p2.time.hh && p1.time.mm < p2.time.mm) return (p1.time.mm < p2.time.mm);
    return (p1.time.mm == p2.time.mm && p1.time.ss < p2.time.ss);
}

void Rank::read_File_Rank() {
    ifstream fin;
   fin.open("RANK_FILE_FILEPATH", ios::in);
    if(fin.is_open()) {
        int n;
        fin >> n; fin.ignore();
        for(int i = 0; i < n; ++i) {
            int level;
            Time time;
            fin >> level;
            fin >> time.hh >> time.mm >> time.ss;
            fin.ignore();
            Player p(level, time);
            players.push_back(p);
        }
        fin.close();
    }
    else {
        cout << "Open file rank failed!" << endl;
    }
}
void Rank::write_File_Rank() {
    ofstream fout;
    fout.open("RANK_FILE_FILEPATH", ios::out);
    if(fout.is_open()) {
        this->sortRank();
        fout << players.size() << endl;
        for(int i = 0; i < players.size(); ++i) {
            fout << players[i].level << " ";
            fout << players[i].time.hh << " " << players[i].time.mm << " " << players[i].time.ss;
            fout << endl;
        }
        fout.close();
    }
    else {
        cout << "Open file rank failed!" << endl;
    }
}

void Rank::sortRank() {
    sort(players.begin(), players.end(), comparePlayerTime);
    sort(players.begin(), players.end(), comparePlayerLevel);
}

void Rank::set_Font(string font) {
   _font.loadFromFile(FONT_FOLDER_FILEPATH + font + ".ttf");
    for(int i = 0; i < _texts.size(); ++i) {
        _texts[i].setFont(_font);
    }
}
void Rank::set_Texts() {
    for(int i = 0; i < players.size(); ++i) {
        string s;
        s = std::to_string(i+1) + " " + players[i].getStringPlayer() + '\n';
        sf::Text t;
        t.setString(s);
        _texts.push_back(t);
    }
}
void Rank::set_Texts_PosXY(const float x, const float y) {
    for(int i = 0; i < _texts.size(); ++i) {
        _texts[i].setPosition(x, (i + 1) * 100 + y);
    }
}
void Rank::set_Texts_Size(const float x, const float y) {
    for(int i = 0; i < _texts.size(); ++i) {
        _texts[i].scale(sf::Vector2f(x,y));
    }
}
const sf::Vector2f Rank::get_Texts_Pos() {
    return _texts[0].getPosition();
}
const sf::Vector2f Rank::get_Texts_Size() {
    return _texts[0].getScale();
}
void Rank::draw_Texts(sf::RenderTarget& window) {
    for(int i = 0; i < _texts.size(); ++i) {
        window.draw(_texts[i]);
    }
}


void Rank::set_Texture1() {
   this->_texture.loadFromFile(LOSE_RANK_BACKGROUND_FILEPATH);
}
void Rank::set_Texture2() {
   this->_texture.loadFromFile(RANK_STATE_BACKGROUND_FILEPATH);
}
void Rank::set_Sprite() {
    _sprite.setTexture(_texture);
}
void Rank::set_PosXY(const float x, const float y) {
    _sprite.setPosition(sf::Vector2f(x,y));
}
void Rank::set_Size(const float x, const float y) {
    _sprite.scale(sf::Vector2f(x,y));

}
const sf::Vector2f Rank::get_Pos() const {
    return _sprite.getPosition();
}
const sf::Vector2f Rank::get_Size() const {
    return _sprite.getScale();
}
void Rank::draw(sf::RenderTarget& window) {
    window.draw(_sprite);
}

Rank::Rank() {
    //        BACKGROUND
    this->set_Texture2();
    this->set_Sprite();
//        pass value
//        this->set_PosXY(x ,y);
//        this->set_Size(x, y);
    
//        TEXT
    this->read_File_Rank();
    this->sortRank();
    this->set_Texts();
//        pass value
//        this->set_Font(font name)
//        this->set_Texts_PosXY(x, y);
//        this->set_Size(x, y);
}

Rank::Rank(int level, float ftime) {
    Player newPlayer(level, ftime);
    players.push_back(newPlayer);
    
//        BACKGROUND
  
//        pass value
//        this->set_PosXY(x ,y);
//        this->set_Size(x, y);
    
//        TEXT
    this->read_File_Rank();
    this->sortRank();
    this->set_Texts();
//        pass value
//        this->set_Font(font name)
//        this->set_Texts_PosXY(x, y);
//        this->set_Size(x, y);
    this->write_File_Rank();
}
