#include "tictactoe.h"

void TicTacToe::draw(sf::RenderWindow *window) {
    std::cout << "Drawn" << std::endl;
    window->draw(mSprite);
    window->draw(mText);
    mSprite.setOrigin(imageSize.x/2, imageSize.y/2);
    mSprite.setPosition(window->getSize().x/2, window->getSize().y/2);
}
