
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
// #include "sahu.h"
// #include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int T;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;

    while (T--)
    {
        bool flag = 0;
        ll N, temp;
        vector<ll> A;
        vector<ll> B;
        cin >> N;
        ll total_cost = 0;
        ll sum = 0;
        ll mn = INT64_MAX - 1;
        unordered_map<int, int> mp, np, check;
        map<int, int> fr;
        vector<int> cv;
        for (ll i = 0; i < N; i++)
        {
            cin >> temp;
            A.push_back(temp);
            mp[temp]++;
            check[temp]++;
            mn = min(mn, temp);
        }
        for (ll j = 0; j < N; j++)
        {
            cin >> temp;
            B.push_back(temp);
            np[temp]++;
            check[temp]++;
            mn = min(mn, temp);
        }

        for (auto m : check)
            if ((m.second % 2) != 0)
                flag = 1;

        if (!flag)
        {
            ll i = 0;
            int swapdone = 0;
            int swapcount = 0;
            for (auto m : mp)
            {
                if (m.first >= mn && m.first < (2 * mn))
                    fr[m.first] = abs(np[m.first] - mp[m.first]) / 2;
            }
            for (auto m : np)
            {
                if (m.first >= mn && m.first < (2 * mn))
                {
                    fr[m.first] = abs(np[m.first] - mp[m.first]) / 2;
                    // cout << m.first << endl;
                }
            }
            for (auto f : fr)
            {
                if (f.second > 0)
                {
                    total_cost += abs(f.first) * f.second;
                    swapdone += f.second;
                    // cout << f.second << "sec" << endl;
                    int temp = f.second;
                    while (temp--)
                        cv.push_back(f.first);
                }
            }

            sort(A.begin(), A.end(),greater<int>());
            sort(B.begin(), B.end(),greater<int>());

            while (i < A.size())
            {
                if (A[i] == B[i])
                    i++;
                else
                {
                    if (A[i] == A[i + 1] && np[A[i]] != mp[A[i]])
                    {
                        swapcount++;
                        i = i + 2;
                    }
                    else
                        i++;
                }
            }
            if (swapcount < swapdone)
            {
                int cnt = 0;
                total_cost = 0;
                while (cnt<swapcount)
                    total_cost += cv[cnt++];
                //  cout << cv[cnt] << "--";
                swapdone = swapcount = 0;
            }

            total_cost += abs(swapcount - swapdone) * 2 * mn;
        }
        flag ? cout << -1 << endl : cout << total_cost << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
// #include <bits/stdc++.h>
#include <map>
using namespace std;
typedef long long int ll;
void swap(ll *a, ll *b)
{
    // cout << *a << "swap" << *b << endl;
    ll temp = *a;
    *a = *b;
    *b = temp;
}
int T;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;

    while (T--)
    {
        int flag = 0;
        ll N, temp;
        vector<ll> A;
        vector<ll> B;
        cin >> N;
        ll total_cost = 0;
        map<int, int> mp;
        for (ll i = 0; i < N; i++)
        {
            cin >> temp;
            A.push_back(temp);
            mp[temp]++;
        }
        for (ll j = 0; j < N; j++)
        {
            cin >> temp;
            B.push_back(temp);
            mp[temp]++;
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for (auto m : mp)
            if ((m.second % 2) != 0)
            {
                flag = 1;
                break;
            }
        ll i = 0;
        ll j = B.size() - 1;
        ll x = 0;
        ll y = 0;
        if (!flag)
        {
            while (i < A.size())
            {
                if (A[i] == B[i])
                    i++;
                else
                {
                    if (A[i] == A[i + 1])
                    {
                        while (B[j] != B[j - 1] && j >= 0)
                            j--;

                        ll Asmall = min(B[i], A[x]) + min(A[x], A[i + 1]);
                        ll Bsmall = min(B[x], B[i]) + min(B[x], A[i + 1]);

                        if (((Asmall >= min(A[i], B[j])) && (Asmall <= Bsmall)) || ((Bsmall >= min(A[i], B[j])) && (Asmall >= Bsmall)))
                        {
                            if (x == i)
                                x++;

                            swap(&A[i], &B[j]);
                            total_cost += min(A[i], B[j]);
                            i = i + 2;
                            j = j - 2;
                        }
                        else if ((Asmall < min(A[i], B[j])) && (Asmall <= Bsmall))
                        {

                            swap(&A[x], &B[i]);
                            total_cost += min(A[x], B[i]);

                            swap(&A[i + 1], &B[i]);
                            total_cost += min(A[i + 1], B[i]);
                            x = i + 1;
                            i = i + 2;
                        }
                        else if ((Bsmall < min(A[i], B[j])) && (Asmall > Bsmall))
                        {

                            swap(&A[i], &B[y]);
                            total_cost += min(A[i], B[y]);

                            swap(&B[i + 1], &A[i]);
                            total_cost += min(A[i + 1], A[i]);
                            y = i + 1;
                            i = i + 2;
                        }
                    }
                }
            }
        }
        flag ? cout << -1 << endl : cout << total_cost << endl;
    }

    return 0;
}



#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
// #include "sahu.h"
// #include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int T;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;

    while (T--)
    {
        bool flag = 0;
        int N, temp;
        vector<ll> A;
        vector<ll> B;
        cin >> N;
        ll total_cost = 0;
        int mn = 1000000000;
        unordered_map<int, int> mp;
        vector<int> v1;
        vector<int> v2;
        for (ll i = 0; i < N; i++)
        {
            cin >> temp;
            A.push_back(temp);
            mp[temp]++;
            mn = min(mn, temp);
        }
        for (ll j = 0; j < N; j++)
        {
            cin >> temp;
            B.push_back(temp);
            mp[temp]++;
            mn = min(mn, temp);
        }
        for (auto m : mp)
            if ((m.second % 2) != 0)
                flag = 1;
            else
                mp[m.first] /= 2;

        if (!flag)
        {
            for (int i = 0; i < N; i++)
            {
                if (count(A.begin(), A.end(), A[i]) != mp[A[i]])
                {
                    v1.push_back(A[i]);
                    //   A.erase(remove(A.begin(), A.end(), val), A.end());
                }

                if (count(B.begin(), B.end(), B[i]) != mp[B[i]])
                {
                    v2.push_back(B[i]);
                    // B.erase(remove(B.begin(), B.end(), val), B.end());
                }
            }

            sort(v1.begin(), v1.end(), greater<int>());
            sort(v2.begin(), v2.end(), greater<int>());
            if (v1.size() != v2.size())
                flag = 1;
            for (ll i = 0; i < v1.size(); i++)
                total_cost += min((2 * mn), (min(v1[i], v2[i])));
            if (v1.size() == 0 || v2.size() == 0)
                total_cost = 0;
        }
        flag ? cout << -1 << endl : cout << total_cost << endl;
    }

    return 0;
}