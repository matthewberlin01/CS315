#include <iostream>
#include <iomanip>
#include "JSONParser.hpp"
using namespace std;

JSONParser::JSONParser(){
    gpaMatrix.resize(8);
    for(int i = 0; i < gpaMatrix.size(); i++){
        gpaMatrix.at(i).resize(8);
    }
}

void JSONParser::parseTags(vector<JSONToken> &theTokens, vector<EntitySet> &theSet){
    string theName;
    EntityInstance currentEntityInstance;
    EntitySet currentEntitySet;

    for(int i = 0; i < theTokens.size(); i++){
        if(theTokens.at(i).isOpenBracket()){
            currentEntitySet = new EntitySet;
            currentEntitySet.setSpaceLength(theTokens.at(i).getSpaces());
        }
        else if(theTokens.at(i).isCloseBracket()){
            theSet.push_back(currentEntitySet);
        }
        else if(theTokens.at(i).isOpenBrace()){
            currentEntityInstance = new EntityInstance;
            currentEntityInstance.setSpaceLength(theTokens.at(i).getSpaces());
        }
        else if(theTokens.at(i).isCloseBrace()){
            currentEntitySet.addEntity(currentEntityInstance);
        }
        else if(theTokens.at(i).isColon()){
            if(theTokens.at(i + 1).isNumberValue()){
                Pair currentPair(theName, theTokens.at(i + 1).getNumValue());
                currentPair.setSpaceLength(theTokens.at(i - 1).getSpaces());
                currentEntityInstance.addPair(currentPair);
            }
            else{
                Pair currentPair(theName, theTokens.at(i + 1).getTagName());
                currentPair.setSpaceLength(theTokens.at(i - 1).getSpaces());
                currentEntityInstance.addPair(currentPair);
            }
            i++;
        }
        else if(theTokens.at(i).isComma()){
            if(theTokens.at(i - 1).isCloseBrace()){
                currentEntitySet.topEntity().hasComma() = true;
            }
            else{
                currentEntityInstance.topPair().hasComma() = true;
            }
        }
        else if(!theTokens.at(i).getTagName().empty()){
            theName = theTokens.at(i).getTagName();
        }
        else{
            cout << "Token read that does not fit any of the requirements for being a token." << endl;
            exit(1);
        }
    }
}

void JSONParser::printSets(vector<EntitySet> &theSets){
    for(int i = 0; i < theSets.size(); i++){
        theSets.at(i).print();
    }
}

void JSONParser::setsIntersection(EntitySet &previousSet, EntitySet &currentSet){
    int currentSetPosition;
    for(int i = 0; i < previousSet.numSets(); i++){
        currentSetPosition = currentSet.findPosition(previousSet.at(i).id());
        if(currentSetPosition != -1){
            std::pair<EntityInstance, EntityInstance> make_pair(previousSet.at(i), currentSet.at(currentSetPosition));
            previousCurrentEntities.push_back(make_pair);
        }
    }
}

void JSONParser::setGPABandValues(){
    for(int i = 0; i < previousCurrentEntities.size(); i++){
        double previousGPA = previousCurrentEntities.at(i).first.gpa();
        double currentGPA = previousCurrentEntities.at(i).second.gpa();
        int previousPosition = findGPABandPosition(previousGPA);
        int currentPosition = findGPABandPosition(currentGPA);
        if(previousPosition != -1 && currentPosition != -1){
            gpaMatrix.at(currentPosition).at(previousPosition)++;
        }
        else{
            cout << "gpa value collected that does not fall within the given gpa band." << endl;
            exit(1);
        }
    }
}

void JSONParser::printGPAMatrix(){
    cout << "[" << endl;
    for(int i = 0; i < gpaMatrix.size(); i++){
        cout << setw(3) << "[";
        for(int j = 0; j < gpaMatrix.size() - 1; j++){
            cout << gpaMatrix.at(i).at(j) << ", ";
        }
        if(i == gpaMatrix.size() - 1){
            cout << gpaMatrix.at(i).at(7) << "]" << endl;
        }
        else{
            cout << gpaMatrix.at(i).at(7) << "]," << endl;
        }
    }
    cout << "]" << endl;
}

int JSONParser::findGPABandPosition(double gpaValue){
    for(int i = 0; i < gpaBand.size() - 1; i++){
        if(i != gpaBand.size() - 2){
            if(gpaValue > gpaBand.at(i + 1) && gpaValue <= gpaBand.at(i)){
                return i;
            }
        }
        else{
            if(gpaValue >= gpaBand.at(i + 1) && gpaValue <= gpaBand.at(i)){
                return i;
            }
        }
    }
    return -1;
}

