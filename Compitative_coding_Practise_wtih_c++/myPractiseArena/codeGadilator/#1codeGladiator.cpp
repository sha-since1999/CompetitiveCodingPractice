#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ull i;
    ull N;
    cin >> N;
    ull quantity_of_ingredient_required[N + 1];
    ull having_ingredeint_quantity_array[N + 1];
    for (i = 0; i < N; i++)
        cin >> quantity_of_ingredient_required[i];

    for (i = 0; i < N; i++)
        cin >> having_ingredeint_quantity_array[i];
    int flag = 1;
    ll max_powerfull_girls = 0;
    while (flag)
    {
        for (i = 0; i < N; i++)
        {
            if (quantity_of_ingredient_required[i] > having_ingredeint_quantity_array[i])
            {
                flag = 0;
                cout << max_powerfull_girls << endl;
                break;
            }

            having_ingredeint_quantity_array[i] =having_ingredeint_quantity_array[i] -quantity_of_ingredient_required[i];
        }
        max_powerfull_girls++;
    }

    
    return 0;
}




















