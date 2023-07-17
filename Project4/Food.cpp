#include "Food.hpp"

Food::Food(){
    foodValue = 0;
}

int Food::getFoodValue(){
    return foodValue;
}

std::pair<int, int> Food::getPosition(){
    return position;
}

void Food::setFoodValue(){
    foodValue = (rand() % 9) + 1;
}

void Food::setPosition(std::pair<int, int> thePosition){
    position = thePosition;
}