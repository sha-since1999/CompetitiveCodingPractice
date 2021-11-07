#include <bits/stdc++.h>
#include "input.h"
using namespace std;
struct Item
{
    int v, w;
    Item(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};
bool cmp(Item a, Item b)
{
    int x = a.v / a.w;
    int y = b.v / b.w;
    return x > y;
}
int fractionalKnapsack(int W, Item *arr, int n)
{
    sort(arr, arr + n, cmp);
    int curr_w = 0, final_v = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr_w + arr[i].w <= W)
        {
            curr_w += arr[i].w;
            final_v += arr[i].v;
        }
        else
        {
            int remain_weight = W - curr_w;
            final_v += remain_weight * (arr[i].v / arr[i].w);
            break;
        }
    }
    return final_v;
}
int main()
{
    int W = 50; //    Weight of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);
    return 0;
}

// fractional knapsack is greedy approch