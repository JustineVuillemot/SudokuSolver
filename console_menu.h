#include "sudoku_matrix.hpp"
#include <iostream>
#include "sudoku_exception.h"

#ifndef SUDOKUCMAKE_CONSOLE_MENU_H
#define SUDOKUCMAKE_CONSOLE_MENU_H

template <unsigned int MAX_VAL = 3>
class ConsoleMenu {
public:
    /*static int chooseSudokuSize(){
        std::string userInput;
        int size;

        std::cout << "Please enter the sudoku size (between 2 and 4) :" << std::endl;
        std::getline(std::cin, userInput);

        try {
            size = std::stoi(userInput);
        }catch(const std::invalid_argument &err){
            std::cerr << "you didn't enter a number !" << std::endl << "for the program to run correctly, the size will be 3" << std::endl;
            size = 3;
        }

        if(size < 2 || size > 4){
            size = 3;
        }

        return size;
    }*/

    void fillGrid(Sudoku<MAX_VAL>& s){
        bool finished = false;
        std::string userInput;
        int cellI, cellVal;

        do{
            //asking for info
            std::cout << "Please enter the cell number from 0 to " << MAX_VAL*MAX_VAL * MAX_VAL*MAX_VAL -1 << " :" << std::endl;
            std::getline(std::cin, userInput);

            try {
                cellI = std::stoi(userInput);
            }catch(const std::invalid_argument &err){
                std::cerr << "you didn't enter a number !" << std::endl << "for the program to run correctly, the cell index is set to 0" << std::endl;
                cellI = 0;
            }

            //make sure the index will work
            if(cellI < 0){
                std::cout << "you entered a number lower than 0 so the cell selected will be 0" << std::endl;
                cellI = 0;
            }

            if(cellI > 80){
                std::cout << "you entered a number higher than" << MAX_VAL*MAX_VAL * MAX_VAL*MAX_VAL -1 << "so the cell selected will be " << MAX_VAL*MAX_VAL * MAX_VAL*MAX_VAL -1 << std::endl;
                cellI = 80;
            }

            std::cout << "Please enter the cell value from 1 to " << MAX_VAL*MAX_VAL << " :" << std::endl;
            std::getline(std::cin, userInput);

            try{
                cellVal = std::stoi(userInput);
            }catch(const std::invalid_argument & err){
                std::cerr << "you didn't enter a number !" << std::endl << "for the program to run correctly, the cell value is set to 0" << std::endl;
                cellVal = 0;
            }

            //adding info
            try{
                s.addValue(cellI, cellVal);
            }
            catch(const Cell_exists & err){
                std::cerr << "The value was not entered in the sudoku, try again !" << std::endl << err.what() << std::endl;
            }
            catch(const std::out_of_range & err){
                std::cerr << "The value was not entered in the sudoku, try again !" << std::endl << err.what() << std::endl;
            }

            std::cout << s.printSudoku() << std::endl;
            std::cout << "Is your sudoku ready to be solved ? (y/n)" << std::endl;

            std::getline(std::cin, userInput);
            if(userInput == "y"){
                finished = true;
            }

        }while(!finished);
    }

    void printSudoku(Sudoku<MAX_VAL>& s){
        std::cout << s.printSudoku() << std::endl;
    }
};


#endif //SUDOKUCMAKE_CONSOLE_MENU_H
