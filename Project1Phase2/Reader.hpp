#ifndef CS315PROJECT1_READER_HPP
#define CS315PROJECT1_READER_HPP
#include "Token.hpp"
#include <fstream>
#include <vector>
using namespace std;

class Reader {
public:
    Reader(ifstream &inputStream);

    void readFile(vector<Token>&, ifstream&);

    Token getToken(char&, int&, int&);
private:
    bool isTokenHeader(char);
    ifstream &instream;
};


#endif //CS315PROJECT1_READER_HPP

