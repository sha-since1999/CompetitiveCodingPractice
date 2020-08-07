#include <iostream>
using namespace std;
typedef long long ll;
int guess(char);
int determineGraderStratgy(void);
int stratgy;
char tempch;
char ch = 'L';
static ll N;
int main()
{
  cin >> N;
  if (N == 0)
    exit(0);
  int stratgy = determineGraderStratgy();
  cout << N << endl;
  cin >> ch;
  if (ch == 'E')
    exit(0);
  cout << N << endl;
  cin >> tempch;
  ch = 'L';

  while (ch != 'E')
  {
    if (stratgy == 1) //truelly answer in first tym
    {
      cout << guess(ch) << endl;
      cin >> ch;
    }
    else if (stratgy == 0) //truelly ans in second tym
    {
      cout << guess('X') << endl;
      cin >> tempch;
      cout << guess(ch) << endl;
      cin >> ch;
    }
    else
    {
      cout << "stratgy not determined" << endl;
      exit(0);
    }
  }

  return -1;
}

int determineGraderStratgy(void) // to find grader stratgy even true or odd
{
  char ch[5];
  int i = 4;
  while (i)
  {
    cout << 1 << endl;
    cin >> ch[i];
    if (ch[i] == 'E')
      exit(0);
    i--;
  }

  if (ch[4] == 'L' && ch[3] == 'G')
    return 0; //lie rply in in first tym
  else if (ch[4] == 'G' && ch[3] == 'L')
    return 1; //ture rply in first tym
  return -1;
}

int guess(char ch)
{
  static ll upper = N;
  static ll lower = 1;
  static ll mid = N;
  if (ch == 'X')
    return mid;
  if (ch == 'L')
  {
    upper = mid;
    mid = (upper - lower + 1) / 2;
    return mid;
  }
  else
  {
    lower = mid;
    mid = mid + (upper - lower) / 2;
    return mid;
  }
  return -1;
}