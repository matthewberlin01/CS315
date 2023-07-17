#include "Stack.hpp"

void Stack::push(Token theToken){
    stack.push_back(theToken);
    stackSize++;
}

Token Stack::top(){
    return stack.at(stack.size() - 1);
}

Token Stack::at(int position){
    return stack.at(position);
}

void Stack::pop(){
    stack.pop_back();
    stackSize--;
}

bool Stack::empty(){
    return stack.empty();
}

bool Stack::findTag(Stack theStack, Token theToken){
    bool hasTag = false;
    while(!theStack.empty()){
        if((theStack.top().getTagName() == theToken.getTagName()) && (theStack.top().isOpenTag() && theStack.top().isCloseAngleBracket())){
            hasTag = true;
            break;
        }
        theStack.pop();
    }
    return hasTag;
}

void Stack::removeTag(Stack &theStack, Stack &malFormedTags, Token theToken){
    Stack tempStack;
    malFormedTags.push(theToken);
    while(theStack.top().getTagName() != theToken.getTagName()){
        tempStack.push(theStack.top());
        malFormedTags.push(theStack.top());
        theStack.pop();
    }
    theStack.pop();
    while(!tempStack.empty()){
        theStack.push(tempStack.top());
        tempStack.pop();
    }
}

int Stack::size(){
    return stackSize;
}

