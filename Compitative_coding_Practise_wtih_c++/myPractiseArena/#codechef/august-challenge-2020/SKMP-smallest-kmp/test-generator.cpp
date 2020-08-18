#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

minstd_rand rng(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T> T randint(T a, T b) { return uniform_int_distribution<T>(a, b)(rng); }
template <typename T> T uniform(T a, T b) { return uniform_real_distribution<T>(a, b)(rng); }

// 💻 Here in test-generator.cpp, write code that prints one random test input with cout/printf. 💻
// 💡 Then, press Alt+F9 to have ICIE automatically test your solution on thousands of tests! 💡
// 😕 How to randomize a dice roll: int dice = randint<int>(1, 6); 😕
// 😕 How to randomize a probability: double probability = uniform<double>(0., 1.); 😕

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

}
