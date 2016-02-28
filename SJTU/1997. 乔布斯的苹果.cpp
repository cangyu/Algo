//注意在同等误差时重量的选择

#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char **argv)
{
	int N, W;
	cin >> N >> W;
	int apples[1000] = { 0 };
	int error = W, mostSuitableIndex = -1, mostSuitableWeight = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> apples[i];

		int new_error = abs(W - apples[i]);
		if (new_error < error)
		{
			error = new_error;
			mostSuitableWeight = apples[i];
			mostSuitableIndex = i;
		}
		else if (new_error == error)
		{
			if (apples[i] > mostSuitableWeight)
			{
				mostSuitableWeight = apples[i];
				mostSuitableIndex = i;
			}
		}
	}

	cout << apples[mostSuitableIndex];

	//system("pause");
}
