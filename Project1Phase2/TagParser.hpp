#ifndef CS315PROJECT1_TAGPARSER_HPP
#define CS315PROJECT1_TAGPARSER_HPP
#include <map>
#include "Stack.hpp"
#include "Reader.hpp"
#include "Token.hpp"
using namespace std;

class TagParser {
public:
    void parseTags(vector<Token>&);
    void printTags();
private:
    Stack theStack;
    Stack malFormedTags;
    map <string, Stack> wellFormedTags;
};


#endif //CS315PROJECT1_TAGPARSER_HPP

