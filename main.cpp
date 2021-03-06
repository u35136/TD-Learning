#include <bits/stdc++.h>
#include <conio.h>
#include <time.h>

#include "board.h"
#include "AI.h"

using namespace std;

int main()
{
    srand(time(0));

    int table[4][4] = {{0}};
    Board board;
    board.New();
    board.Copy_(table);

    int round = 10000, score = 0, round_score = 0;

    fstream  file;
    file.open("output.txt", ios::out);


    cout << "For AI" << endl << "Round >> 10000" << endl;
    //cin >> round;

    AI myai;
    int win = 0, failed = 0,round_win = 0,round_failed = 0;
    long long int avg_sum = 0, avg_round = 0,avg_max=0;
    string str = "test";
    myai.Load(str, win, failed);
    while(round)
    {
        board.Copy_(table);
        //cout << "Your score: " << score << endl;
        //board.Show();

        round_score = myai.Go(board);

        score += round_score;
        /*if(board.Win())
        {
            board.Show();
            win++;
            round--;
            cout << "Win"<<endl;
            board.New();
            score=0;
        }*/
        if(board.Compare(table) && board.Randon_add() == 1 && board.Failed())
        {
            if(round %100==0)
            {
                cout <<"! "<<round_win <<" "<<round_failed <<" ";
                round_win=0;
                round_failed=0;
            }
            if(board.Win())
            {
                //cout << "W";
                round_win++;
                win++;
                failed--;
                round_failed--;
            }
            round_failed++;
            failed++;
            round--;
            avg_sum += score;
            avg_round += 1;
            if(score>avg_max) avg_max=score;
            //board.Show();
            myai.Failed(board);
            score = 0;
            if(avg_round == 1000)
            {
                cout << avg_sum / avg_round <<" "<<avg_max<< endl;
                file << avg_sum / avg_round <<" "<<avg_max<< endl;
                avg_sum = 0;
                avg_round = 0;
                avg_max=0;
                //system("pause");
            }
            /*if(round == 40000)
            {
                str="test_40000";
                myai.Save(str, win, failed);
            }*/
            board.New();
            //system("pause");
        }
        //system("pause");
    }
    str.clear();
    str="test";
    myai.Save(str, win, failed);
    file.close();
    /*//keyboard
    int c, k = 1;
    while(k != 0)
    {
        if(board.Win())
        {
            board.Show();
            cout << "Win"<<endl;
            break;
        }
        if(board.Compare(table) && board.Randon_add()==1 && board.Failed())
        {
            board.Show();
            cout << "Failed"<<endl;
            break;
        }
        board.Copy_(table);
        cout << "Your score: " << score << endl;
        board.Show();

        c = getch();
        if(c == 224)
        {
            c = getch();
            switch(c)
            {
            case 72://up
                cout << "Up" << endl;
                round_score = board.Move_up();
                break;
            case 80:
                cout << "Down" << endl; //down
                round_score = board.Move_down();
                break;
            case 75:
                cout << "Left" << endl;
                round_score = board.Move_left(); //left
                break;
            case 77:
                cout << "Right" << endl; //right
                round_score = board.Move_right();
                break;
            default:
                break;
            }
        }
        score += round_score;
        if(c == 0x0D)
        {
            k = 0;
        }
    }*/

}
