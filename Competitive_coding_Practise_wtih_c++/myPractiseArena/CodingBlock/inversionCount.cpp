#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

int main()
{

    int a[] = {1, 5, 2, 3, 6, 4, 10};
    int n = sizeof(a) / sizeof(a[0]);
    PBDS st;
    int sum = 0;
    for (int x : a)
    {
        sum += st.order_of_key(x);
        st.insert(x);
    }
    cout << sum << endl;
    return 0;
}

//inversion : if i<j the a[i]> a[j];  count all such pair