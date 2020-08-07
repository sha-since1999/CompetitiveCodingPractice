#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node *next;
    int val;
    int col;
};

class sparseMtrix
{
private:
    node **sparse;
    int roww;
    int column;

public:
    sparseMtrix(int n = 3, int m = 3)
    {

        sparse = new node *[n];
        for (int i = 0; i < n; i++)
            sparse[i] = NULL;
        roww = n;
        column = m;
    }
    void create(int r, int c, int v);
    void display();
};
void sparseMtrix::create(int r, int c, int v)
{

    node *temp = new node;
    temp->col = c;
    temp->val = v;
    temp->next = NULL;
    if (sparse[r] == NULL)
    {
        sparse[r] = temp;
    }
    else
    {
        node *tpt, *ptr = sparse[r];
        while (ptr->next != NULL)
        {

            tpt = ptr;
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void sparseMtrix::display()
{
    for (int i = 0; i < roww; i++)
    {
        for (int j = 0; j < column; j++)
        {
            int data = 0;
            if (sparse[i])
            {
                node *temp = sparse[i];
                while (temp)
                {
                    if (temp->col == j)
                    {
                        data = temp->val;
                        break;
                    }
                    temp = temp->next;
                }
            }
            cout << data << " ";
        }
        cout << endl;
    }
}

void sahu()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
}
int main()
{
    // sahu();
    cout << "Enter the No.of rows in sparse matrix:" << endl;
    int maxrow, maxcol, row, col, val;
    cin >> maxrow >> maxcol;
    sparseMtrix spr(maxrow, maxcol);
    cout << "enter the no of NON zero element in the matrix" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> row >> col >> val;
        spr.create(row, col, val);
    }
    spr.display();
    // cout << "Enter the  ROW:COL  to sea the data of sparse matrix:" cin >> row >> col >> val;
    // spr.display(row, col);

    return 0;
}