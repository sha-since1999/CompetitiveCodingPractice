#include <iostream>
using namespace std;

int chefmoneycounter(long moneyPay, int *chefcoinType)
{
    if (moneyPay == 5)
    {
        chefcoinType[0]++;

        return 1;
    }
    if (moneyPay == 15)
    {
        if (chefcoinType[1] > 0)
        {
            chefcoinType[1]--;
            return 1;
        }
        else if (chefcoinType[0] > 1)
        {
            chefcoinType[0] = chefcoinType[0] - 2;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (moneyPay == 10)
    {

        if (chefcoinType[0] > 0)
        {
            chefcoinType[0]--;
            chefcoinType[1]++;
            return 1;
        }
    }

    return 0;
}
int can_serve(long *manHaveCoin, long N, int *chefcoinType)
{
    int x = 78;
    long i = 0;

    while (N--)
    {

        x = chefmoneycounter(manHaveCoin[i++], chefcoinType);
        cout << x;
        if (!x)
            return 0;
    }
    return 1;
}

int main()
{
    long T = 0;

    cin >> T;
    while (T--)
    {
        long i = 0;
        int chefcoinType[] = {0, 0, 0};

        long N = 0;
        cin >> N;
        long check = N;
        long manHaveCoin[N + 1];
        while (check--)
        {
            cin >> manHaveCoin[i++];
        }
        if (manHaveCoin[0] > 5)
        {
            cout << "NO";
        }
        else
        {
            can_serve(manHaveCoin, N, chefcoinType) ? cout << "YES" : cout << "NO";
        }
        cout << endl;
    }

    return 0;
}