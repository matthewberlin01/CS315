#ifndef CS315PROJECT3_JSONTOKEN_HPP
#define CS315PROJECT3_JSONTOKEN_HPP
#include <string>
using namespace std;

class JSONToken {
public:
    JSONToken();

    bool &isOpenBrace();
    bool &isCloseBrace();
    bool &isOpenBracket();
    bool &isCloseBracket();
    bool &isColon();
    bool &isComma();
    bool &isNumberValue();

    string getTagName();
    double getNumValue();
    int getSpaces();

    void setTagName(string);
    void setNumberValue(double);
    void setSpaces(int);

    void print();

private:
    string tagName;
    double numValue;
    int spaces;
    bool openBrace;
    bool closeBrace;
    bool openBracket;
    bool closeBracket;
    bool colon;
    bool comma;
    bool numberValue;
};


#endif //CS315PROJECT3_JSONTOKEN_HPP

