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
class TicTacToe {
public:
TicTacToe() : TicTacToe("black.jpg") {}
TicTacToe(const string& fileName) {
    if (fileName == "black.jpg") {
        if (!mFont.loadFromFile("Villa.ttf"))
        {
            std::cout<<"Error opening file\n";
            exit(2);
        }
        mText.setFont(mFont);
        mText.setCharacterSize(30);
        mText.setString("Select a starting position!");
        //set origin to the middle
        mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
        //set position at the middle of the button
        mText.setPosition(500,35);
        //choose colors
        mText.setFillColor(sf::Color::White);
    }
    if (!mTexture.loadFromFile(fileName))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mSprite.setTexture(mTexture);
    //get size of image
    imageSize=mTexture.getSize();
    mSprite.setOrigin(imageSize.x/2, imageSize.y/2);
    mSprite.setScale(1,1);

}
    void draw(sf::RenderWindow* window);
private:
    sf::Sprite mSprite;
    sf::Texture mTexture;
    sf::Vector2u imageSize;
    sf::Font mFont;
    sf:: Text mText;
};
