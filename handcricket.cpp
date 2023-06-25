#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int GetPlayerToss(char player1[], char player2[], int oversToplay);
int batting(char battingplayer[], char bowlingplayer[], int oversToplay);

int main()
{
    int i, j, overs, noovers, player1Toss, player2Toss;
    char player1[50], player2[50];
    srand(time(NULL));

    cout << "-----------------------------------WELCOME TO HAND CRICKET GAME-------------------------------------" << endl;
    cout << "Enter Player 1 Name: ";
    cin.getline(player1, 50);
    cout << "Enter Player 2 Name: ";
    cin.getline(player2, 50);
    cout << "Enter\n1 - Fixed Overs\n2 - Play Until Out\n3 - How to Play?\n4 - Exit: ";
    cin >> noovers;

    do
    {
        if (noovers == 1)
        {
            cout << "Enter No Of Overs: ";
            cin >> overs;
            player1Toss = GetPlayerToss(player1, player2, overs);
        }
        else if (noovers == 2)
        {
            player1Toss = GetPlayerToss(player1, player2, 0);
        }
        else if (noovers == 3)
        {
            cout << "How To Play?" << endl;
            cout << "Until a player has won the toss, follow the output and provide the required input." << endl;
            cout << "The player who wins the toss chooses whether to bat or bowl." << endl;
            cout << "The player who chose batting and bowling will proceed by pressing the Enter key one by one." << endl;
            cout << "The system will generate a random number as runs for both players." << endl;
            cout << "Player 1's runs will keep adding until their runs equal Player 2's runs." << endl;
            cout << "Finally, when Player 1 is out, their score becomes their final score." << endl;
            cout << "The same process will be conducted for Player 2." << endl;
            cout << "Finally, whoever has the highest score is the winner." << endl << endl;
            cout << "For example: Player 1 won the toss and chose batting." << endl;
            cout << "When Player 1 presses the Enter key, a score will be generated for Player 1." << endl;
            cout << "Suppose the runs are 5, so Player 1's score is 5." << endl;
            cout << "Then Player 2 also presses the Enter key." << endl;
            cout << "If Player 2 gets a score of 4, Player 2's score is 4." << endl;
            cout << "Since Player 1's score is not equal to Player 2's score, Player 1 is not out, and their score will be 5 after the first ball." << endl;
            cout << "In the second ball, Player 1 gets 3 runs and Player 2 gets 4 runs." << endl;
            cout << "Since again both scores are not equal, Player 1's score becomes 5 + 3 = 8." << endl;
            cout << "If in the third ball, Player 1 gets 4 runs and Player 2 also gets 4 runs, Player 1's score is equal to Player 2's score, and Player 1 is out." << endl;
            cout << "Then the final score of Player 1 is 8 runs." << endl;
            cout << "The same process is repeated for Player 2. Finally, the player with the higher score wins." << endl;
        }
        else
        {
            cout << "--------------------------------------------Invalid Choice--------------------------------------------" << endl;
        }

        cout << "Enter 1 - Fixed Overs\n2 - Play Until Out\n3 - How to Play?\n4 - Exit: ";
        cin >> noovers;

    } while (noovers >= 1 && noovers <= 3);

    return 0;
}

