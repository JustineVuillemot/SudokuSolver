#include <stdexcept>

#ifndef SUDOKUCMAKE_CELL_H
#define SUDOKUCMAKE_CELL_H

template <unsigned int MAX_VAL = 3>
class Cell{
private:
	bool c_clue;
	int c_value;

public:
	Cell(){
        c_clue = false;
        c_value = 0;
    }

	~Cell(){};

	bool isClue() const{
        return c_clue;
    }

	void setClue(bool clue){
        c_clue = clue;
    }

	int getValue() const{
        return c_value;
    }

	void setValue(int val){
        c_value = val;
    }

	void operator++(int){
        if(c_value >= MAX_VAL*MAX_VAL){
            c_value = 0;
            throw std::out_of_range(MAX_VAL*MAX_VAL+" reached, backtracking needed !");
        }

        c_value++;
    }

	bool operator==(const Cell &c) const{
        return c_value == c.c_value;
    }

};

#endif //SUDOKUCMAKE_CELL_H