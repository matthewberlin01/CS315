#ifndef CS315PROJECT3_JSONPARSER_HPP
#define CS315PROJECT3_JSONPARSER_HPP
#include "JSONToken.hpp"
#include "EntitySet.hpp"

class JSONParser {
public:
    JSONParser();

    void parseTags(vector<JSONToken>&, vector<EntitySet>&);
    void printSets(vector<EntitySet>&);
    void setsIntersection(EntitySet&, EntitySet&);
    void setGPABandValues();
    void printGPAMatrix();

    int findGPABandPosition(double);
private:
    vector<std::pair<EntityInstance, EntityInstance>> previousCurrentEntities;
    vector<vector<int>> gpaMatrix;
    vector<double> gpaBand{4.0, 3.67, 3.3, 3.0, 2.67, 2.3, 2.0, 1.67, 0.0};

};


#endif //CS315PROJECT3_JSONPARSER_HPP

