#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "sort.cpp"

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
    random_shuffle(vec.begin(), vec.end());
    return vec;
}

// run and time sort for vector with n elements. return vector of timings with sizes and seconds
timing time_sort(int n, int reps)
{
    double total_time = 0.0;
    vector<int> rvec;
    for(int i = 0; i < reps; i++)
    {
        rvec = get_random_shuffled_int_vector(n);
        clock_t c_start = clock();
        bubble_sort(rvec);
        clock_t c_end = clock();
        total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
    }
    timing t;
    t.n = n;
    t.seconds = (float)total_time/reps;
    return t;
}

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
    create_empty_timings_file("timings.csv");
    timing t;
    for(int n = 10; n <= 10000000; n *= 10)
    {
        t = time_sort(n, 3);
        add_timings_to_file("bubble-sort", t, "timings.csv");
    }
}