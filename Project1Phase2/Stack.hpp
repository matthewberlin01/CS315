#ifndef CS315PROJECT1_STACK_HPP
#define CS315PROJECT1_STACK_HPP
#include "Token.hpp"
#include <vector>
#include <map>
using namespace std;

class Stack {
public:
    void push(Token value);
    Token top();
    Token at(int);
    void pop();
    bool empty();
    bool findTag(Stack, Token);
    void removeTag(Stack&, Stack&, Token);
    int size();
private:
    vector<Token> stack;
    int stackSize = 0;
};


#endif //CS315PROJECT1_STACK_HPP

