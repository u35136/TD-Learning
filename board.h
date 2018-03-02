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
    const bool Compare(int last_table[][4]) const;
    const bool Win() const {return win;};
    void Replace(int new_table[][4]);//new to this

<<<<<<< HEAD
    void Replace(const int new_table[][4]);//new to this

    int Move(const Option &opt);//return score
<<<<<<< HEAD
<<<<<<< HEAD
    void Move(const Option &opt, int temp[][4]) const; //for AI
=======
    int Move(const Option &opt);
    int Move_up();//return score
    int Move_down();
    int Move_right();
    int Move_left();
>>>>>>> parent of 44143b8... 朝乾淨的程式碼前進
=======
    void Move(const Option &opt,int temp[][4]) const;//for AI
>>>>>>> parent of b13c212... 有一層美好未來的 均分1w9 極大7w5
=======
    void Move(const Option &opt,int temp[][4]) const;//for AI
>>>>>>> parent of b13c212... 有一層美好未來的 均分1w9 極大7w5

    int Randon_add();//return empty size
    void New();
    bool Failed();

    //for AI
    void Move_up(int temp[][4]) const;//return score
    void Move_down(int temp[][4]) const;
    void Move_right(int temp[][4]) const;
    void Move_left(int temp[][4]) const;
    void Copy_choice_and_check(int new_table[][4]) ;//copy and check win
private:
    int table[4][4] = {{0}};
    bool win = false;
};
/*{{1,2,1,3},{4,2,4,2},{0,6,5,6},{7,8,8,7}};*/
#endif
