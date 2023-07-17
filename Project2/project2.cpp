#include <fstream>
#include "project2.hpp"

void read_numbers(string fileName, vector<int> &theNumbers){
    int numberValue = 0;
    ifstream inputStream;
    inputStream.open(fileName, std::ios::in);
    while(!inputStream.eof()){
        inputStream >> numberValue;
        theNumbers.push_back(numberValue);
    }
}

int count_inversions_iterative(vector<int> &numbers){
    int total = 0;
    for(int i = 0; i < numbers.size() - 1; i++){
        if(numbers.at(i) > numbers.at(i + 1)){
            total++;
        }
    }
    return total;
}

int count_inversions_recursive(vector<int> &numbers, int position){
    if(position == 0){
        return 0;
    }
    int count = count_inversions_recursive(numbers, position - 1);
    if(position != numbers.size() && numbers.at(position - 1) > numbers.at(position)){
        count++;
        return count;
    }
    return count;
}

void largest_left_iterative(const vector<int> &numbers, vector<int> &result){
    for(int i = 0; i < numbers.size(); i++){
        result.at(i) = largest_left_helper_iterative(numbers, i);
    }
}

int largest_left_helper_iterative(const vector<int> &numbers, int position){
    if(position == 0){
        return 0;
    }
    for(int i = position - 1; i >= 0; i--){
        if(numbers.at(i) > numbers.at(position)){
            return numbers.at(i);
        }
    }
    return 0;
}

void largest_left_recursive(const vector<int> &numbers, vector<int> &result, int position){
    if(position != 1){
        largest_left_recursive(numbers, result, position - 1);
    }
    result.at(position - 1) = largest_left_helper_recursive(numbers, position - 1, numbers.at(position - 1));
}

int largest_left_helper_recursive(const vector<int> &numbers, int position, int value){
    if(position == 0){
        return 0;
    }
    int largestLeft;
    if(numbers.at(position - 1) > value){
        largestLeft = numbers.at(position - 1);
    }
    else{
        largestLeft = largest_left_helper_recursive(numbers, position - 1, value);
    }
    return largestLeft;
}

void largest_left_right_iterative(const vector<int> &numbers, vector<int> &result){
    for(int i = 0; i < numbers.size(); i++){
        if(largest_left_helper_iterative(numbers, i) > largest_right_helper_iterative(numbers, i)){
            result.at(i) = largest_left_helper_iterative(numbers, i);
        }
        else{
            result.at(i) = largest_right_helper_iterative(numbers, i);
        }
    }
}

int largest_right_helper_iterative(const vector<int> & numbers, int position){
    if(position == numbers.size() - 1){
        return 0;
    }
    for(int i = position + 1; i < numbers.size(); i++){
        if(numbers.at(i) > numbers.at(position)){
            return numbers.at(i);
        }
    }
    return 0;
}

void largest_left_right_recursive(const vector<int> & numbers, vector<int> &result, int position){
    if(position != 1){
        largest_left_right_recursive(numbers, result, position - 1);
    }
    if(largest_left_helper_recursive(numbers, position - 1, numbers.at(position - 1)) > largest_right_helper_recursive(numbers, position - 1, numbers.at(position - 1))){
        result.at(position - 1) = largest_left_helper_recursive(numbers, position - 1, numbers.at(position - 1));
    }
    else{
        result.at(position - 1) = largest_right_helper_recursive(numbers, position - 1, numbers.at(position - 1));
    }
}

int largest_right_helper_recursive(const vector<int> &numbers, int position, int value){
    if(position == numbers.size() - 1){
        return 0;
    }
    int largestRight;
    if(numbers.at(position + 1) > value){
        largestRight = numbers.at(position + 1);
    }
    else{
        largestRight = largest_right_helper_recursive(numbers, position + 1, value);
    }
    return largestRight;
}

int increasing_sequences_iterative(vector<int> &numbers){
    int largestSequence = 1;
    for(int i = 0; i < numbers.size() - 1; i++){
        if(increasing_sequences_helper_iterative(numbers, i) > largestSequence){
            largestSequence = increasing_sequences_helper_iterative(numbers, i);
        }
    }
    return largestSequence;
}

int increasing_sequences_helper_iterative(vector<int> &numbers, int position){
    int currentSequence = 1;
    for(int i = position; i < numbers.size() - 1; i++){
        if(numbers.at(i + 1) >= numbers.at(i)){
            currentSequence++;
        }
        else{
            return currentSequence;
        }
    }
    return currentSequence;
}

int increasing_sequences_recursive(vector<int> &numbers, int position){
    int largestSequence = 1;
    if(position == numbers.size() - 1){
        return largestSequence;
    }
    if(increasing_sequences_helper_recursive(numbers, position, largestSequence) > largestSequence){
        largestSequence = increasing_sequences_helper_recursive(numbers, position, largestSequence);
    }
    int currentSequence = increasing_sequences_recursive(numbers, position + 1);
    if(currentSequence > largestSequence){
        largestSequence = currentSequence;
    }
    return largestSequence;
}

int increasing_sequences_helper_recursive(vector<int> &numbers, int position, int &theSequence){
    int currentSequence = theSequence;
    if(position == numbers.size() - 1){
        return currentSequence;
    }
    if(numbers.at(position + 1) >= numbers.at(position)){
        currentSequence++;
    }
    else{
        return currentSequence;
    }
    currentSequence = increasing_sequences_helper_recursive(numbers, position + 1, currentSequence);
    return currentSequence;
}
