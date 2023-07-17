#include "freePool.hpp"

freePool::freePool(int rows, int cols){
    space.resize(((rows - 2) * (cols - 2)) + 1 );
    lastIndex = 0;
}

int freePool::size(){
    return space.size();
}

int freePool::getIndex(){
    return lastIndex;
}

void freePool::setIndex(int value){
    lastIndex += value;
}

void freePool::setValue(int position, int rowValue, int columnValue){
    //Position can be -1 when the worm isn't moving or when the worm hits a wall.
    if(position != -1){
        space.at(position).first = rowValue;
        space.at(position).second = columnValue;
    }
}

void freePool::swapValue(int oldPosition, int newPosition){
    
    if(oldPosition != -1 && newPosition != -1){
        std::pair<int, int> tempPosition = space.at(newPosition);
        space.at(newPosition) = space.at(oldPosition);
        space.at(oldPosition) = tempPosition;
    }
}

std::pair<int, int> freePool::at(int position){
    return space.at(position);
}