#include <vector>
#include <stdlib.h>

class Food{
    public:
        Food();
        int getFoodValue();
        std::pair<int, int> getPosition();
        void setFoodValue();
        void setPosition(std::pair<int, int>);

    private:
        int foodValue;
        std::pair<int, int> position;
};
