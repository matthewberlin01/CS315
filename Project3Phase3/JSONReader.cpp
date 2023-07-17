#include <iostream>
#include "JSONReader.hpp"


JSONReader::JSONReader(ifstream &inputStream): instream(inputStream){

}

bool JSONReader::isWhiteSpaceOrNewLine(char theCharacter, int &spaces){
    if(isspace(theCharacter)){
        spaces++;
        return true;
    }
    else if(theCharacter == '\n' || theCharacter == -1){
        return true;
    }
    else{
        return false;
    }
}

void JSONReader::readFile(vector<JSONToken> &theTokens, ifstream &inputStream){
    char character;
    int spaces = 0;
    while(!instream.eof()){
        instream.get(character);
        if(!isWhiteSpaceOrNewLine(character, spaces)){
            JSONToken token = getToken(character);
            token.setSpaces(spaces);
            theTokens.push_back(token);
            spaces = 0;
        }
    }
    instream.close();
}

JSONToken JSONReader::getToken(char &theCharacter){
    string tagName;
    string stringValue;
    double numberValue = 0;
    JSONToken theToken;

    if(theCharacter == '{'){
        theToken.isOpenBrace() = true;
    }
    else if(theCharacter == '}'){
        theToken.isCloseBrace() = true;
    }
    else if(theCharacter == '['){
        theToken.isOpenBracket() = true;
    }
    else if(theCharacter == ']'){
        theToken.isCloseBracket() = true;
    }
    else if(theCharacter == ':'){
        theToken.isColon() = true;
    }
    else if(theCharacter == ','){
        theToken.isComma() = true;
    }
    else if(isdigit(theCharacter)){
        stringValue = theCharacter;
        while(isdigit(instream.peek()) || instream.peek() == '.'){
            instream.get(theCharacter);
            stringValue += theCharacter;
        }
        numberValue = stod(stringValue);
        theToken.setNumberValue(numberValue);
    }
    else if(theCharacter == '"'){
        do{
            instream.get(theCharacter);
            stringValue += theCharacter;
        }while(instream.peek() != '"');
        instream.get(theCharacter);
        theToken.setTagName(stringValue);
    }
    else{
        cout << "Error: Token read that does not fit any of the specified token requirements." << endl;
        exit(1);
    }
    return theToken;
}

void JSONReader::print(vector<JSONToken> &tokens){
    for(int i = 0; i < tokens.size(); i++){
        tokens.at(i).print();
    }
}

