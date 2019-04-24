#include "project1.h"
#include "swap.cpp"
#include "random_generation_sample.cpp"

using namespace std;

void annealing_sort(std::vector<int>& nums, const std::vector<int>& temps, const std::vector<int>& reps) {
    int n = nums.size();
    int t = temps.size();
    mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();
    for (int j = 0; j < t-1; ++j) {
        for (int i = 0; i < n-1; ++i) {
            for (int k = 1; k <= reps[j]; ++k) {
                uniform_int_distribution<int> ui = get_uniform_int_generator(i+1, min(n-1, i+temps[j]));
                int s = ui(mt);
                if (nums[i] > nums[s]) {
                    swap_element(nums[i], nums[s]);
                }
            }
        }
        for (int i = n-1; i >= 1; --i) {
            for (int k = 1; k <= reps[j]; ++k) {
                uniform_int_distribution<int> ui = get_uniform_int_generator(max(0, i-temps[j]), i-1);
                int s = ui(mt); 
                if (nums[s] > nums[i]) {
                    swap_element(nums[i], nums[s]);
                }
            }
        }
    }
}