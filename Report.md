# Project 1: Testing Running Times

## **Overview**

This projects consists of the experimental anaylis of different sorting algorithm's running times. The tests are implemented as followed:

1. Implement different sorting algorithms to test. Sorting algorithms include: 

* bubble sort
* insertion sort
* spin the bottle sort
* shell sort with different gaps
* annealing sort with different temparature and repetition sequences.

2. For each sorting algorithm, perform runtime experiments on random permutations (Distribution: **Uniformly-distributed permutations**), with multiple runs for increasing problem sizes. 

3. Do the same test as in Step 2 for another distribution: **Almost-sorted permutations**.

4. For each distribution, plot the results on a log-log scale and perform regression analysis. Based on the plot, determine each algorithm's asymptotic running time.

## **Algorithms**

This section will introduce the mechanism of implementation of each algorithm. Pseudocode/C++ code of some algorithms will be shown. 

### Subroutine
When implementing sorting algorithms, one subroutine that is usually used is to swap two elements by its indices in the list.

C++ code:

```c++
void swap_element(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}
```

### Bubble sort

Bubble sort algorithm repeated scan a list of elements, exchanging elements if they are not relevant order (to bubble the largest element to the right of the list), until all elements have been placed in their proper order.

Given n elements in the list, in the first scan, the algorithm will bubble the largest value to the rightmost position of the list, which may have at most n-1 swap operations. In the second scan, it will bubble the second largest value to the second rightmost position of the list, which may have at most n-2 swap operations, etc.

In total, the largest possible number of swap operations is: `(n - 1) + (n - 2) + ... + 1`, which is bounded by `O(N^2)`.

C++ code:

```c++
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
```

### Insertion sort

Insertion sort first considers the first item to be a sorted list. Then, it insert the second item to the sorted list ans keep swapping elements if needed. Repeat the steps until it processes the last elements in the list. For each step, the element will be inserted into its proper position of the given sorted list.

The largest possible number of operations is bounded by `O(N^2)`.

C++ code:

```c++
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
```

### Spin the bottle sort

Spin the bottle sort repeated scan the list untit the list is sorted. In each iteration, it uniformly chooses an element and performs swap operation with current scanned element if needed.

C++ code:

```c++
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
```

### Shell sort

Based on the fact that insertion sort has linear run time if the input is already sorted, shell sort orders the list by comparing elements that are separated by decreasing gap numbers. A gap sequence that contains 1 can ensure the this algorithm is correct.

When testing this algorithm, some different gap sequences will be used to find which two gap sequences are the best two. All of the gap sequences running time of different size will be plotted in one graph. In this way, the best two sequences that has the fastest asymptotic running time can be found.

C++ code:

```c++
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
```

### Annealing sort
Inspired by simulated annealing meta-heuristic, which involves solving a problem by a sequence of choices from the nubmer of r_j neighbors and T_j distance.

Pseudocode:

```Pseudocode
for j = 1 to t do
    for i = 1 to n − 1 do
        for k = 1 to r_j do
            Let s be a random integer in the range [i + 1, min{n, i + T_j}].
            if A[i] > A[s] then
                Swap A[i] and A[s]
    for i = n downto 2 do
        for k = 1 to r_j do
            Let s be a random integer in the range [max{1, i − T_j}, i − 1].
            if A[s] > A[i] then
                Swap A[i] and A[s]
```

## **Runtime Testing Methods**

Running time experiments will be tested on two distributions: **Uniformly distributed permutations** and **Almost-sorted permutations**. For each distribution, run experiments for increasing problem size, for example, 10, 100, 1000, 10,000, 100,000, 1,000,000 elements. For each problem size, generate 3 random permutation of the current testing distribution. For each permutation, run 3 times and pick the minimum running time. Then, average the 3 minimum running time of the 3 different permutations. This average running time is running time of the algorithm for its current problem size.

***NOTE***: To prevent external process affect the result of experiments, pick the minimum running time of each permutation and average minimum running times of different permutations.

Shell sort and annealing sort are tested using different sequences. The best two sequences of annealing sort and shell sort will be shown in the graph with other sorting algorithms. All of the sequences of shell sort and annealing sort will be shown separately.

Result of running time experiments will be ploted on a log-log scale. In this case, comparing the slope of the line can find which sorting algorithm is the fastest.

Regression analysis will also be performed on the results of running time experiments.

## **Testing Results**

### Uniformly distributed permutations

### Almost-sorted permutations

## **Conclusion**