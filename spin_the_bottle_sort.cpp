#include <random>
#include <algorithm>
#include "project1.h"
#include "random_generation_sample.cpp"
#include "swap.cpp"

using namespace std;

void spin_the_bottle_sort(std::vector<int>& nums) {
    int size = nums.size();
    mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();
    uniform_int_distribution<int> ui = get_uniform_int_generator(0, size-1);
    while (!is_sorted(nums.begin(), nums.end())) {
        for (int i = 0; i < size; ++i) {
            int s = ui(mt);
            if ((i < s && nums[i] > nums[s]) || (i > s && nums[i] < nums[s])) {
                swap_element(nums[i], nums[s]);
            }
        }
    } 
}