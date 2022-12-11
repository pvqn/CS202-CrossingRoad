//
//  Rank.hpp
//  main
//
//  Created by Apple on 09/12/2022.
//  Copyright © 2022 Apple. All rights reserved.
//

#ifndef Rank_hpp
#define Rank_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "DEFINITIONS.hpp"
using namespace std;

struct Time {
    Time(){};
    Time(float ftime) {
        this->convert(ftime);
    }
    void convert(float ftime) {
        if(ftime >= 3600) {
            hh = ftime / 3600;
            ftime -= hh * 3600;
        }
        if(ftime >= 60) {
            mm = ftime / 60;
            ftime -= mm * 60;
        }
        ss = ftime;
    }
    void printTime() {
        cout << hh << ":" << mm << ":" << ss << endl;
    }
    ~Time(){};
    
    int hh = 0;
    int mm = 0;
    int ss = 0;
};

class Player {
public:
    Player(){};
    Player(int level, float ftime) {
        this->level = level;
        time.convert(ftime);
    }
    Player(int level, Time time) :  level(level), time(time) {};
    ~Player(){};
    int seperate1(int a) {
        return a / 10;
    }
    int seperate2(int a) {
        return a % 10;
    }
    string getStringPlayer();
    int level;
    Time time;
};

class Rank {
public:
    // Call default constructor to executive rank state
    // which is chosen is menu state
    Rank(){};
    
    // Call constructor(int, float) to executive lose_Rank
    // Pass in the current level, time at the time user lose
    Rank(int level, float ftime);
    
    void read_File_Rank();
    void write_File_Rank();

    void sortRank();
    
    void set_Font(string font);
    void set_Texts();
    void set_Texts_PosXY(const float x, const float y);
    void set_Texts_Size(const float x, const float y);
    const sf::Vector2f get_Texts_Pos();
    const sf::Vector2f get_Texts_Size();
    void draw_Texts(sf::RenderTarget& window);
    
    void set_Texture1();
    void set_Texture2();
    void set_Sprite();
    void set_PosXY(const float x, const float y);
    void set_Size(const float x, const float y);
    const sf::Vector2f get_Pos() const;
    const sf::Vector2f get_Size() const;
    void draw(sf::RenderTarget& window);
    
    sf::Font _font;
    
    sf::Texture _texture;
    sf::Sprite _sprite;
    
    vector<Player> players;
    vector<string> rankText;
    vector<sf::Text> _texts;
    
private:
    
};


#endif /* Rank_hpp */
