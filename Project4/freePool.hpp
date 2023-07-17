#include <vector>

class freePool{
public:
    freePool(int, int);
    int size();
    int getIndex();
    void setIndex(int);
    void setValue(int, int, int);
    void swapValue(int, int);
    std::pair<int, int> at(int);
    
private:
    std::vector<std::pair<int, int>> space;
    int lastIndex;
};