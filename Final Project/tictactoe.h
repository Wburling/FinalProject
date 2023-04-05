/*
 * Authors:
 * Jack Gauvin
 * Wyatt Burlingame
 */

#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream>
using namespace std;

const int NUM_ROWS = 3;

const int NUM_COLS = 3;

const int NUM_OF_COORD = 2;

void initializeBoard(char board[][NUM_COLS]);

void displayBoard(const char board[][NUM_COLS]);

void updateBoard(char board[][NUM_COLS], int row, int col, char playerToken);

bool isValidMove(const char board[][NUM_COLS], int row, int col);

bool isWin(const char board[][NUM_COLS],char playerToken);

bool isFull(const char board[][NUM_COLS]);

void getMove(int player, int move[], char board[][NUM_COLS]);


#endif
