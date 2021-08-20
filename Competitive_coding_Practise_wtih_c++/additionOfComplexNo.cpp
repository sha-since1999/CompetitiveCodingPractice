#include <bits/stdc++.h>
#include "input.h"
using namespace std;
typedef struct complex
{
    int r;
    int i;
} comp;
comp operator+(comp &first, comp &second)
{

    comp res;
    res.r = first.r + second.r;
    res.i = first.i + second.i;
    return res;
}

int main()
{
    comp first = {3, 5}, second = {5, 4}, ans;
    ans = first + second;

    cout << ans.r << "+ i" << ans.i << endl;

    return 0;
}
