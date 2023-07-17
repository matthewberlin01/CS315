#include <iostream>
#include <iomanip>
#include "Pair.hpp"
using namespace std;

Pair::Pair(string name, string value){
    _attributeName = name;
    _attributeStringValue = value;
    _attributeNumberValue = 0;
    _spaceLength = 0;
    _isNumber = false;
    _hasComma = false;
}

Pair::Pair(string name, double value){
    _attributeName = name;
    _attributeStringValue = "";
    _attributeNumberValue = value;
    _spaceLength = 0;
    _isNumber = true;
    _hasComma = false;
}

void Pair::setSpaceLength(int length){
    _spaceLength = length;
}

bool Pair::isDouble(){
    return _isNumber;
}

bool &Pair::hasComma(){
    return _hasComma;
}

double Pair::numberValue(){
    return _attributeNumberValue;
}

int Pair::spaceLength(){
    return _spaceLength;
}

string Pair::stringValue(){
    return _attributeStringValue;
}

string Pair::attributeName(){
    return _attributeName;
}

void Pair::print(){
    cout << setw(spaceLength()) << "\"" << attributeName() << "\": ";
    if(isDouble()){
        cout << numberValue();
    }
    else{
        cout <<"\"" << stringValue() << "\"";
    }
    if(hasComma()){
        cout << ",";
    }
    cout << endl;
}

