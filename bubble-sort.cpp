#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& in) {
    // TODO: bubble sort algorithm
    int size = in.size();
    if (size > 1) {
        for (int i = 0; i < size; ++i) {
            for (int j = 1; j < size - i; ++j) {
                if (in.at(j) < in.at(j - 1)) {
                    // TODO: swap two elements
                }
            }
        }
    }
}

void printVector(vector<int> in) {
    int size = in.size();
    for (int i = 0; i < size; ++i) {
        cout << in.at(i) << ' ';
    }
}

int main() {
    vector<int> v1{8,5,6,3,4,1,2,7};
    vector<int> v2{1,2,3,4,5,6,7,8};
    bubble_sort(v1);
    printVector(v1);
    cout << "\n v1 and v2 are equal: " << (v1 == v2) << endl;
    return 0;
}