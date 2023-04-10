//
// Created by wyatt on 4/9/23.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "tictactoe.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Tic Tac Toe!");
   // TicTacToe Background;
    TicTacToe board("Tic-tac-toe.png");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
       // Background.draw(&window);
        board.draw(&window);
        window.display();
    }
}