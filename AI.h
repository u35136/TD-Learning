#ifndef AI_
#define AI_

#include "board.h"
#include <bits/stdc++.h>
#include <map>
#include <sstream>
#include <fstream>
#define L_rate 0.25
#define Failed_score -10
class AI
{
public:
    //AI();
    int Go(Board &board);//return round_score
    void Save(string &filename,const int &win,const int &failed)const;
    void Load(string &filename)const;

    bool Diff_step(const Option &opt, const Board &board, double &table_score);//return option's score
    double Table_score(const int table[][4]);
    void Reward(const int table[][4], double max_table_score, const int &round_score);
    void Failed_reward(const int &score);
private:
    map <string, double> myscore;
    int old_table[4][4];
    //vector <int[4][4]> last;
    vector <string> mapkey;
};

#endif
