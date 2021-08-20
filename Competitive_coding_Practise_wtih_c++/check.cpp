#include <bits/stdc++.h>
using namespace std;

vector<int> Min_Jumps(int N, vector<int> A)
{
    // vector<int> leftMx(N,0),rightMx(,N,0);
    unordered_map<int, int> L, R;
    int mx = -1;
    for (int i = 0; i < N; i++)
    {
        mx = A[0];
        for (int j = i; j > 0; j--)
            if (A[j] > A[i])
            {
                mx = A[j];
                break;
            }
        L.insert({A[i], mx});
        // leftMx.push_back(mx);
    }

    for (int i = N - 1; i >= 0; i--)
    {
        mx = A[N - 1];
        for (int j = i; j < N; j++)
            if (A[j] > A[i])
            {
                mx = A[j];
                break;
            }

        R.insert({A[i], mx});
        // rightMx.push_back(mx);
    }

    unordered_map<int, int> mp;
    vector<int> V = A;
    vector<int> res;
    sort(A.begin(), A.end(), greater<int>());

    mp[A[0]] = 0;
    for (int i = 1; i < N; i++)
    {
        if (L[A[i]] > R[A[i]])
            mp[A[i]] = mp[L[A[i]]] + 1;
        else
            mp[A[i]] = mp[R[A[i]]] + 1;
        // cout<<L[A[i]]<<" " <<R[A[i]]<<endl;
    }
    for (int x : V)
    {
        res.push_back(mp[x]);
    }
    return res;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i_A = 0; i_A < N; i_A++)
        {
            cin >> A[i_A];
        }

        vector<int> out_;
        out_ = Min_Jumps(N, A);
        cout << out_[0];
        for (int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
            cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}

// try to do in O(log n)
