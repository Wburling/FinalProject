#include "tictactoe.h"
#include <cstdlib>

int turnCount = 0;
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
turnCount++;
std::cout << "Pressed" << endl;
replace(&mSprite);
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
    sf:: Texture& textures = *(new sf::Texture);
    if (turnCount%2 !=0) {
        textures.loadFromFile("X.png");
        sprite->setTexture(textures);
        sprite->setOrigin(imageSize.x/2, imageSize.y/2);
        sprite->setScale(1,1);
        cout << "X" << endl;
    }
    else {
        if((!mTexture.loadFromFile("O.png"))) {
            std::cout<<"Error opening file\n";
            exit(1);
        }
        textures.loadFromFile("O.png");
        sprite->setTexture(textures);
        cout << "O" << endl;
    }

}
