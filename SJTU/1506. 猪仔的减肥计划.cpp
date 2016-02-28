//来去一起考虑

#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
	int M, T, U, F, D;
	char S[100000];
	cin >> M >> T >> U >> F >> D;
	for (int i = 0; i < T; i++)
		cin >> S[i];

	int cnt = 0;
	for (int i = 0; i < T; i++)
	{
		if (S[i] == 'u' || S[i] == 'd')
			M -= (U + D);
		else
			M -= (2 * F);

		if (M >= 0)
			cnt++;
		else
			break;
	}
	cout << cnt;

	//system("pause");
}
