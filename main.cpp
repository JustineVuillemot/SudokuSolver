#include "console_menu.h"
#include "backtracking_solver.hpp"

int main(int argc, char const *argv[])
{

    ConsoleMenu<3> menu;
    Sudoku<3> s;

    menu.fillGrid(s);

    BacktrackingSolver<3> solver(s);

    solver.solve();

    menu.printSudoku(s);

    return 0;
}
