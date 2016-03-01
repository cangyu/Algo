//如果顺着正向思路来，一步步模拟，在新方法中考虑每一组的最小值，再一步步减去，很麻烦
//换个角度，从整体考虑，用加法

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void calcOld(int n, const vector<long long> &cost, long long &totalTime, long long &finalTime);
void calcNew(int n, const vector<long long> &cost, long long &totalTime, long long &finalTime);
inline int getMinIndex(const long long t[], int len);

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	vector<long long> cost(n);
	for (int i = 0; i < n; i++)
		cin >> cost[i];

	long long old_SumOfTotal = 0, old_TimeOfFinal = 0;
	long long  new_SumOfTotal = 0, new_TimeOfFinal = 0;

	calcOld(n, cost, old_SumOfTotal, old_TimeOfFinal);
	calcNew(n, cost, new_SumOfTotal, new_TimeOfFinal);

	cout << old_SumOfTotal << ' ' << old_TimeOfFinal << endl;
	cout << new_SumOfTotal << ' ' << new_TimeOfFinal << endl;

	//system("pause");
	return 0;
}

void calcOld(int n, const vector<long long> &cost, long long &totalTime, long long &finalTime)
{
	long long t[3] = { 0 };
	long long f[3] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < n; j += 3)
		{
			f[i] += t[i];
			t[i] += cost[j];
		}
	}
	finalTime = 0;
	for (int i = 0; i < 3; i++)
	{
		totalTime += f[i];
		finalTime = max(finalTime, t[i]);
	}
}

void calcNew(int n, const vector<long long> &cost, long long &totalTime, long long &finalTime)
{
	long long t[3] = { 0 };
	long long f = 0;

	for (int i = 0; i < n; i++)
	{
		int j = getMinIndex(t, 3);
		f += t[j];
		t[j] += cost[i];
	}

	totalTime = f;
	finalTime = max(t[0], max(t[1], t[2]));
}

inline int getMinIndex(const long long t[], int len)
{
	if (len < 0)
		throw "Invalid parameter of length";

	long long curMin = t[0];
	int curMinIndex = 0;
	for (int i = 1; i < len; i++)
	{
		if (t[i] < curMin)
		{
			curMin = t[i];
			curMinIndex = i;
		}
	}
	return curMinIndex;
}