int GetPlayerToss(char player1[], char player2[], int oversToplay)
{
    int player1Choice, player2Choice, toss, player1Toss, batorbowlChoice, player2Score, player1Score;
    cout << player1 << " Choose your choice: 1 for head or 2 for tail: ";
    cin >> player1Choice;

    if (player1Choice == 1)
    {
        player2Choice = 2;
        cout << player2 << "'s choice is Tail" << endl;
    }
    else if (player1Choice == 2)
    {
        player2Choice = 1;
        cout << player2 << "'s choice is Head" << endl;
    }
    else
    {
        cout << "--------------------------------------------Invalid Choice--------------------------------------------" << endl;
        return 0;
    }

    toss = rand() % 2;
    toss = toss + 1;

    if (toss == 1)
        cout << "Toss is Head" << endl;
    else
        cout << "Toss is Tail" << endl;

    if (toss == player1Choice)
    {
        player1Toss = 1;
        cout << "Player 1 " << player1 << " won the toss" << endl;
        cout << "Choose\n1 - Batting\n2 - Bowl: ";
        cin >> batorbowlChoice;

        if (batorbowlChoice == 1)
        {
            cout << "-----------------" << player1 << " is going to bat now-----------------------" << endl;
            player1Score = batting(player1, player2, oversToplay);
            cout << "-----------------" << player2 << " is going to bat now-----------------------" << endl;
            player2Score = batting(player2, player1, oversToplay);
            cout << "-----------------It's time for the results-----------------------" << endl;
        }
        else
        {
            cout << "-----------------" << player2 << " is going to bat now-----------------------" << endl;
            player2Score = batting(player2, player1, oversToplay);
            cout << "-----------------" << player1 << " is going to bat now-----------------------" << endl;
            player1Score = batting(player1, player2, oversToplay);
            cout << "-----------------It's time for the results-----------------------" << endl;
        }
    }
    else if (toss == player2Choice)
    {
        player1Toss = 2;
        cout << "Player 2 " << player2 << " won the toss" << endl;
        cout << "Choose\n1 - Batting\n2 - Bowl: ";
        cin >> batorbowlChoice;

        if (batorbowlChoice == 1)
        {
            cout << "-----------------" << player2 << " is going to bat now-----------------------" << endl;
            player2Score = batting(player2, player1, oversToplay);
            cout << "-----------------" << player1 << " is going to bat now-----------------------" << endl;
            player1Score = batting(player1, player2, oversToplay);
            cout << "-----------------It's time for the results-----------------------" << endl;
        }
        else
        {
            cout << "-----------------" << player1 << " is going to bat now-----------------------" << endl;
            player1Score = batting(player1, player2, oversToplay);
            cout << "-----------------" << player2 << " is going to bat now-----------------------" << endl;
            player2Score = batting(player2, player1, oversToplay);
            cout << "-----------------It's time for the results-----------------------" << endl;
        }
    }
    else
    {
        cout << "------------------------------------------------Error-------------------------------------------------" << endl;
        return 0;
    }

    if (player1Score == player2Score)
    {
        cout << "Draw Match" << endl;
        cout << "Thanks for playing the game" << endl;
    }
    if (player1Score > player2Score)
        cout << player1 << " won the match" << endl << "Thanks for playing the game" << endl;
    if (player1Score < player2Score)
        cout << player2 << " won the match" << endl << "Thanks for playing the game" << endl;

    return player1Toss;
}

int batting(char battingplayer[], char bowlingplayer[], int oversToplay)
{
    int i, j, battingScore, sum = 0, bowlerScore, flag = 1;
    char c;

    if (oversToplay > 0)
    {
        for (i = 1; i <= oversToplay; i++)
        {
            for (j = 1; j <= 6; j++)
            {
                cout << i << "." << j << " ball" << endl;
                cout << bowlingplayer << " Press Enter key to bowl: ";
                cin.ignore();
                cin.get(c);
                bowlerScore = rand() % 7; // Generate from 0-6 where 0 means no ball
                cout << battingplayer << " Press Enter key to bat: ";
                cin.ignore();
                cin.get(c);
                battingScore = rand() % 7; // Generate 0-6 runs

                if (battingScore == bowlerScore)
                {
                    flag = 0;
                    cout << "-----------------" << battingplayer << " is Out----------------" << endl;
                    cout << battingplayer << " Total Score = " << sum << endl;

                    if (sum == 0)
                        cout << "-----------Hehehe Duck Out-----------------" << endl;

                    break;
                }
                else
                {
                    cout << "Got " << battingScore << " runs" << endl;

                    if (battingScore == 6)
                        cout << "Sixerrrrrr Keep it Up" << endl;
                    if (battingScore == 4)
                        cout << "It's a Four Great Man" << endl;

                    sum += battingScore;
                    cout << battingplayer << " Score = " << sum << endl;
                }
            }

            if (flag == 0)
                break;
        }

        return sum;
    }
    else if (oversToplay == 0)
    {
        while (flag)
        {
            cout << bowlingplayer << " Press Enter key to bowl: ";
            cin.ignore();
            cin.get(c);
            bowlerScore = rand() % 7; // Generate from 0-6 where 0 means no ball
            cout << battingplayer << " Press Enter key to bat: ";
            cin.ignore();
            cin.get(c);
            battingScore = rand() % 7; // Generate 0-6 runs

            if (battingScore == bowlerScore)
            {
                flag = 0;
                cout << "-----------------" << battingplayer << " is Out----------------" << endl;
                cout << battingplayer << " Total Score = " << sum << endl;

                if (sum == 0)
                    cout << "-----------Hehehe Duck Out-----------------" << endl;

                break;
            }
            else
            {
                cout << "Got " << battingScore << " runs" << endl;

                if (battingScore == 6)
                    cout << "Sixerrrrrr Keep it Up" << endl;
                if (battingScore == 4)
                    cout << "It's a Four Great Man" << endl;

                sum += battingScore;
                cout << battingplayer << " Score = " << sum << endl;
            }
        }

        return sum;
    }

    return 0;
}
