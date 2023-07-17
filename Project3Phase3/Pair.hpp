#ifndef CS315PROJECT3_PAIR_HPP
#define CS315PROJECT3_PAIR_HPP
#include <string>
using namespace std;

class Pair {
public:
    Pair(string, string);
    Pair(string, double);

    void setSpaceLength(int);

    bool isDouble();
    bool &hasComma();
    double numberValue();
    int spaceLength();
    string stringValue();
    string attributeName();

    void print();

private:
    string _attributeName;
    string _attributeStringValue;
    double _attributeNumberValue;
    int _spaceLength;
    bool _isNumber;
    bool _hasComma;
};


#endif //CS315PROJECT3_PAIR_HPP

