#include "board.h"

void Board::Show()const
{
    for(int i = 0; i < 4; ++i)
        {
            for(int j = 0; j < 4; ++j)
            {
                int temp = (pow(Table_base, table[i][j]) == 1)? 0 : pow(Table_base, table[i][j]);
                cout << setw(4) << temp << " ";
            }
            cout << endl;
        }
        cout << endl;
}

void Board::Copy_to(Board &board) const
{
    board.Replace(table);
    board.SetWin(win);
}

 void Board::SetWin(const bool &newwin)
 {
     win=newwin;
 }

void Board::Copy_(int new_table[][4])const
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            new_table[i][j] = table[i][j];
        }
    }
}

const bool Board::Compare(const int last_table[][4])const
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(last_table[i][j] != table[i][j]) return true;
        }
    }
    return false;
}

void Board::New()//necessary????
{
    for(int i = 0;i<4;++i)
    {
        for(int j = 0;j<4;++j)
        {
            table[i][j]=0;
        }
    }
    this->Randon_add();
    this->win = false;
}

bool Board::Failed()
{
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            if((i!=3 && table[i][j]==table[i+1][j]) || (j!=3 && table[i][j]==table[i][j+1]))
            {
                return false;
            }
        }
    }
    return true;
}

void Board::Replace(const int new_table[][4])//new to this
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
             table[i][j] = new_table[i][j];
        }
    }
}

void Board::Move(const Option &opt,int temp[][4])const
{
    if(opt == UP){this->Move_up(temp);}
    else if(opt == DOWN){this->Move_down(temp);}
    else if(opt == LEFT){this->Move_left(temp);}
    else if(opt == RIGHT){this->Move_right(temp);}
}

void Board::Move_up(int temp[][4])const
{
    this->Copy_(temp);
    int score = 0;
    for(int j = 0; j < 4 ; ++j)
    {
        int now_index = 0, last_num = 0;
        for(int i = 0; i < 4; ++i)
        {
            if(last_num != 0 && temp[i][j] == last_num) //same with last number
            {
                last_num = 0;
                temp[now_index - 1][j] += 1;
                //if(temp[now_index - 1][j]==Win_base){win=true;}
                //score += pow(Table_base, temp[now_index - 1][j]);
            }
            else if(temp[i][j] != 0)
            {
                last_num = temp[i][j];
                temp[now_index][j] = temp[i][j];
                now_index += 1;
            }
        }
        while(now_index != 4)
        {
            temp[now_index][j] = 0;
            now_index += 1;
        }
    }
}
void Board::Move_down(int temp[][4]) const
{
    this->Copy_(temp);
    int score = 0;
    for(int j = 0; j < 4 ; ++j)
    {
        int now_index = 3, last_num = 0;
        for(int i = 3; i >= 0; --i)
        {
            if(last_num != 0 && temp[i][j] == last_num) //same with last number
            {
                last_num = 0;
                temp[now_index + 1][j] += 1;
                //if(temp[now_index +1][j]==Win_base){win=true;}
                //score += pow(Table_base, temp[now_index + 1][j]);
            }
            else if(temp[i][j] != 0)
            {
                last_num = temp[i][j];
                temp[now_index][j] = temp[i][j];
                now_index -= 1;
            }
        }
        while(now_index >= 0)
        {
            temp[now_index][j] = 0;
            now_index -= 1;
        }
    }
}

void Board::Move_right(int temp[][4]) const
{
    this->Copy_(temp);
    int score = 0;
    for(int i = 0; i < 4; ++i)
    {
        int now_index = 3, last_num = 0;
        for(int j = 3; j >= 0; --j)
        {
            if(last_num != 0 && temp[i][j] == last_num) //same with last number
            {
                last_num = 0;
                temp[i][now_index + 1] += 1;
                //if(temp[i][now_index + 1]==Win_base){win=true;}
                //score += pow(Table_base, temp[i][now_index + 1]);
            }
            else if(temp[i][j] != 0)
            {
                last_num = temp[i][j];
                temp[i][now_index] = temp[i][j];
                now_index -= 1;
            }
        }
        while(now_index >= 0)
        {
            temp[i][now_index] = 0;
            now_index -= 1;
        }
    }
}

