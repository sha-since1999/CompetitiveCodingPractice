#include <bits/stdc++.h>
using namespace std;

int fun(string s)
{
    int res = 0, c = 0;
    char prev = '!';
    for (char i : s)
    {
        if (prev == i)
        {
            c++;
        }
        else
        {
            c = 1;
            prev = i;
        }
        res = max(res, c);
    }
    return res;
}
vector<int> maximum_length(int N, string S, int Q, vector<int> X, vector<char> Y)
{
    vector<int> res(Q);
    for (int k = 0; k < Q; k++)
    {
        S[X[k] - 1] = Y[k];
        res[k] = fun(S);
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
        string S;
        cin >> S;
        int Q;
        cin >> Q;
        vector<int> X(Q);
        for (int i_X = 0; i_X < Q; i_X++)
        {
            cin >> X[i_X];
        }
        vector<char> Y(Q);
        for (int i_Y = 0; i_Y < Q; i_Y++)
        {
            cin >> Y[i_Y];
        }

        vector<int> out_;
        out_ = maximum_length(N, S, Q, X, Y);
        cout << out_[0];
        for (int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
            cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}