#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin >> T;
    while (T++)
    {
        int N;
        int j;
        int i;
        cin >> N;
        ll power[N];
        ll oponent_power[N];
        for (i = 0; i < N; i++)
            cin >> power[i];
        for (i = 0; i < N; i++)
            cin >> oponent_power[i];
        sort(power, power + N, greater<int>());
        sort(oponent_power, oponent_power + N, greater<int>());
        int count = 0;
        i = 0;
        j = 0;
        while (i <= N && j <= N)
        {

            if (power[j] > oponent_power[i])
            {

                j++;
                i++;
                count++;
            }

            else
            {
                i++;
            }
        }

        cout << count << endl;
    }
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// typedef long long int;
int winsPossibilties(vector<int> &A, vector<int> &O, int N)
{
    int count = 0;

    int i = 0, j = 0;
    while (i < A.size() && j < O.size())
    {

        if (A[i] > O[j])
        {

            i++;
            j++;
            count++;
        }
        else
        {
            j++;
        }
    }
    return count;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        int i;
        int data;
        cin >> N;
        vector<int> power;

        vector<int> oponent_power;

        for (i = 0; i < N; i++)
        {
            cin >> data;
            power.push_back(data);
        }
        for (i = 0; i < N; i++)
        {
            cin >> data;
            oponent_power.push_back(data);
        }
        // sort(power, power + N, greater<int>());
        // sort(oponent_power, oponent_power + N, greater<int>());
        sort(power.begin(), power.end(), greater<int>());
        sort(oponent_power.begin(), oponent_power.end(), greater<int>());

        cout << winsPossibilties(power, oponent_power, N) << endl;
    }
    return 0;
}