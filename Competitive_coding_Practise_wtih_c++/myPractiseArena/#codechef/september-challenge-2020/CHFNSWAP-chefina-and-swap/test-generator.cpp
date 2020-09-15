#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

minstd_rand rng(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
T randint(T a, T b) { return uniform_int_distribution<T>(a, b)(rng); }
template <typename T>
T uniform(T a, T b) { return uniform_real_distribution<T>(a, b)(rng); }

int main()
{
    // sahu();
    int t = randint<int>(1, 1000000);
    cout << t << endl;
    while (t--)
    {
        long long x = uniform<long long>(1, 1000000000);
        cout << x << endl;
    }

    return 0;
}
