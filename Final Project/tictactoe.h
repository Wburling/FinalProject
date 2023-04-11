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
        mText.setString("Place among the Gray Squares!");
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
    void draw(sf::RenderWindow* window);
    void update(sf::Event& e, sf::RenderWindow& window);
    void replace(sf::Sprite* sprite);
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


