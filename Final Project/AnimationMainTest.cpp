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
   TicTacToe Background;
    TicTacToe board("Tic-tac-toe.png");
    TicTacToe grayBox("grayBox.png", 313, 215, 0.6);
    TicTacToe grayBox2("grayBox.png", 500, 215, 0.6);
    TicTacToe grayBox3("grayBox.png", 687, 215, 0.6);
    TicTacToe grayBox4("grayBox.png", 313, 404, 0.6);
    TicTacToe grayBox5("grayBox.png", 500, 404, 0.6);
    TicTacToe grayBox6("grayBox.png", 687, 404, 0.6);
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
        window.display();
    }
}