#ifndef AI_
#define AI_

#include "board.h"
#include <bits/stdc++.h>
#include <map>
#include <sstream>
#include <fstream>
#define L_rate 0.1

using D2array =array<array<int, 4>, 4>;

struct BoardState
{
    int d2array[4][4];
    double round_score;
};

class AI
{
public:
    //AI();
    int Go(Board &board);//return round_score
    void Save(string &filename, const int &win, const int &failed)const;
    void Load(string &filename, int &win, int &failed);

    bool Diff_step(const Option &opt, const Board &board, double &table_score);//return option's score
    double Table_score(const int table[][4]);
    //void Reward(const int table[][4], double max_table_score, const int &round_score);
    void Failed(Board &board);
private:
    map <string, double> myscore;
    int old_table[4][4];

    vector <BoardState> last;
    vector <string> mapkey;
};

#endif
