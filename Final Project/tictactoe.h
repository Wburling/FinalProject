/*
 * Authors:
 * Jack Gauvin
 * Wyatt Burlingame
 */
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
using namespace std;

// Class for GUI

class TicTacToe {
public:
    //Background Constructor
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
        mText.setString("Click the Gray Squares!");
        //set origin to the middle
        mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
        //set position at the middle of the button
        mText.setPosition(500,35);
        //choose colors
        mText.setFillColor(sf::Color::Black);
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
    mSprite.setPosition(500, 400);
}
//Gray spaces constructor
TicTacToe(const string& fileName, float x, float y, float scaleSquare, int id) {
    identity = id;
    if (!mTexture.loadFromFile(fileName))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mSprite.setTexture(mTexture);
    //get size of image
    imageSize=mTexture.getSize();
    mSprite.setOrigin(imageSize.x/2, imageSize.y/2);
    mSprite.setScale(scaleSquare,scaleSquare);
    mSprite.setPosition(x,y);
}
// Winning Screen Constructor
    TicTacToe(const string& fileName, int i) {
    mTexture.loadFromFile(fileName);
    mSprite.setTexture(mTexture);
    mFont.loadFromFile("Villa.ttf");
    mText.setFont(mFont);
    mText.setCharacterSize(30);
    string word;
    if (i != 3)
    word = "Player " + to_string(i) + " Won!!!";
    else
        word = "Cat Scratch!!!";
    mText.setString(word);
        mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
        mText.setPosition(500,400);
        mText.setFillColor(sf::Color::Black);

}
//Display Player Turn Constructor
TicTacToe(const string& fileName, int count, int player ) {

    mTexture.loadFromFile(fileName);
    mSprite.setTexture(mTexture);
    mFont.loadFromFile("Villa.ttf");
    mText.setFont(mFont);
    mText.setCharacterSize(30);
    if (fileName == "grayBox.png") {
        mSprite.scale(0,0);
        mText.setString("Press this text to Replay");
        mText.setOrigin(mText.getGlobalBounds().width / 2, mText.getGlobalBounds().height / 2);
        mText.setPosition(500,600);
        mText.setFillColor(sf::Color::Black);
    }
    else {
        string word;
        word = "Player " + to_string(player);
        if (player == 1)
            word = word + " \"X\":";
        if (player == 2)
            word = word + " \"O\":";
        mText.setString(word);
        mText.setOrigin(mText.getGlobalBounds().width / 2, mText.getGlobalBounds().height / 2);
        mText.setPosition(120, 725);
        mText.setFillColor(sf::Color::Black);
    }
}
    //Drawing the image to the window
    void draw(sf::RenderWindow* window);
    //Updating live for choosing a space
    void update(sf::Event& e, sf::RenderWindow& window);
    //Replacing the gray space with an x or o
    void replace(sf::Sprite* sprite);
    //Checking if the player won or had a tie.
    void CheckWin();
private:
    sf::Sprite mSprite;
    sf::Texture mTexture;
    sf::Vector2u imageSize;
    sf::Font mFont;
    sf:: Text mText;
    bool alreadyPassed = false;
    int identity;
};
void start();


