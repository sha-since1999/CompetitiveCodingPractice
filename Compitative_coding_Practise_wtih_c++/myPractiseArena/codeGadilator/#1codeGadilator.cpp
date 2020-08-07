
#include <iostream>
using namespace std;

long long maxgirl(long long requireIngredien[], long long quantityOfIngredient[], long long n)
{
	long long count = 0;
	long long j;
	while (1)
	{
		for (j = 0; j < n; j++)
		{
			if (quantityOfIngredient[j] >= requireIngredien[j])
			{
				quantityOfIngredient[j] -= requireIngredien[j];
			}
			else
			{
				break;
			}
		}
		count++;
	}
	return count;
}

int main()
{
	long long N;
	cout << "hello" << endl;
	cin >> N;
	long long requireIngredien[N];
	long long quantityOfIngredient[N];

	for (long long i = 0; i < N; i++)
	{
		cin >> requireIngredien[i];
		cout << "first";
	}
	for (long long i = 0; i < N; i++)
	{
		cin >> quantityOfIngredient[i];
		cout << "second";
	}

cout << maxgirl(requireIngredien, quantityOfIngredient, N) << endl;

return 0;
}