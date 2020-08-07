#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int genrateSumOfIfectedPeople(int key, int x1, int y1, int x2, int y2, int *covid_matrix[N + 1])
{
    int sum = 0;
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            if (key == -1)
                cout << covid_matrix[i][j];
            if (covid_matrix[i][j] == key)
                sum++;
        }
        cout << endl;
    }
    if (key == 1)
        return sum;
    return 0;
}

int main()
{
    int T = 0;
    while (T--)
    {
        long N;
        long P;
        long key;
        int r1, c1, r2, c2;
        cin >> N, P;
        int is_corona_postive = ((rand() % 100) < P) ? 1 : 0;
        int covid_matrix = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                covid_matrix[i][j] = is_corona_postive;
            }
        }
        while (key = 2)
            cin >> key >> r1 >> c1 >> r2 >> c2;
        if (r1 < 1 && r2 > N && c1 < 1 && c2 > N)

            cout << genrateSumOfIfectedPeople(key, r1, c1, r2, c2, covid_matrix) << endl; //show the no of infected people in  given matrix
        else
        {
            cout << -1 << endl;
        }

        // if (key == 2)
        //     genrateSumOfIfectedPeople(-1, r1, c1, r2, c2, covid_matrix);

        // int theyKnow = key;
        // cin >> theyKnow;
        if (key == 2)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    cout << covid_matrix[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}