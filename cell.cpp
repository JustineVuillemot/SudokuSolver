#include "cell.hpp"

Cell::Cell(){
	c_clue = false;
	c_value = 0;
}

bool Cell::isClue() const{
	return c_clue;
}

void Cell::setClue(bool clue){
	c_clue = clue;
}

int Cell::getValue() const{
	return c_value;
}

void Cell::setValue(int val){
	c_value = val;
}

/*value cannot be > MAX_VAL
throws an error if value is MAX_VAL when called*/
void Cell::operator++(int){
	if(c_value >= 9){
		c_value = 0;
		throw std::out_of_range("9 reached, backtracking needed !");
	}
	
	c_value++;
}

bool Cell::operator==(const Cell &c) const{
	return c_value == c.c_value;
}
