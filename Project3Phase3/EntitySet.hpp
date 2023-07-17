#ifndef CS315PROJECT3_ENTITYSET_HPP
#define CS315PROJECT3_ENTITYSET_HPP
#include "EntityInstance.hpp"
class EntitySet {
public:
    EntitySet();

    EntitySet(EntitySet *pSet);

    void addEntity(EntityInstance &);
    void setSpaceLength(int);
    EntityInstance &topEntity();
    EntityInstance at(int);
    int numSets();
    int getSpaceLength();
    int findPosition(const string&);

    void print();
private:
    vector<EntityInstance> instances;
    int spaces;

};


#endif //CS315PROJECT3_ENTITYSET_HPP

