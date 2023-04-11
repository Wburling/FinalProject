#include "tictactoe.h"
#include <iostream>
#include <cstdlib>

vector<vector<int>> wins = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
int turnCount = 0;
vector<int> player1;
vector<int> player2;
void TicTacToe::draw(sf::RenderWindow *window) {
    window->draw(mSprite);
    window->draw(mText);
    mSprite.setOrigin(imageSize.x/2, imageSize.y/2);
}
void TicTacToe::update(sf::Event& e, sf::RenderWindow& window){
// get position of the mouse
sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

bool mouseInButton =    mousePosition.x >= mSprite.getPosition().x - mSprite.getGlobalBounds().width/2
                        && mousePosition.x <= mSprite.getPosition().x + mSprite.getGlobalBounds().width/2
                        && mousePosition.y >= mSprite.getPosition().y - mSprite.getGlobalBounds().height/2
                        && mousePosition.y <= mSprite.getPosition().y + mSprite.getGlobalBounds().height/2;
if(e.type == sf::Event::MouseMoved)
{
if(mouseInButton)
{
mSprite.setColor(sf::Color::Blue);
}
else
{
mSprite.setColor(sf::Color::White);
}
}
if (e.type == sf::Event::MouseButtonPressed)
{
if(e.mouseButton.button==sf::Mouse::Left)
{
if(mouseInButton)
{
//mSprite.setScale(0,0);
std::cout << "Pressed" << endl;
replace(&mSprite);
alreadyPassed = true;
}
else
{
mSprite.setRotation(0);

}
}
}
if (e.type == sf::Event::MouseButtonReleased)
{
if (e.mouseButton.button==sf::Mouse::Left)
{
if(mouseInButton)
{
mSprite.setColor(sf::Color::Blue);
mSprite.setRotation(0);
}
else
{
mSprite.setColor(sf::Color::White);
mSprite.setRotation(0);
}
}
}
}
void TicTacToe::replace(sf::Sprite* sprite) {
        sf::Texture &textures = *(new sf::Texture);
        if (alreadyPassed != true) {
            turnCount++;
            if (turnCount % 2 != 0) {
                textures.loadFromFile("X.png");
                sprite->setTexture(textures);
                sprite->setOrigin(imageSize.x / 2, imageSize.y / 2);
                sprite->setColor(sf::Color::White);
                player1.push_back(identity);
                TicTacToe::CheckWin();
                cout << "X" << endl;
            } else {
                textures.loadFromFile("O.png");
                sprite->setTexture(textures);
                sprite->setOrigin(imageSize.x / 2, imageSize.y / 2);
                mSprite.setColor(sf::Color::White);
                player2.push_back(identity);
                TicTacToe::CheckWin();
                cout << "O" << endl;
            }
        }

}
void TicTacToe::CheckWin() {
    int checker1 =0;
    int checker2 =0;
    for (int i = 0; i < 8; i++) {
        checker1 =0;
        for(int j = 0; j < 3; j++) {
            for (int k = 0; k < player1.size(); k++) {
                if(wins[i][j] == player1[k]) {
                    checker1++;
                }
            }
            if (checker1 ==3) {
                cout << "Player 1 wins" << endl;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        checker2=0;
        for(int j = 0; j < 3; j++) {
            for (int k = 0; k < player2.size(); k++) {
                if(wins[i][j] == player2[k]) {
                    checker2++;
                }

            }
            if (checker2 == 3) {
                cout << "Player 2 wins" << endl;
            }
        }
    }


}
