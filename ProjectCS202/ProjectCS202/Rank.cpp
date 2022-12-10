//
//  Rank.cpp
//  main
//
//  Created by Apple on 09/12/2022.
//  Copyright © 2022 Apple. All rights reserved.
//

#include "Rank.hpp"

bool comparePlayerLevel(Player p1, Player p2) {
    return (p1.level > p2.level);
}
bool comparePlayerTime(Player p1, Player p2) {
    if(p1.time.hh < p2.time.hh) return (p1.time.hh < p2.time.hh);
    else if(p1.time.hh == p2.time.hh && p1.time.mm < p2.time.mm) return (p1.time.mm < p2.time.mm);
    return (p1.time.mm == p2.time.mm && p1.time.ss < p2.time.ss);
}

void Rank::read_File_Rank(string path) {
    ifstream fin;
    fin.open(path, ios::in);
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
    }
    else {
        cout << "Open file rank failed!" << endl;
    }
}
void Rank::sortRank() {
    sort(players.begin(), players.end(), comparePlayerTime);
    sort(players.begin(), players.end(), comparePlayerLevel);
}
void Rank::printRankOnTerminal() {
    cout << "-----RANK-----" << endl;
    cout << "LEVEL    TIME" << endl;
    for(int i = 0; i < players.size(); ++i) {
        players[i].print();
    }
}

