#include <string>
#include "sudoku_matrix.hpp"

#ifndef SUDOKUCMAKE_SUDOKU_SOLVER_H
#define SUDOKUCMAKE_SUDOKU_SOLVER_H

template <unsigned int MAX_VAL = 3>
class SudokuSolver{
protected:
	Sudoku<MAX_VAL> & ss_sudoku;

public:
	SudokuSolver(Sudoku<MAX_VAL> & sudoku): ss_sudoku(sudoku) {
    }

	virtual ~SudokuSolver(){};
	virtual void solve() = 0;
};

#endif //SUDOKUCMAKE_SUDOKU_SOLVER_H