#include <bits/stdc++.h>
#include "input.h"
using namespace std;
// ps: count pair such that i<j a[i]>2*a[j];
int merge(int *a, int low, int mid, int high)
{
    int right = mid + 1;
    // logic here
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high and a[i] > 2 * a[right])
        {
            right++;
        }
        cnt += right - (mid + 1);
    }
    // merge here
    int tmp[high + 1];
    int i = 0;
    int left = low;
    right = mid + 1;
    while (left <= mid and right <= high)
    {
        if (a[left] <= a[right])
            tmp[i++] = a[left++];
        else
            tmp[i++] = a[right++];
    }
    while (left <= mid)
    {
        tmp[i++] = a[left++];
    }
    while (right <= high)
    {
        tmp[i++] = a[right++];
    }

    for (int i = low; i <= high; i++)
    {
        a[i] = tmp[i - low];
    }
    return cnt;
}
int mergeSort(int *a, int low, int high)
{
    int ans = 0;
    if (low < high)
    {
        int mid = (high + low) / 2;
        ans += mergeSort(a, low, mid);
        ans += mergeSort(a, mid + 1, high);
        ans += merge(a, low, mid, high);
    }
    return ans;
}
int count_pair(int *a, int n)
{
    return mergeSort(a, 0, n - 1);
}
int main()
{
    int a[] = {40, 25, 19, 12, 9, 6, 2};
    int n = sizeof(a) / sizeof(a[0]);
    cout << count_pair(a, n) << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}
