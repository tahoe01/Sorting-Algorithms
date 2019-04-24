#include <vector>

//REQUIREMENTS:
//each sort should be implemented in its own file of the same name e.g. bubble_sort.cpp
//each file should #include this header file
//no file should use anything outside of the C++ standard library
//functions should be tested using g++ in a linux environment
//each function should modify the input vector so that it is sorted upon completion
void bubble_sort(std::vector<int>& nums);
void insertion_sort(std::vector<int>& nums);
void spin_the_bottle_sort(std::vector<int>& nums);
void shell_sort(std::vector<int>& nums, const std::vector<int>& gaps);
void annealing_sort(std::vector<int>& nums, const std::vector<int>& temps, const std::vector<int>& reps);