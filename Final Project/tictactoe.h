/*
 * Authors:
 * Jack Gauvin
 * Wyatt Burlingame
 */
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
//Tic Tac Toe basics
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
// Class for GUI
class TicTacToe: public sf::Drawable {
public:
TicTacToe() {
    if (!mTexture.loadFromFile("black.jpg"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mSprite.setTexture(mTexture);
    //get size of image
    sf::Vector2u imageSize=mTexture.getSize();
    draw(mSprite,)
}
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
private:
    sf::Sprite mSprite;
    sf::Texture mTexture;
};
