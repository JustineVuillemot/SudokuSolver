# SudokuSolver

## What is it ?

This project is a C++ terminal soduko solver. The programm first asks you to enter your base sudoku grid and then it calculates the (or one if many exists) solution. There are no graphic interface available.

## Why do this project ?

It was a project realised during a C++ course at IMAC engineering school in Paris.

## How to test it ?

### With a Linux environment

The project was coded with the CLion compiler on Windows so the project wasn't created with a `Makefile`. So you can use a compiler or code your own `Makefile` and then test it.

### With a windows environment

Like I said in the previous section, the project was coded on CLion. If you have the compiler installed on your computer I would recommend you to open the project with it. However I didn't put any CLion settings file on this repop so that you can still launch it with another compiler like Visual Studio or Code::Blocks.

## More info on the project

The algorithm used to solve the sudoku puzzles is the most basic one : brute force. That's why, if multiple solutions exists, the programm will give the first one it calculates (smaller numbers tends to find themselves at the top left corner of the sudoku).

However the architecture of the project is thought in a way where someone could easily inherit the Class `SudokuSolver` and code his/her own solving algorithm and the programm would still work.

The same thing can be applied for the interface. The architecture was conceived in a way where one could replace the existing interface Class in the main.cpp file and the programm would still work.
