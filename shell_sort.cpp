#include "project1.h"

using namespace std;

void shell_sort(std::vector<int>& nums, const std::vector<int>& gaps) {
    int size = nums.size();
    for (auto gap : gaps) {
        for (int i = gap; i < size; ++i) {
            int tmp = nums[i];
            int j = i;
            while (j >= gap && tmp < nums[j-gap]) {
                nums[j] = nums[j - gap];
                j -= gap;
            }
            nums[j] = tmp;
        }
    }
}