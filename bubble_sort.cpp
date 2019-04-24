#include "project1.h"
#include "swap.cpp"

using namespace std;

void bubble_sort(std::vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j < size - i; ++j) {
            if (nums[j] < nums[j - 1]) {
                swap_element(nums[j-1], nums[j]);
            }
        }
    }
}