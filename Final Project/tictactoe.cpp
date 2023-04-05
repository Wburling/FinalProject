#include "tictactoe.h"

// Jack's code: board functions

void initializeBoard(char board[][NUM_COLS])
{
    for (int i = 0; i < NUM_ROWS; i++) // Go through each row
    {
        for (int j = 0; j < NUM_COLS; j++) // Go through each element in the row
        {
            board[i][j] = '*';
        }
    }
}

void displayBoard(const char board[][NUM_COLS])
{
    system("clear");

    cout << "    1    2    3\n\n";

    for (int i = 0; i < NUM_ROWS; i++) // Go through each row
    {
        cout << i + 1 << "   ";

        for (int j = 0; j < NUM_COLS; j++) // Go through each element in the row
        {
            cout << board[i][j] << "    ";
        }
        cout << endl;
        cout << endl;
    }
}

void getMove(int player, int move[], char board[][NUM_COLS])
{
    // displayBoard(board);
    cout << "Player " << player << ":" << endl;
    do
    {
        cout << "Enter a row, column: ";
        cin >> move[0] >> move[1];
    } while (!isValidMove(board, move[0], move[1]));
}

void updateBoard(char board[][NUM_COLS], int row, int col, char playerToken)
{
    board[row][col] = playerToken;
}

// Wyatt's code: testing functions (is..etc)

bool isValidMove(const char board[][NUM_COLS], int row, int col)
{
    // displayBoard(board);
    if (row < 1 || row > 3)
    {
        cout << "\nInvalid move: value must be between 1 and 3." << endl;
        return false;
    }
    if (col < 1 || col > 3)
    {
        cout << "\nInvalid move: value must be between 1 and 3." << endl;
        return false;
    }
    if (board[row - 1][col - 1] != '*')
    {
        cout << "That place is taken!" << endl;
        return false;
    }

    return true;
}

bool isWin(const char board[][NUM_COLS], char playerToken)
{
    for (int i = 0; i < NUM_ROWS; i++)
    {
        if (board[i][0] == playerToken && board[i][1] == playerToken && board[i][2] == playerToken)
        {
            return true;
        }
    }
    for (int i = 0; i < NUM_ROWS; i++)
    {
        if (board[0][i] == playerToken && board[1][i] == playerToken && board[2][i] == playerToken)
        {
            return true;
        }
    }
    if (board[0][0] == playerToken && board[1][1] == playerToken && board[2][2] == playerToken)
    {
        return true;
    }
    if (board[0][2] == playerToken && board[1][1] == playerToken && board[2][0] == playerToken)
    {
        return true;
    }
    return false;
}

bool isFull(const char board[][NUM_COLS])
{
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            if (board[i][j] == '*')
            {
                return false;
            }
        }
    }
    return true;
}