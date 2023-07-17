#include "Reader.hpp"
#include <iostream>
using namespace std;

Reader::Reader(ifstream &inputStream): instream{inputStream}{
//Known as an initializer list  -------^
}

bool Reader::isTokenHeader(char theCharacter){
    bool isImportantChar = false;
    if(theCharacter == '<' || theCharacter == '>' || (theCharacter == '/' && instream.peek() == '>')){
        isImportantChar = true;
    }
    return isImportantChar;
}

void Reader::readFile(vector<Token> &tokens, ifstream &inputStream){
    char character;
    int lineNum = 1;
    int position = 0;

    while(!instream.eof()){
        //Checks to see if the next character is a newline. If so, then sets the next character as normal and
        // increases lineNum by one.
        if(instream.peek() == '\n'){
            instream.get(character);
            lineNum++;
            position++;
        }
        else{
            instream.get(character);
            position++;
        }
        if(isTokenHeader(character)){
            Token token = getToken(character, lineNum, position);
            tokens.push_back(token);
        }
    }
}

Token Reader::getToken(char &theCharacter, int &lineNum, int &position){
    string name = "";
    Token token(lineNum, position);

    if(theCharacter == '<'){
        if(instream.peek() == '/'){
            token.isCloseTag() = true;
        }
        else if(isdigit(instream.peek()) || isspace(instream.peek())){
            token.isOpenAngleBracket() = true;
            return token;
        }

        while(!isspace(theCharacter) && theCharacter != '\n'){
            if(theCharacter != '/' && instream.peek() == '>'){
                if(isalpha(theCharacter)){
                    name += theCharacter;
                    break;
                }
            }
            else{
                if(isalpha(theCharacter)){
                    name += theCharacter;
                }
                instream.get(theCharacter);
                position++;
            }
        }
        if(token.isCloseTag()){
            token.setCloseTag(name);
        }
        else{
            token.setOpenTag(name);
        }
    }
    else if(theCharacter == '/' && instream.peek() == '>'){
        instream.get(theCharacter);
        position++;
        token.isCloseStandAloneTag() = true;
    }
    else if(theCharacter == '>'){
        token.isCloseAngleBracket() = true;
    }
    else{
        cout << "Error, tag character detected, but didn't meet the criteria for open, close, or stand alone tags: " << theCharacter << endl;
        exit(1);
    }

    return token;
}
