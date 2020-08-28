#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

  string s;
  cin >> s;

  ll n = s.length();

  vector<ll> v[26];

  for (ll i = 0; i < n; i++)
    v[s[i] - 'a'].push_back(i);

  ll dist = 0;

  for (int i = 0; i < 26; i++)
  {
    ll n = v[i].size();

    if (n == 1 || n == 0)
    {
    }
    else if (n == 2)
    {
      dist += v[i][1] - v[i][0];
    }
    else
    {

      sort(v[i].begin(), v[i].end());

      for (ll j = n - 1; j >= 0; j--)
        dist += j * v[i][j] - (n - 1 - j) * v[i][j];
    }
  }

  cout << dist << "\n";
  return 0;
