#include <bits/stdc++.h>
using namespace std;

/*this is seive eratosthenes function to find prime  best till 10^5*/
void seive(int M, int N)
{
    vector<bool> isPrime(N + 1, true);
     for (int i = 2; i * i <= N; i++)
        if (isPrime[i])
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
    for (int i = M; i <= N; i++)
        if (isPrime[i])
            cout << i << " ";
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int M, N;
        cin >> M >> N;
        seive(M, N);
    }
    return 0;
}