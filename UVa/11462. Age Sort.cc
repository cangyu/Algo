#include <iostream>
#include <cstring>

using namespace std;

const int N = 100;

int n = 0, age[N + 5];

 int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	
	while(cin>>n && n!=0)
	{
		int x = 0;
		memset(age, 0, sizeof(age));
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			++age[x];
		}

		int i = 1;
		for(;i<=100;i++)
			if (age[i] != 0)
			{
				cout << i;
				--age[i];
				break;
			}

		for (; i <= 100; i++)
			for (int j = 0; j < age[i]; j++)
				cout << " " << i;

		cout << endl;
	}
	return 0;
}
