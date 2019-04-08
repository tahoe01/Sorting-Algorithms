#include <iostream>
#include <vector>
#include <functional>
#include <random>
using namespace std;

void swap_element(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

void bubble_sort(vector<int>& in) {
    int size = in.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j < size - i; ++j) {
            if (in[j] < in[j - 1]) {
                swap_element(in[j-1], in[j]);
            }
        }
    }
}

void insertion_sort(vector<int>& in) {
    int size = in.size();
    for (int i = 1; i < size; ++i) {
        int tmp = in[i];
        int k = i;
        while (k > 0 && tmp < in[k - 1]) {
            in[k] = in[k - 1];
            --k;
        }
        in[k] = tmp;
    }
}

void spin_the_bottle_sort(vector<int>& in) {
    int size = in.size();
    default_random_engine gen;
    uniform_int_distribution<int> uniform_distribution(0,size - 1);
    while (!is_sorted(in.begin(), in.end())) {
        for (int i = 0; i < size; ++i) {
            int s = uniform_distribution(gen);
            if ((i < s && in[i] > in[s]) || (i > s && in[i] < in[s])) {
                swap_element(in[i], in[s]);
            }
        }
    } 
}

void shell_sort(vector<int>& in) {

}

void annealing_sort(vector<int>& in) {

}

void print_vector(vector<int> in) {
    int size = in.size();
    for (int i = 0; i < size; ++i) {
        cout << in[i] << ' ';
    }
}

// Get a vector of ints in 1, 2, ... , n shuffled randomly
bool test_sort(int n, function<void(vector<int>&)> sort_algorithm)
{
    vector<int> sorted = vector<int>(n);
    vector<int> unsorted = vector<int>(n);
    for(int i = 0; i < n; i++) {
        unsorted[i] = (i + 1);
        sorted[i] = (i + 1);
    }
    random_shuffle(unsorted.begin(), unsorted.end());
    sort_algorithm(unsorted);
    return sorted == unsorted;
}

// Main function for algorithm testing
int main() {
    cout << "Testing bubble sort (0):" << boolalpha << test_sort(0, bubble_sort) << endl;
    cout << "Testing bubble sort (1):" << boolalpha << test_sort(1, bubble_sort) << endl;
    cout << "Testing bubble sort (10):" << boolalpha << test_sort(10, bubble_sort) << endl;;
    cout << "Testing bubble sort (100):" << boolalpha << test_sort(100, bubble_sort) << endl;
    cout << "Testing insertion sort (0):" << boolalpha << test_sort(0, insertion_sort) << endl;
    cout << "Testing insertion sort (1):" << boolalpha << test_sort(1, insertion_sort) << endl;
    cout << "Testing insertion sort (10):" << boolalpha << test_sort(10, insertion_sort) << endl;
    cout << "Testing insertion sort (100):" << boolalpha << test_sort(100, insertion_sort) << endl;
    cout << "Testing spin the bottle sort sort (0):" << boolalpha << test_sort(0, spin_the_bottle_sort) << endl;
    cout << "Testing spin the bottle sort sort (1):" << boolalpha << test_sort(1, spin_the_bottle_sort) << endl;
    cout << "Testing spin the bottle sort sort (10):" << boolalpha << test_sort(10, spin_the_bottle_sort) << endl;
    cout << "Testing spin the bottle sort sort (100):" << boolalpha << test_sort(100, spin_the_bottle_sort) << endl;
    return 0;
}