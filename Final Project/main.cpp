/*
 * Authors:
 * Jack Gauvin
 * Wyatt Burlingame
 * */

#include "tictactoe.h"
#include <iostream>
using namespace std;



int main()
{
    //Jacks Work
    const int NUM_PLAYERS = 2;

    const char PLAYER_TOKEN[NUM_PLAYERS] = {'X', 'O'};

    char board[NUM_ROWS][NUM_COLS];

    initializeBoard(board);

    displayBoard(board);

    int coord[NUM_OF_COORD];

        while(1)
        {
            getMove(1, coord, board);
            updateBoard(board, coord[0] - 1, coord[1] - 1, PLAYER_TOKEN[0]);
            displayBoard(board);

            //Wyatt's Work
            if (isWin(board, PLAYER_TOKEN[0]))
            {
                cout << "Player 1 wins!" << endl;
                return 0;
            } else if (isFull(board)) {
                cout << "It's a tie!" << endl;
                return 0;
            }
            getMove(2, coord, board);
            updateBoard(board, coord[0] - 1, coord[1] - 1, PLAYER_TOKEN[1]);
            displayBoard(board);
            if (isWin(board, PLAYER_TOKEN[1]))
            {
                cout << "Player 2 wins!" << endl;
                return 0;
            } else if (isFull(board)) {
                cout << "It's a tie!" << endl;
                return 0;
            }

        }

    return 0;
}
