#include<bits/stdc++.h>
#include "input.h"
using namespace std;
int getMinDiceThrows (int * moves, int n){
    vector<int> vis(n+1,0);
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0]=1;
    while(!q.empty()){
        auto [x,d] = q.front();
        if(x==n-1) break;
        q.pop();
        for( int i= x+1;i<=x+6 and x<n;i++){
            if(!vis[i]){
                if(moves[i]!=-1) 
                    q.push({moves[i],d+1});
                else
                    q.push({i,d+1});

                vis[i]=1;
            }
        }

    }
return q.front().second;
}
int main()
{
    // Let us construct the board given in above diagram
    int N = 30;
    int moves[N];
    for (int i = 0; i < N; i++)
        moves[i] = -1;

    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout << "Min Dice throws required is " << getMinDiceThrows(moves, N);
    return 0;
}