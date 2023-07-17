#ifndef CS315PROJECT2_PROJECT2_HPP
#define CS315PROJECT2_PROJECT2_HPP
#include <iostream>
#include <vector>
using namespace std;

    void read_numbers(string fileName, vector<int> &theNumbers);

    int count_inversions_iterative(vector<int> &);
    int count_inversions_recursive(vector<int> &, int);

    void largest_left_iterative(const vector<int> &, vector<int> &);
    int largest_left_helper_iterative(const vector<int> &, int);

    void largest_left_recursive(const vector<int> &, vector<int> &, int);
    int largest_left_helper_recursive(const vector<int> &, int, int);

    void largest_left_right_iterative(const vector<int> &, vector<int> &);
    int largest_right_helper_iterative(const vector<int> &, int);

    void largest_left_right_recursive(const vector<int> &, vector<int> &, int);
    int largest_right_helper_recursive(const vector<int> &, int, int);

    int increasing_sequences_iterative(vector<int> &);
    int increasing_sequences_helper_iterative(vector<int> &, int);

    int increasing_sequences_recursive(vector<int> &, int);
    int increasing_sequences_helper_recursive(vector<int> &, int, int &);

#endif //CS315PROJECT2_PROJECT2_HPP

