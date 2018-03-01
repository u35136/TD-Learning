#include "AI.h"

string intMapString[] =
{
    "00", "01", "02", "03", "04", "05",
    "06", "07", "08", "09", "10"
};

int AI::Go(Board &board)
{
    //it should be a useful step
    double max_table_score = -1.0 * (numeric_limits<double>::max)(); //default DOUBLE_MIN
    Option opt;
    double temp_table_score = 0.0;
    if(this->Diff_step(UP, board, temp_table_score) && temp_table_score > max_table_score)
    {
        max_table_score = temp_table_score;
        opt = UP;
    }
    if(this->Diff_step(RIGHT, board, temp_table_score) && temp_table_score > max_table_score)
    {
        max_table_score = temp_table_score;
        opt = RIGHT;
    }
    if(this->Diff_step(DOWN, board, temp_table_score) && temp_table_score > max_table_score)
    {
        max_table_score = temp_table_score;
        opt = DOWN;
    }
    if(this->Diff_step(LEFT, board, temp_table_score) && temp_table_score > max_table_score)
    {
        max_table_score = temp_table_score;
        opt = LEFT;
    }

    BoardState temp;
    board.Copy_(temp.d2array);
    temp.round_score = board.Move(opt);

    //this->Reward(old_table, max_table_score, round_score);
    last.push_back(temp);

    return temp.round_score;
}

/*void AI::Reward(const int table[][4], double max_table_score, const int &round_score)
{
    double old_table_score = this->Table_score(table);
    double target_data = (double) (max_table_score + (double)round_score) ;
    for(int i = 0; i < mapkey.size(); ++i)
    {
        //double temp = myscore[mapkey[i]];
        myscore[mapkey[i]] = myscore[mapkey[i]] * (1 - L_rate) + (target_data / 16.0) * L_rate;
        //temp = myscore[mapkey[i]]-temp;
        //cout<<temp<<endl;
    }
}
*/
void AI::Failed(Board &board)
{
    int table[4][4];
    board.Copy_(table);
    double old_table_score = this->Table_score(table);
    double target_data = old_table_score * (-1) ;
    for(int i = 0; i < mapkey.size(); ++i)
    {
        //cout << mapkey[i]<<endl;
        myscore[mapkey[i]] = myscore[mapkey[i]] * (1 - L_rate) + (target_data / 16.0) * L_rate;
    }
    double now_update_table_score,round_score;
    for(int i=last.size()-1;i>=0;--i)
    {
        BoardState temp=last[i];
        now_update_table_score = this->Table_score(temp.d2array);
        round_score = temp.round_score;
        target_data = (double) (old_table_score + (double)round_score) ;
        for(int i = 0; i < mapkey.size(); ++i)
        {
            myscore[mapkey[i]] = myscore[mapkey[i]] * (1 - L_rate) + (target_data / 16.0) * L_rate;
        }
        old_table_score = now_update_table_score;
    }
    //cout << last.size()<<endl;
    last.clear();
    //cout << last.size()<<endl;
}

bool AI::Diff_step(const Option &opt, const Board &board, double &table_score)
{
    int temp[4][4] = {0};
    if(opt == UP)
    {
        board.Move_up(temp);
    }
    else if(opt == DOWN)
    {
        board.Move_down(temp);
    }
    else if(opt == LEFT)
    {
        board.Move_left(temp);
    }
    else if(opt == RIGHT)
    {
        board.Move_right(temp);
    }
    if(!board.Compare(temp))
    {
        return false;
    }
    else
        table_score = Table_score(temp);
    return true;
}

double AI::Table_score(const int table[][4])
{
    if(mapkey.size() != 0)
    {
        mapkey.clear();
    }
    string tempkey1, tempkey2, tempkey3, tempkey4;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            tempkey1 += intMapString[table[i][j]];
            tempkey2 += intMapString[table[j][i]];
            tempkey3 += intMapString[table[3 - i][3 - j]];
            tempkey4 += intMapString[table[3 - j][3 - i]];
        }
        mapkey.push_back(tempkey1);
        mapkey.push_back(tempkey2);
        mapkey.push_back(tempkey3);
        mapkey.push_back(tempkey4);
        tempkey1.clear();
        tempkey2.clear();
        tempkey3.clear();
        tempkey4.clear();
    }
    //return option's score
    double sum = 0.0;
    for(int i = 0; i < mapkey.size(); ++i)
    {
        sum += myscore[mapkey[i]];
    }
    return sum;
}

void AI::Save(string &filename, const int &win, const int &failed)const
{
    fstream  fp;
    filename += ".txt";
    fp.open(filename, ios::out);
    fp << win << " " << failed << endl;
    auto it = myscore.begin();
    for( ; it != myscore.end(); ++it)
        fp << it->first << " " << it->second << endl;
    fp.close();
}

void AI::Load(string &filenamem, int &win, int &failed)
{
    /*fstream  fp;
    filename += ".txt";
    fp.open(filename, ios::out);
    fp >> win >> failed;
    auto it = myscore.begin();
    for( ;it != myscore.end(); ++it)
        fp << it->first << " " << it->second << endl;
    fp.close();*/
}
