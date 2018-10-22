#include <stdexcept>
#include "backtracking_solver.hpp"

BacktrackingSolver::BacktrackingSolver(Sudoku & sudoku) : SudokuSolver(sudoku) {

}

void BacktrackingSolver::solve(){
    solveCell(0, 1);
}

/*backtrack should only be 1 or -1
it helps go throught clues in the right way*/
int BacktrackingSolver::solveCell(const int indice, const int ifbacktrack){

	if(indice == 81){
		return 1;
	}

	if(indice < 81){
		if(ss_sudoku.isClue(indice)){
			//si la cellule est un indice, il ne faut pas la changer
            return solveCell(indice+(1*ifbacktrack), ifbacktrack);
		}

		while(!ss_sudoku.checkCell(indice, ss_sudoku.getValue(indice)+1)){
			try{
				ss_sudoku.incrementCell(indice);
			}
			catch(const std::out_of_range & err){
                return solveCell(indice-1, -1);
			}
		}

		try{
			ss_sudoku.incrementCell(indice);
		}
		catch(const std::out_of_range & err){
            return solveCell(indice-1, -1);
		}
		return solveCell(indice+1, +1);

	}

}
