#include <bits/stdc++.h>
using namespace std;
bool isSameBST(vector<int> A, vector<int> B)
{
    int n = A.size(), m = B.size();
    if (!n and !m)
        return true;
    else if (n != m)
        return false;
    else if (A[0] != B[0])
        return false;

    vector<int> AL, AR, BL, BR;
    for (int i = 1; i < n; i++)
    {
        if (A[i] > A[0])
            AR.push_back(A[i]);
        else
            AL.push_back(A[i]);
    }
    for (int i = 1; i < m; i++)
    {
        if (B[i] > B[0])
            BR.push_back(B[i]);
        else
            BL.push_back(B[i]);
    }

    return isSameBST(AL, BL) and isSameBST(AR,BR);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> BST1 = {10,15,8,12,94,81,5,2,11};
    vector<int> BST2 = {10,8,5,15,2,12,11,94,81};
    cout << isSameBST(BST1, BST2) << endl;
    return 0;
}