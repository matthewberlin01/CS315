#include <iostream>
#include "JSONToken.hpp"

JSONToken::JSONToken(){
    tagName = "";
    numValue = 0;
    spaces = 0;
    openBrace = false;
    closeBrace = false;
    openBracket = false;
    closeBracket = false;
    colon = false;
    comma = false;
    numberValue = false;
}

bool &JSONToken::isOpenBrace(){
    return openBrace;
}

bool &JSONToken::isCloseBrace(){
    return closeBrace;
}

bool &JSONToken::isOpenBracket(){
    return openBracket;
}

bool &JSONToken::isCloseBracket(){
    return closeBracket;
}

bool &JSONToken::isColon(){
    return colon;
}

bool &JSONToken::isComma(){
    return comma;
}

bool &JSONToken::isNumberValue(){
    return numberValue;
}

string JSONToken::getTagName(){
    return tagName;
}

double JSONToken::getNumValue(){
    return numValue;
}

int JSONToken::getSpaces(){
    return spaces;
}

void JSONToken::setTagName(string name){
    tagName = name;
}

void JSONToken::setNumberValue(double value){
    numValue = value;
    isNumberValue() = true;
}

void JSONToken::setSpaces(int theSpaces){
    spaces = theSpaces;
}

void JSONToken::print(){
    if(isOpenBrace()){
        cout << "{" << endl;
    }
    else if(isCloseBrace()){
        cout << "}" << endl;
    }
    else if(isOpenBracket()){
        cout << "[" << endl;
    }
    else if(isCloseBracket()){
        cout << "]" << endl;
    }
    else if(isColon()){
        cout << ":" << endl;
    }
    else if(isComma()){
        cout << "," << endl;
    }
    else if(!getTagName().empty()){
        cout << getTagName() << endl;
    }
    else if(isNumberValue()){
        cout << getNumValue() << endl;
    }
    else{
        cout << "Error: Token made that does not fit any of the specified token requirements." << endl;
        exit(1);
    }
}

