#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        int count = 1;
        for (int i = 2; i <= N; i *= 2)
            count++;
        cout << count << endl;
    }
    return 0;
}