#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <float.h>
#include <functional>
#include "bubble_sort.cpp"
#include "insertion_sort.cpp"
#include "spin_the_bottle_sort.cpp"
#include "shell_sort.cpp"
#include "annealing_sort.cpp"
#include "random_generation_sample.cpp"

using namespace std;

struct timing 
{
    int n;
    double seconds;
};

// get a vector of ints in 1, 2, ... , n shuffled randomly
vector<int> get_random_shuffled_int_vector(int n)
{
    vector<int> vec = vector<int>(n);
    for(int i = 0; i < n; i++)
        vec[i] = (i + 1);
    shuffle_vector(vec);
    // almost_sorted_vector(vec); // Use this line to generate almost sorted array
    return vec;
}

// run and time sort for vector with n elements. return vector of timings with sizes and seconds
timing time_sort(int n, int reps, function<void(vector<int>&)> sort_algorithm)
{
    double total_time = 0.0;
    vector<int> rvec;
    for(int i = 0; i < reps; i++) // For each input size, do "reps" times runs.
    {
        rvec = get_random_shuffled_int_vector(n);
        double min_timing = DBL_MAX;
        for (int j = 0; j < 1; j++) { // For each input vector, do 3 runs and take the smallest timing.
            clock_t c_start = clock();
            sort_algorithm(rvec);
            clock_t c_end = clock();

            double curr_timing = (float)(c_end - c_start) / CLOCKS_PER_SEC;
            if (curr_timing < min_timing) {
                min_timing = curr_timing;
            }
        }  
        total_time += min_timing;
    }
    timing t;
    t.n = n;
    t.seconds = (float)total_time/reps;  // Average minimum running time of each size
    return t;
}

timing time_shell_sort(int n, int reps, const std::vector<int>& gaps)
{
    double total_time = 0.0;
    vector<int> rvec;
    for(int i = 0; i < reps; i++)
    {
        rvec = get_random_shuffled_int_vector(n);
        double min_timing = DBL_MAX;
        for (int j = 0; j < 1; j++) { // For each input vector, do 3 runs and take the smallest timing.
            clock_t c_start = clock();
            shell_sort(rvec, gaps);
            clock_t c_end = clock();

            double curr_timing = (float)(c_end - c_start) / CLOCKS_PER_SEC;
            if (curr_timing < min_timing) {
                min_timing = curr_timing;
            }
        }  
        total_time += min_timing;
    }
    timing t;
    t.n = n;
    t.seconds = (float)total_time/reps;
    return t;
}

// timing time_annealing_sort(int n, int reps, const std::vector<int>& temps, const std::vector<int>& repetitions)
// {
//     double total_time = 0.0;
//     vector<int> rvec;
//     for(int i = 0; i < reps; i++)
//     {
//         rvec = get_random_shuffled_int_vector(n);
//         double min_timing = DBL_MAX;
//         for (int j = 0; j < 1; j++) { // For each input vector, do 3 runs and take the smallest timing.
//             clock_t c_start = clock();
//             annealing_sort(rvec, temps, repetitions);
//             clock_t c_end = clock();

//             double curr_timing = (float)(c_end - c_start) / CLOCKS_PER_SEC;
//             if (curr_timing < min_timing) {
//                 min_timing = curr_timing;
//             }
//         }  
//         total_time += min_timing;
//     }
//     timing t;
//     t.n = n;
//     t.seconds = (float)total_time/reps;
//     return t;
// }

// create/truncate a file with chosen filename. insert csv header "funcname,n,seconds"
void create_empty_timings_file(string filename)
{
    ofstream f;
    f.open(filename, ios::trunc);
    f << "funcname,n,seconds\n";
    f.close();
}

// append timings data in csv format to a file with no header. (header should be created first)
void add_timings_to_file(string funcname, timing t, string filename)
{
    ofstream f;
    f.open(filename, ios::app);
    f << funcname << "," << t.n << "," << t.seconds << "\n";
    f.close();
}

int main()
{
    timing t;
    const vector<int>& gaps1{1501, 701, 301, 132, 57, 23, 10, 4, 1};
    const vector<int>& gaps2{1200, 900, 281, 77, 23, 8, 1};
    // const vector<int>& temps1;
    // const vector<int>& temps2;
    // const vector<int>& repetitions1;
    // const vector<int>& repetitions2;

    create_empty_timings_file("shell1.csv");
    for(int n = 10; n <= 1000000; n *= 10)
    {
        t = time_shell_sort(n, 3, gaps1);
        add_timings_to_file("shell-sort(gaps1)", t, "shell1.csv");
    }

    create_empty_timings_file("shell2.csv");
    for(int n = 10; n <= 1000000; n *= 10)
    {
        t = time_shell_sort(n, 3, gaps2);
        add_timings_to_file("shell-sort(gaps2)", t, "shell2.csv");
    }

    create_empty_timings_file("insertion.csv");
    for(int n = 10; n <= 100000; n *= 10)
    {
        t = time_sort(n, 3, insertion_sort);
        add_timings_to_file("insertion-sort", t, "insertion.csv");
    }
    
    create_empty_timings_file("bubble.csv");
    for(int n = 10; n <= 100000; n *= 10)
    {
        t = time_sort(n, 3, bubble_sort);
        add_timings_to_file("bubble-sort", t, "bubble.csv");
    }

    create_empty_timings_file("spin.csv");
    for(int n = 10; n <= 100000; n *= 10)
    {
        t = time_sort(n, 3, spin_the_bottle_sort);
        add_timings_to_file("spin-the-bottle-sort", t, "spin.csv");
    }

    // TODO:
    // create_empty_timings_file("annealing1.csv");
    // for(int n = 10; n <= 10000; n *= 10)
    // {
    //     t = time_annealing_sort(n, 3, temps1, repetitions1);
    //     add_timings_to_file("annealing-sort(temps1, reps1", t, "annealing1.csv");
    // }

    // create_empty_timings_file("annealing2.csv");
    // for(int n = 10; n <= 10000; n *= 10)
    // {
    //     t = time_annealing_sort(n, 3, temps2, repetitions2);
    //     add_timings_to_file("annealing-sort(temps2, reps2", t, "annealing2.csv");
    // }
}