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
        window.display();
    }
}