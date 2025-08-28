#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player);
bool checkTie(char *spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    srand(time(0)); // Seed random for computer moves
    drawBoard(spaces);

    while (running)
    {
        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player))
        {
            cout << "YOU WIN!\n";
            break;
        }
        else if (checkTie(spaces))
        {
            cout << "IT'S A TIE!\n";
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, computer))
        {
            cout << "COMPUTER WINS!\n";
            break;
        }
        else if (checkTie(spaces))
        {
            cout << "IT'S A TIE!\n";
            break;
        }
    }
    cout << "THANK YOU FOR PLAYING.";
    return 0;
}

void drawBoard(char *spaces)
{
    cout << " " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << '\n';
    cout << "---+---+---" << '\n';
    cout << " " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << '\n';
    cout << "---+---+---" << '\n';
    cout << " " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << '\n';
    cout << '\n';
}

void playerMove(char *spaces, char player)
{
    int number = 0;

    do
    {
        cout << "Enter a spot to place your marker (1-9): ";
        cin >> number;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            number = 0; // force loop to repeat
        }
    } while (number < 1 || number > 9 || spaces[number - 1] != ' ');

    spaces[number - 1] = player;
}

void computerMove(char *spaces, char computer)
{
    // Try to win
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            spaces[i] = computer;
            if (checkWinner(spaces, computer))
            {
                cout << "Computer chose spot " << (i + 1) << endl;
                return;
            }
            spaces[i] = ' ';
        }
    }

    // Try to block player
    char player = (computer == 'X') ? 'O' : 'X';
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            spaces[i] = player;
            if (checkWinner(spaces, player))
            {
                spaces[i] = computer;
                cout << "Computer chose spot " << (i + 1) << endl;
                return;
            }
            spaces[i] = ' ';
        }
    }

    // Otherwise, pick random
    int number = 0;
    do
    {
        number = rand() % 9;
    } while (spaces[number] != ' ');

    cout << "Computer chose spot " << (number + 1) << endl;
    spaces[number] = computer;
}

bool checkWinner(char *spaces, char player)
{
    // Horizontal wins
    if ((spaces[0] == player && spaces[1] == player && spaces[2] == player) ||
        (spaces[3] == player && spaces[4] == player && spaces[5] == player) ||
        (spaces[6] == player && spaces[7] == player && spaces[8] == player) ||

        // Vertical wins
        (spaces[0] == player && spaces[3] == player && spaces[6] == player) ||
        (spaces[1] == player && spaces[4] == player && spaces[7] == player) ||
        (spaces[2] == player && spaces[5] == player && spaces[8] == player) ||

        // Diagonal wins
        (spaces[0] == player && spaces[4] == player && spaces[8] == player) ||
        (spaces[2] == player && spaces[4] == player && spaces[6] == player))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    return true;
}