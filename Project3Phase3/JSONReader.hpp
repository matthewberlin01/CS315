#ifndef CS315PROJECT3_JSONREADER_HPP
#define CS315PROJECT3_JSONREADER_HPP
#include <fstream>
#include <vector>
#include "JSONToken.hpp"
using namespace std;

class JSONReader {
public:
    JSONReader(ifstream &inputStream);

    void readFile(vector<JSONToken>&, ifstream&);

    JSONToken getToken(char&);

    void print(vector<JSONToken>&);

private:
    bool isWhiteSpaceOrNewLine(char, int&);
    ifstream &instream;
};


#endif //CS315PROJECT3_JSONREADER_HPP

