#include "tictactoe.h"
#include <iostream>
#include <cstdlib>
int whoWon = 0;
vector<vector<int>> wins = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
int turnCount = 0;
vector<int> player1;
vector<int> player2;

void start() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Tic Tac Toe!");
    TicTacToe Background;
    TicTacToe Player1("black.jpg", 1);
    TicTacToe Player2("black.jpg", 2);
    TicTacToe PlayerCat("black.jpg",3);
    TicTacToe board("Tic-tac-toe.png");
    TicTacToe playerTurn("grayBox.png", 35,35,0.6,10);
    TicTacToe grayBox("grayBox.png", 313, 215, 0.6, 1);
    TicTacToe grayBox2("grayBox.png", 500, 215, 0.6, 2);
    TicTacToe grayBox3("grayBox.png", 687, 215, 0.6, 3);
    TicTacToe grayBox4("grayBox.png", 313, 404, 0.6,4);
    TicTacToe grayBox5("grayBox.png", 500, 404, 0.6,5);
    TicTacToe grayBox6("grayBox.png", 687, 404, 0.6,6);
    TicTacToe grayBox7("grayBox.png", 313, 593, 0.6,7);
    TicTacToe grayBox8("grayBox.png", 500, 593, 0.6,8);
    TicTacToe grayBox9("grayBox.png", 687, 593, 0.6,9);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            //board.update(event, window); do the gray squares...
            grayBox.update(event,window);
            grayBox2.update(event,window);
            grayBox3.update(event,window);
            grayBox4.update(event,window);
            grayBox5.update(event,window);
            grayBox6.update(event,window);
            grayBox7.update(event,window);
            grayBox8.update(event,window);
            grayBox9.update(event,window);
        }
        window.clear();
        Background.draw(&window);
        board.draw(&window);
        grayBox.draw(&window);
        grayBox2.draw(&window);
        grayBox3.draw(&window);
        grayBox4.draw(&window);
        grayBox5.draw(&window);
        grayBox6.draw(&window);
        grayBox7.draw(&window);
        grayBox8.draw(&window);
        grayBox9.draw(&window);
        if(whoWon == 1) {
            Player1.draw(&window);
        }
        if(whoWon == 2) {
            Player2.draw(&window);
        }
        if(whoWon == 3) {
            PlayerCat.draw(&window);
        }

        window.display();
    }
}
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
    sf::Texture &textureWin = *(new sf::Texture);
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
    int cat = 0;
    if(turnCount == 9) {
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
                    whoWon = 1;
                    break;
                }
            }
        }
        if(whoWon == 0) {
            cat++;
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
                    whoWon = 2;
                    break;
                }
            }
        }
        if(whoWon == 0) {
            cat++;
        }
    }
    else {
        int checker1 = 0;
        int checker2 = 0;
        for (int i = 0; i < 8; i++) {
            checker1 = 0;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < player1.size(); k++) {
                    if (wins[i][j] == player1[k]) {
                        checker1++;
                    }
                }
                if (checker1 == 3) {
                    cout << "Player 1 wins" << endl;
                    whoWon = 1;

                }
            }
        }
        for (int i = 0; i < 8; i++) {
            checker2 = 0;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < player2.size(); k++) {
                    if (wins[i][j] == player2[k]) {
                        checker2++;
                    }

                }
                if (checker2 == 3) {
                    cout << "Player 2 wins" << endl;
                    whoWon = 2;
                }
            }
        }
    }

    cout << whoWon << " is whoWon" << endl;
    cout << cat << endl;
    if(cat >=2) {
        whoWon = 3;
    }

}
