#include "Screen.hpp"

Screen::Screen(int theRows, int theCols){
    rows = theRows;
    cols = theCols;

    screenState.resize(rows);
    for(int i = 0; i < rows; i++){
        screenState.at(i).resize(cols);
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(i == 0 || j == 0 || i == rows - 1 || j == cols - 1){
                screenState.at(i).at(j) = -1;
            }
        }
    }
}

int Screen::getRows(){
    return rows;
}

int Screen::getCols(){
    return cols;
}

int Screen::getPositionValue(int row, int col){
    return screenState.at(row).at(col);
}

int Screen::getPositionValue(std::pair<int, int> positions){
    return screenState.at(positions.first).at(positions.second);
}

void Screen::setPositionValue(int row, int col, int value){
    screenState.at(row).at(col) = value;
}

void Screen::swapPositionValue(std::pair<int, int> oldPosition, std::pair<int, int> newPosition, int oldValue, int newValue){
    setPositionValue(newPosition.first, newPosition.second, oldValue);
    setPositionValue(oldPosition.first, oldPosition.second, newValue);

}

void Screen::overridePositionValue(std::pair<int, int> oldPosition, std::pair<int, int> newPosition, int oldValue){
    setPositionValue(newPosition.first, newPosition.second, oldValue);
    setPositionValue(oldPosition.first, oldPosition.second, -1);
}
