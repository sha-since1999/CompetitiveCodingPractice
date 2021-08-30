#include <bits/stdc++.h>
#include "input.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[] = {1, 2, 4, 5, 6, 7};
    int *b = a;
    b = b + 2;
    cout << b[0] << endl;
    // it will return  4 rem this concept

    return 0;
}