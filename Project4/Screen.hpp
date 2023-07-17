#include <vector>

class Screen{
public:
    Screen(int, int);
    int getRows();
    int getCols();
    int getPositionValue(int, int);
    int getPositionValue(std::pair<int, int>);
    void setPositionValue(int, int, int);
    void swapPositionValue(std::pair<int, int>, std::pair<int, int>, int, int);
    void overridePositionValue(std::pair<int, int>, std::pair<int, int>, int);

private:
    std::vector<std::vector<int>> screenState;
    int rows;
    int cols;
};
