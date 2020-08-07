#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sahu()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
}

vector<bool> seive(int N)
{
    vector<bool> isPrime(N + 1, true);
    for (int i = 2; i * i <= N; i++)
        if (isPrime[i])
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
    return isPrime;
}

ll fibonacy(int n1, int n2, int n)
{
    ll f[n + 1];
    f[0] = n1;
    f[1] = n2;
    for (int i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    return f[n - 1];
}
int main()
{
    // sahu();
    int intl;
    // stringstream("21920") >> intl;
    // cout << intl + 1 << endl;
    int T;
    cin >> T;
    while (T--)
    {

        vector<bool> prime_table = seive(10000);
        vector<int> firstPrimelist;
        int n1, n2;
        cin >> n1 >> n2;
        for (int j = n1; j <= n2; j++)
        {
            if (prime_table[j])
                firstPrimelist.push_back(j);
        }
        firstPrimelist.shrink_to_fit();

        unordered_map<int, bool> m;
        int data;
        int min = INT16_MAX, max = INT16_MIN;
        for (auto &&i : firstPrimelist)
        {
            for (auto &&j : firstPrimelist)
            {
                stringstream ss;
                ss << i << j;
                ss >> data;
                if (prime_table[data])
                {
                    if (!m[data])
                        m[data] = 1;
                    if (data < min)
                        min = data;
                    if (max < data)
                        max = data;
                }
            }
        }
        // for (auto &&k : m)
        //     cout << k.first << " ";
        cout << fibonacy(min, max, m.size()) << endl;
    }

    return 0;
}
