#include <bits/stdc++.h>
#include "sahu.h"
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (T--)
    {
        ll N;
        cin >> N;
        {
            deque<int> dq;

            for (int i = 0; i < n; i++)
            {

                if (dq.empty())
                {
                    dq.push_back(i);
                }

                if (dq.front() <= (i - k))
                {
                    dq.pop_front();
                }

                while (!dq.empty() && arr[i] >= arr[dq.back()])
                {
                    dq.pop_back();
                }

                dq.push_back(i);

                if (i >= (k - 1))
                {
                    cout << arr[dq.front()] << " ";
                }
            }
            cout << endl;
        }

        return 0;
    }