//
//  Rank.hpp
//  main
//
//  Created by Apple on 09/12/2022.
//  Copyright © 2022 Apple. All rights reserved.
//

#ifndef Rank_hpp
#define Rank_hpp

#include "Game.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

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
    
    int hh;
    int mm;
    int ss;
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
    void print() {
        cout << "  " << level << "     " << time.hh << ":" << time.mm << ":" << time.ss << endl;
    }
    int level;
    Time time;
};

class Rank {
public:
    Rank(){};
    Rank(int level, float ftime) {
        Player newPlayer(level, ftime);
        players.push_back(newPlayer);
    }
    void read_File_Rank(string);
    void sortRank();
    void printRank();
private:
    vector<Player> players;
};

#endif /* Rank_hpp */
