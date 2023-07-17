#include <iostream>
#include <iomanip>
#include "EntityInstance.hpp"
using namespace std;

EntityInstance::EntityInstance(){
    _hasComma = false;
    spaces = 0;
}

void EntityInstance::addPair(Pair &thePair){
    entityPairs.push_back(thePair);
}

void EntityInstance::setSpaceLength(int theSpaces){
    spaces = theSpaces;
}

Pair &EntityInstance::topPair(){
    return entityPairs.at(entityPairs.size() - 1);
}

int EntityInstance::numAttributes(){
    return entityPairs.size();
}

int EntityInstance::getSpaceLength(){
    return spaces;
}

vector<string> EntityInstance::attributeNames(){
    vector<string> theNames;
    for(int i = 0; i < numAttributes(); i++){
        theNames.push_back(entityPairs.at(i).attributeName());
    }
    return theNames;
}

double EntityInstance::gpa(){
    for(int i = 0; i < numAttributes(); i++){
        if(entityPairs.at(i).attributeName() == "gpa"){
            return entityPairs.at(i).numberValue();
        }
    }
    return -1;
}

string EntityInstance::term(){
    for(int i = 0; i < numAttributes(); i++){
        if(entityPairs.at(i).attributeName() == "term"){
            return entityPairs.at(i).stringValue();
        }
    }
    return "";
}

string EntityInstance::id(){
    for(int i = 0; i < numAttributes(); i++){
        if(entityPairs.at(i).attributeName() == "id"){
            return entityPairs.at(i).stringValue();
        }
    }
    return "";
}

bool &EntityInstance::hasComma(){
    return _hasComma;
}

void EntityInstance::print(){
    cout << setw(getSpaceLength()) << "{" << endl;
    for(int i = 0; i < numAttributes(); i++){
        entityPairs.at(i).print();
    }
    cout << setw(getSpaceLength()) << "}";
}

EntityInstance::EntityInstance(EntityInstance *newInstance) {
    entityPairs = newInstance->entityPairs;
    _hasComma = newInstance->_hasComma;
}

