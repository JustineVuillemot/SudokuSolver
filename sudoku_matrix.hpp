#include "sudoku_exception.h"
#include "cell.hpp"

#ifndef SUDOKUCMAKE_SUDOKU_MATRIX_H
#define SUDOKUCMAKE_SUDOKU_MATRIX_H

template <unsigned int MAX_VAL = 3>
class Sudoku{
private:
	Cell<MAX_VAL> s_grille[MAX_VAL*MAX_VAL][MAX_VAL*MAX_VAL];

public:
	bool checkCell(const int indice, const int val) const{
        return checkLine(indice, val) && checkCol(indice, val) && checkBlock(indice, val);
    }

	bool checkLine(const int indice, const int val) const{
        Cell<MAX_VAL> temp;
        temp.setValue(val);

        int line = indice / (MAX_VAL*MAX_VAL);

        for(int i = 0; i < (MAX_VAL*MAX_VAL); i++){
            if(s_grille[line][i] == temp){
                return 0;
            }
        }

        return 1;

    }

	bool checkCol(const int indice, const int val) const{
        Cell<MAX_VAL> temp;
        temp.setValue(val);

        int col = indice % (MAX_VAL*MAX_VAL);

        for(int i = 0; i < (MAX_VAL*MAX_VAL); i++){
            if(s_grille[i][col] == temp){
                return 0;
            }
        }

        return 1;

    }

	bool checkBlock(const int indice, const int val) const{
        Cell<MAX_VAL> temp;
        temp.setValue(val);

        int col = indice % (MAX_VAL*MAX_VAL) / MAX_VAL;
        int line = indice / (MAX_VAL*MAX_VAL) / MAX_VAL;

        for(int i = line*MAX_VAL; i < (line+1)*MAX_VAL; i++){
            for(int j = col*MAX_VAL; j < (col+1)*MAX_VAL; j++){
                if(s_grille[i][j] == temp){
                    return 0;
                }
            }
        }

        return 1;
    }

    /*this function only delivers the cell incremenation error*/
	void incrementCell(const int indice){

        int line = indice / (MAX_VAL*MAX_VAL);
        int col = indice % (MAX_VAL*MAX_VAL);

        try{
            s_grille[line][col]++;
        }
        catch(const std::out_of_range & err){
            throw std::out_of_range("9 reached, backtracking needed !");
        }
    }

	void addValue(const int indice, const int val){

        if(val < 1 || val > (MAX_VAL*MAX_VAL)){
            throw std::out_of_range("the value entered is not correct (not between 1 and 9)");
        }

        if(!checkCell(indice, val)){
            throw Cell_exists("the value entered already exists in the block, column or line");
        }

        int line = indice / (MAX_VAL*MAX_VAL);
        int col = indice % (MAX_VAL*MAX_VAL);

        s_grille[line][col].setValue(val);
        s_grille[line][col].setClue(true);
    }

	std::string printSudoku(){
        std::string sudoku_str;

        for(int i=0; i<(MAX_VAL*MAX_VAL); i++){

            //put a horizontal line between blocks
            if(i%MAX_VAL == 0){
                sudoku_str += "\n";
            }

            for(int j=0; j<(MAX_VAL*MAX_VAL); j++){
                sudoku_str += std::to_string(s_grille[i][j].getValue());

                //mark the clues
                if(s_grille[i][j].isClue()){
                    sudoku_str += "*";
                }else{
                    sudoku_str += " ";
                }

                sudoku_str += " ";

                //create a vertical line between blocks
                if(j%MAX_VAL == MAX_VAL-1 && j != (MAX_VAL*MAX_VAL)-1){
                    sudoku_str += " ";
                }
            }

            sudoku_str += "\n";
        }

        return sudoku_str;
    }

    /*function to give back info about a cell*/
	int getValue(const int indice) const{
        int line = indice / (MAX_VAL*MAX_VAL);
        int col = indice % (MAX_VAL*MAX_VAL);

        return s_grille[line][col].getValue();
    }

	bool isClue(const int indice) const{
        int line = indice / (MAX_VAL*MAX_VAL);
        int col = indice % (MAX_VAL*MAX_VAL);

        return s_grille[line][col].isClue();
    }
};

#endif //SUDOKUCMAKE_SUDOKU_MATRIX_H