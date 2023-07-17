#include <iostream>
#include <iomanip>
#include "EntitySet.hpp"
using namespace std;

EntitySet::EntitySet()= default;


EntitySet::EntitySet(EntitySet *newSet) {
    instances = newSet->instances;
}

void EntitySet::addEntity(EntityInstance &theInstance){
    instances.push_back(theInstance);
}

void EntitySet::setSpaceLength(int theSpaces){
    spaces = theSpaces;
}

EntityInstance &EntitySet::topEntity(){
    return instances.at(instances.size() - 1);
}

EntityInstance EntitySet::at(int position){
    return instances.at(position);
}

int EntitySet::numSets(){
    return instances.size();
}

int EntitySet::getSpaceLength(){
    return spaces;
}

int EntitySet::findPosition(const string& idValue){
    for(int i = 0; i < instances.size(); i++){
        if(instances.at(i).id() == idValue){
            return i;
        }
    }
    return -1;
}

void EntitySet::print(){
    cout << setw(getSpaceLength()) << "[" << endl;
    for(int i = 0; i < numSets(); i++){
        instances.at(i).print();
        if(instances.at(i).hasComma()){
            cout << "," << endl;
        }
        else{
            cout << endl;
        }
    }
    cout << setw(getSpaceLength()) << "]" << endl;
}

