#include "Worm.hpp"

Worm::Worm(){
    head = 0;
    tail = 0;
    foodValue = 0;
    score = 0;
    _hasFood = false;
    _isDead = false;
    indexPosition = 0;
}

void Worm::setSize(int size){
    bodyPosition.resize(size);
}

void Worm::spawn(int row, int col){
    bodyPosition.at(head).first = row;
    bodyPosition.at(head).second = col;
    head++;
}


int Worm::getSize(){
    return bodyPosition.size();
}

int Worm::getHead(){
    return head;
}

int Worm::getTail(){
    return tail;
}

int Worm::getScore(){
    return score;
}

int Worm::getFoodValue(){
    return foodValue;
}

int Worm::getIndexPosition(){
    return indexPosition;
}

std::pair<int, int> Worm::getPosition(int position){
    //Can be -1 when trying to access the element before zero, which would be the last element in the array.
    if(position < 0){
        position = getSize() + position;
    }
    return bodyPosition.at(position);
}
void Worm::foodlessMove(char theCharacter){
    if(theCharacter == 'h' || theCharacter == 'a'){
        //Moves the worm left.
        bodyPosition.at(head).first = getPosition(head - 1).first;
        bodyPosition.at(head).second = getPosition(head - 1).second - 1;
    }
    else if(theCharacter == 'j' || theCharacter == 's'){
        //Moves the worm down.
        bodyPosition.at(head).first = getPosition(head - 1).first + 1;
        bodyPosition.at(head).second = getPosition(head - 1).second;
    }
    else if(theCharacter == 'k' || theCharacter == 'w'){
        //Moves the worm up.
        bodyPosition.at(head).first = getPosition(head - 1).first - 1;
        bodyPosition.at(head).second = getPosition(head - 1).second;
    }
    else if(theCharacter == 'l' || theCharacter == 'd'){
        //Moves the worm right.
        bodyPosition.at(head).first = getPosition(head - 1).first;
        bodyPosition.at(head).second = getPosition(head - 1).second + 1;
    }
    else{
        //occurs when there is no input yet, so no moves to make.
        bodyPosition.at(head).first = getPosition(head - 1).first;
        bodyPosition.at(head).second = getPosition(head - 1).second;
    }
    //increment head and tail by one to move through array now that the worm has moved.
    head++;
    tail++;
    //reset head and tail when they reach the end of the vector.
    if(head == getSize()){
        head = 0;
    }
    if(tail == getSize()){
        tail = 0;
    }
}

void Worm::foodMove(char theCharacter){

    if(theCharacter == 'h' || theCharacter == 'a'){
        //Moves the worm left.
        bodyPosition.at(head).first = getPosition(head - 1).first;
        bodyPosition.at(head).second = getPosition(head - 1).second - 1;
    }
    else if(theCharacter == 'j' || theCharacter == 's'){
        //Moves the worm down.
        bodyPosition.at(head).first = getPosition(head - 1).first + 1;
        bodyPosition.at(head).second = getPosition(head - 1).second;
    }
    else if(theCharacter == 'k' || theCharacter == 'w'){
        //Moves the worm up.
        bodyPosition.at(head).first = getPosition(head - 1).first - 1;
        bodyPosition.at(head).second = getPosition(head - 1).second;
    }
    else if(theCharacter == 'l' || theCharacter == 'd'){
        //Moves the worm right.
        bodyPosition.at(head).first = getPosition(head - 1).first;
        bodyPosition.at(head).second = getPosition(head - 1).second + 1;
    }
    else{
        //occurs when there is no input yet, so no moves to make.
        bodyPosition.at(head).first = getPosition(head - 1).first;
        bodyPosition.at(head).second = getPosition(head - 1).second;
    }
    //increment head by one to move through array now that the worm has moved. Decrease food value.
    head++;
    foodValue--;
    //reset head when they reach the end of the vector.
    if(head == getSize()){
        head = 0;
    }

}

void Worm::setScore(int points){
    score += points;
}

void Worm::setFoodValue(int value){
    foodValue += value;
}

void Worm::setIndexPosition(int position){
    indexPosition = position;
}

bool &Worm::isDead(){
    return _isDead;
}

bool &Worm::hasFood(){
    return _hasFood;
}

bool Worm::isImportantChar(char theCharacter){
    if(theCharacter == 'h' || theCharacter == 'j' || theCharacter == 'k' || theCharacter == 'l' || theCharacter == 'w' || theCharacter == 'a' || theCharacter == 's' || theCharacter == 'd'){
        return true;
    }
    return false;
}