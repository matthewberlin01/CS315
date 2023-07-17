#ifndef CS315PROJECT3_ENTITYINSTANCE_HPP
#define CS315PROJECT3_ENTITYINSTANCE_HPP
#include <string>
#include <vector>
#include "Pair.hpp"
using namespace std;

class EntityInstance {
public:
    EntityInstance();

    EntityInstance(EntityInstance *newInstance);

    void addPair(Pair &);
    void setSpaceLength(int);
    Pair &topPair();
    int numAttributes();
    int getSpaceLength();
    vector<string> attributeNames();
    double gpa();
    string term();
    string id();
    bool &hasComma();

    void print();

private:
    vector<Pair> entityPairs;
    int spaces;
    bool _hasComma;
};


#endif //CS315PROJECT3_ENTITYINSTANCE_HPP