void Board::Move_left(int temp[][4]) const
{
    this->Copy_(temp);
    int score = 0;
    for(int i = 0; i < 4; ++i)
    {
        int now_index = 0, last_num = 0;
        for(int j = 0; j < 4 ; ++j)
        {
            if(last_num != 0 && temp[i][j] == last_num) //same with last number
            {
                last_num = 0;
                temp[i][now_index - 1] += 1;
                //if(temp[i][now_index - 1]==Win_base){win=true;}
                //score += pow(Table_base, temp[i][now_index - 1]);
            }
            else if(temp[i][j] != 0)
            {
                last_num = temp[i][j];
                temp[i][now_index] = temp[i][j];
                now_index += 1;
            }
        }
        while(now_index != 4)
        {
            temp[i][now_index] = 0;
            now_index += 1;
        }
    }
}

int Board::Move(const Option &opt)
{
    if(opt == UP){return this->Move_up();}
    else if(opt == DOWN){return this->Move_down();}
    else if(opt == LEFT){return this->Move_left();}
    else if(opt == RIGHT){return this->Move_right();}
}

int Board::Move_up()
{
    int score = 0;
    for(int j = 0; j < 4 ; ++j)
    {
        int now_index = 0, last_num = 0;
        for(int i = 0; i < 4; ++i)
        {
            if(last_num != 0 && table[i][j] == last_num) //same with last number
            {
                last_num = 0;
                table[now_index - 1][j] += 1;
                if(table[now_index - 1][j]==Win_base){win=true;}
                score += pow(Table_base, table[now_index - 1][j]);
            }
            else if(table[i][j] != 0)
            {
                last_num = table[i][j];
                table[now_index][j] = table[i][j];
                now_index += 1;
            }
        }
        while(now_index != 4)
        {
            table[now_index][j] = 0;
            now_index += 1;
        }
    }
    return score;
}

int Board::Move_down()
{
    int score = 0;
    for(int j = 0; j < 4 ; ++j)
    {
        int now_index = 3, last_num = 0;
        for(int i = 3; i >= 0; --i)
        {
            if(last_num != 0 && table[i][j] == last_num) //same with last number
            {
                last_num = 0;
                table[now_index + 1][j] += 1;
                if(table[now_index +1][j]==Win_base){win=true;}
                score += pow(Table_base, table[now_index + 1][j]);
            }
            else if(table[i][j] != 0)
            {
                last_num = table[i][j];
                table[now_index][j] = table[i][j];
                now_index -= 1;
            }
        }
        while(now_index >= 0)
        {
            table[now_index][j] = 0;
            now_index -= 1;
        }
    }
    return score;
}

int Board::Move_right()
{
    int score = 0;
    for(int i = 0; i < 4; ++i)
    {
        int now_index = 3, last_num = 0;
        for(int j = 3; j >= 0; --j)
        {
            if(last_num != 0 && table[i][j] == last_num) //same with last number
            {
                last_num = 0;
                table[i][now_index + 1] += 1;
                if(table[i][now_index + 1]==Win_base){win=true;}
                score += pow(Table_base, table[i][now_index + 1]);
            }
            else if(table[i][j] != 0)
            {
                last_num = table[i][j];
                table[i][now_index] = table[i][j];
                now_index -= 1;
            }
        }
        while(now_index >= 0)
        {
            table[i][now_index] = 0;
            now_index -= 1;
        }
    }
    return score;
}

int Board::Move_left()
{
    int score = 0;
    for(int i = 0; i < 4; ++i)
    {
        int now_index = 0, last_num = 0;
        for(int j = 0; j < 4 ; ++j)
        {
            if(last_num != 0 && table[i][j] == last_num) //same with last number
            {
                last_num = 0;
                table[i][now_index - 1] += 1;
                if(table[i][now_index - 1]==Win_base){win=true;}
                score += pow(Table_base, table[i][now_index - 1]);
            }
            else if(table[i][j] != 0)
            {
                last_num = table[i][j];
                table[i][now_index] = table[i][j];
                now_index += 1;
            }
        }
        while(now_index != 4)
        {
            table[i][now_index] = 0;
            now_index += 1;
        }
    }
    return score;
}

int Board::Randon_add()//0 for fail
{
    vector <int> empty_index;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(table[i][j] == 0)empty_index.push_back(4 * i + j);
        }
    }
    if(empty_index.size()==0) cout << "::";
    int index = rand() % empty_index.size();

    table[empty_index[index] / 4][empty_index[index] % 4] = (rand() % 10 == 0) ? 2 : 1;
    return empty_index.size();
}

/*void Board::Copy_choice_and_check(int new_table[][4])
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            table[i][j] = new_table[i][j];
            if(table[i][j]==Win_base){win=true;}
        }
    }
}*/
