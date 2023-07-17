
#include <iostream>
#include "JSONToken.hpp"
#include "JSONReader.hpp"
#include "JSONParser.hpp"
#include "EntitySet.hpp"

int main(int argc, char *argv[]) {
    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if(argc != 3) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        exit(2);
    }
    vector<JSONToken> firstTokens;
    vector<JSONToken> secondTokens;
    JSONReader reader(inputStream);
    reader.readFile(firstTokens, inputStream);
    inputStream.open(argv[2], std::ios::in);
    reader.readFile(secondTokens, inputStream);
    vector<EntitySet> sets;
    JSONParser parser;
    parser.parseTags(firstTokens, sets);
    parser.parseTags(secondTokens, sets);
    parser.setsIntersection(sets.at(0), sets.at(1));
    parser.setGPABandValues();
    parser.printGPAMatrix();
    return 0;
}

