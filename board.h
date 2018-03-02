#ifndef BOARD_
#define BOARD_

#include <bits/stdc++.h>
#include <time.h>
#include <math.h>
#define Table_base 2
#define Win_base 11
using namespace std;

enum Option {UP, DOWN, LEFT, RIGHT};

class Board
{
public:
    void Show()const;
    void Copy_(int new_table[][4]) const;//this to new
    void Copy_to(Board &board) const;
    const bool Compare(int last_table[][4]) const;
    const bool Win() const {return win;};

    void Replace(const int new_table[][4]);//new to this

    int Move(const Option &opt);//return score
    void Move(const Option &opt, int temp[][4]) const; //for AI

    int Randon_add();//return empty size
    void New();
    bool Failed();

private:
    int table[4][4] = {{0}};
    bool win = false;
    void SetWin(const bool &newwin);
    int Move_up();//return score
    int Move_down();
    int Move_right();
    int Move_left();
    //for AI
    void Move_up(int temp[][4]) const;//return score
    void Move_down(int temp[][4]) const;
    void Move_right(int temp[][4]) const;
    void Move_left(int temp[][4]) const;
};
/*{{1,2,1,3},{4,2,4,2},{0,6,5,6},{7,8,8,7}};*/
#endif
