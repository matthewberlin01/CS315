#include <iostream>
#include <vector>
#include "Token.hpp"
#include "Reader.hpp"
#include "TagParser.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    if(argc != 2){
        cout << "usage: " << argv[0] << "nameOfAnInputFile" << endl;
        exit(1);
    }
    ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if(!inputStream.is_open()){
        cout << "Error, could not open file" << endl;
        exit(1);
    }
    vector<Token> tokens;
    Reader reader(inputStream);
    reader.readFile(tokens, inputStream);
    TagParser theParser;
    theParser.parseTags(tokens);
    theParser.printTags();
    return 0;
}

