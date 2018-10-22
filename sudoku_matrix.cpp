#include <stdexcept>
#include <string>
#include "sudoku_matrix.hpp"
#include "sudoku_exception.h"

bool Sudoku::checkCell(const int indice, const int val) const{
	return checkLine(indice, val) && checkCol(indice, val) && checkBlock(indice, val);
}

/*return 1 if no cell of value 'val'
return 0 if a cell with value 'val' exists*/
bool Sudoku::checkLine(const int indice, const int val) const{
	Cell temp;
	temp.setValue(val);

	int line = indice / 9;

	for(int i = 0; i < 9; i++){
		if(s_grille[line][i] == temp){
			return 0;
		}
	}

	return 1;

}

/*return 1 if no cell of value 'val'
return 0 if a cell with value 'val' exists*/
bool Sudoku::checkCol(const int indice, const int val) const{
	Cell temp;
	temp.setValue(val);

	int col = indice % 9;

	for(int i = 0; i < 9; i++){
		if(s_grille[i][col] == temp){
			return 0;
		}
	}

	return 1;

}

/*return 1 if no cell of value 'val'
return 0 if a cell with value 'val' exists*/
bool Sudoku::checkBlock(const int indice, const int val) const{
	Cell temp;
	temp.setValue(val);

	int col = indice % 9 / 3;
	int line = indice / 9 / 3;

	for(int i = line*3; i < (line+1)*3; i++){
		for(int j = col*3; j < (col+1)*3; j++){
			if(s_grille[i][j] == temp){
				return 0;
			}
		}
	}

	return 1;
}

/*this function only delivers the cell incremenation error*/
void Sudoku::incrementCell(const int indice){

	int line = indice / 9;
	int col = indice % 9;

	try{
		s_grille[line][col]++;
	}
	catch(const std::out_of_range & err){
		throw std::out_of_range("9 reached, backtracking needed !");
	}
}

void Sudoku::addValue(const int indice, const int val){

	if(val < 1 || val > 9){
		throw std::out_of_range("the value entered is not correct (not between 1 and 9)");
	}

	if(!checkCell(indice, val)){
		throw Cell_exists("the value entered already exists in the block, column or line");
	}

	int line = indice / 9;
	int col = indice % 9;

	s_grille[line][col].setValue(val);
	s_grille[line][col].setClue(true);
}

std::string Sudoku::printSudoku(){
    std::string sudoku_str;

    for(int i=0; i<9; i++){

        //put a horizontal line between blocks
        if(i%3 == 0){
            sudoku_str += "\n";
        }

        for(int j=0; j<9; j++){
            sudoku_str += std::to_string(s_grille[i][j].getValue());

            //mark the clues
            if(s_grille[i][j].isClue()){
                sudoku_str += "*";
            }else{
                sudoku_str += " ";
            }

            sudoku_str += " ";

            //create a vertical line between blocks
            if(j%3 == 2 && j != 8){
                sudoku_str += " ";
            }
        }

        sudoku_str += "\n";
    }

    return sudoku_str;
}

/*function to give back info about a cell*/

int Sudoku::getValue(const int indice) const{
	int line = indice / 9;
	int col = indice % 9;

	return s_grille[line][col].getValue();
}

bool Sudoku::isClue(const int indice) const{
	int line = indice / 9;
	int col = indice % 9;

	return s_grille[line][col].isClue();
}