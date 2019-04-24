#include "project1.h"

using namespace std;

void insertion_sort(std::vector<int>& nums) {
    int size = nums.size();
    for (int i = 1; i < size; ++i) {
        int tmp = nums[i];
        int k = i;
        while (k > 0 && tmp < nums[k - 1]) {
            nums[k] = nums[k - 1];
            --k;
        }
        nums[k] = tmp;
    }
}