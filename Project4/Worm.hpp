#include <vector>

class Worm{
public:
    Worm();
    void setSize(int);
    void spawn(int, int);
    int getSize();
    int getHead();
    int getTail();
    int getScore();
    int getFoodValue();
    int getIndexPosition();
    std::pair<int, int> getPosition(int);
    void foodlessMove(char);
    void foodMove(char);
    void setScore(int);
    void setFoodValue(int);
    void setIndexPosition(int);
    bool &isDead();
    bool &hasFood();
    bool isImportantChar(char);
    
private:
    std::vector<std::pair<int, int>> bodyPosition;
    int indexPosition;
    int head;
    int tail;
    int foodValue;
    int score;
    bool _hasFood;
    bool _isDead;
};