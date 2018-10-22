#include "sudoku_solver.hpp"

#ifndef SUDOKUCMAKE_BACKTRACKING_SOLVER_H
#define SUDOKUCMAKE_BACKTRACKING_SOLVER_H

template <unsigned int MAX_VAL = 3>
class BacktrackingSolver{
private:
    Sudoku<MAX_VAL> & ss_sudoku;
public:
	BacktrackingSolver(Sudoku<MAX_VAL> & sudoku) : ss_sudoku(sudoku) {

    }

    void solve(){
        solveCell(0, 1);
    }

    int solveCell(const int indice, const int ifbacktrack){

        if(indice == (MAX_VAL*MAX_VAL)*(MAX_VAL*MAX_VAL)){
            return 1;
        }

        if(indice < (MAX_VAL*MAX_VAL)*(MAX_VAL*MAX_VAL)){
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
};

#endif //SUDOKUCMAKE_BACKTRACKING_SOLVER_H