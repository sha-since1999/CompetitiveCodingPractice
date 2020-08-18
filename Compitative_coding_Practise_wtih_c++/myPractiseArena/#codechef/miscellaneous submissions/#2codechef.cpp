#include <iostream>
using namespace std;

long long i, j;
long long T;
long long N;
int main()
{

    cin >> T;
    int x = 0;
    while (T--)
    {
        cin >> N;
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {

                if (N % 2 != 0)
                    cout << N * (i - 1) + j << " ";
                else
                {
                    i % 2 != 0 ? cout << N * (i - 1) + j << " " : cout << (N*i)-j+1<< " ";
                }
            }

            cout << endl;
        }
    }
    return 0;
}
