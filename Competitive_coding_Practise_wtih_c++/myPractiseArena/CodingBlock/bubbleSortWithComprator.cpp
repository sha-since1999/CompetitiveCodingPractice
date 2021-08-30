#include <bits/stdc++.h>

using namespace std;
bool comparator(int a, int b)
{
    return a > b;
}
void bubbleSort(int *a, int n, bool (&comparator)(int a, int b))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)

        {
            if (comparator(a[j], a[j + 1]))
                swap(a[j], a[j + 1]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    int a[n], t = n, i = 0;
    while (t--)
        cin >> a[i++];

    bubbleSort(a, n, comparator);

    while (t++ != n - 1)
        cout << a[t] << " ";

    return 0;
}