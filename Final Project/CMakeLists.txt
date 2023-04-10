cmake_minimum_required(VERSION 3.24)
project(Final_Project)

set(CMAKE_CXX_STANDARD 17)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/black.jpg DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Tic-tac-toe.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Villa.ttf DESTINATION ${CMAKE_BINARY_DIR})
add_executable(Final_Project main.cpp tictactoe.cpp tictactoe.h AnimationMainTest.cpp)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR /home/wyatt/Documents/GitHub/SFML/lib/cmake/SFML/)
include_directories(/home/wyatt/Documents/GitHub/SFML/include/)
target_link_libraries(Final_Project sfml-system sfml-window sfml-graphics sfml-audio)


