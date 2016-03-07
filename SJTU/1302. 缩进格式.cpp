//以表格的形式存储文本，每行每列存放一个单词，确定每一列最大宽度即可
//istringstream、getline、cout格式控制

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

void process();

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		process();
	//system("pause");
	return 0;
}

void process()
{
	vector<vector<string> > text;
	string input;
	size_t max_col = 0;

	getline(cin, input);
	while (input != "@")
	{
		vector<string> words;
		istringstream iss(input);
		while (iss)
		{
			string word;
			iss >> word;
			words.push_back(word);
		}
		max_col = max(words.size(), max_col);
		text.push_back(words);
		getline(cin, input);
	}
	vector<size_t> maxLen(max_col, 0);
	for (size_t i = 0; i < max_col; i++)
	{
		for (size_t j = 0; j < text.size(); j++)
		{
			if (text[j].size() <= i)
				continue;
			else
				maxLen[i] = max(maxLen[i], text[j][i].length());
		}
	}

	cout.flags(ios::left);

	for (size_t i = 0; i < text.size(); i++)
	{
		for (size_t j = 0; j < text[i].size(); j++)
		{
			cout << setw(maxLen[j]) << text[i][j];
			if (j != text[i].size() - 1)
				cout << " ";
		}
		cout << endl;
	}
}
