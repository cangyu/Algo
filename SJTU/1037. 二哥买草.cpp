//低质量干草的捆数可能较少，注意边界的检测

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char **argv)
{
	int n, m;
	cin >> n >> m;
	vector<int> good(n), bad(m);
	for (int i = 0; i < n; i++)
		cin >> good[i];
	for (int i = 0; i < m; i++)
		cin >> bad[i];

	sort(good.begin(), good.end());
	sort(bad.begin(), bad.end());

	int cnt = 0, startPos = 0;
	for (int i = 0; i < n; i++)
	{
		if (startPos >= m) //Be careful!
			break;

		if (good[i] > bad[startPos])
		{
			cnt++;
			startPos++;
		}
	}

	cout << cnt + n << endl;

	//system("pause");
	return 0;
}