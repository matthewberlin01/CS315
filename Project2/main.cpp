#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "project2.hpp"
using namespace std;

int main(int argc, char *argv[]){
    if(argc != 2){
        std::cout << "usage:" << argv[0] << " nameOfInputFile\n";
        exit(2);
    }
    vector<int> numbers;
    vector<int> result;
    string fileName = argv[1];
    read_numbers(fileName, numbers);
    result.resize(numbers.size());
    int theResult;
    if(fileName == "count_inversions_input.txt"){
        theResult = count_inversions_iterative(numbers);
        cout << theResult << endl;
        cout << endl;

        theResult = count_inversions_recursive(numbers, numbers.size());
        cout << theResult << endl;
    }
    else if(fileName == "largest_left_input.txt"){
        largest_left_iterative(numbers, result);
        for(int i = 0; i < result.size(); i++){
            cout << result.at(i) << endl;
        }
        cout << endl;

        largest_left_recursive(numbers, result, numbers.size());
        for(int i = 0; i < result.size(); i++){
            cout << result.at(i) << endl;
        }
    }
    else if(fileName == "largest_left_right_input.txt"){
        largest_left_right_iterative(numbers, result);
        for(int i = 0; i < result.size(); i++){
            cout << result.at(i) << endl;
        }
        cout << endl;

        largest_left_right_recursive(numbers, result, numbers.size());
        for(int i = 0; i < result.size(); i++){
            cout << result.at(i) << endl;
        }
    }
    else if(fileName == "increasing_sequences_input.txt"){
        theResult = increasing_sequences_iterative(numbers);
        cout << theResult << endl;
        cout << endl;

        theResult = increasing_sequences_recursive(numbers, 0);
        cout << theResult << endl;
    }
    else{
        cout << "Error, invalid file name entered." << endl;
    }
    return 0;
}
