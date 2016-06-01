/*
ID: yhcy1991
PROG: lgame
LANG: C++
*/

#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long u64;

const int val[26] = { 2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7 };
const u64 id[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };

struct item
{
	char word[10];
	int score;
	u64 gene;//unique identity

	item() :gene(1), score(0) {}
};

item wordlist[40008];
int cnt = 0;

char src[10];
u64 allgene = 1;

int main(int argc, char** argv)
{
	ifstream fin("lgame.in");
	ifstream dict("lgame.dict");
	ofstream fout("lgame.out");

	fin >> src;
	for (int i = 0; src[i]; i++)
		allgene *= id[src[i] - 'a'];

	char tmpStr[10];
	u64 tmpGene;
	int tmpScore;
	dict >> tmpStr;
	while (tmpStr[0] != '.')
	{
		tmpGene = 1;
		for (int i = 0; tmpStr[i]; i++)
			tmpGene *= id[tmpStr[i] - 'a'];
		if (allgene%tmpGene == 0)
		{
			tmpScore = 0;
			for (int i= 0; tmpStr[i]; i++)
				tmpScore += val[tmpStr[i] - 'a'];
			memcpy(wordlist[cnt].word, tmpStr, 10);
			wordlist[cnt].gene = tmpGene;
			wordlist[cnt].score = tmpScore;
			++cnt;
		}
		dict >> tmpStr;
	}

	wordlist[cnt].word[0] = '\0';
	wordlist[cnt].score = 0;
	wordlist[cnt].gene = 1;
	++cnt;

	int maxScore = 0;
	for (int i = 0; i < cnt; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			u64 g = wordlist[i].gene*wordlist[j].gene;
			if (allgene%g == 0)
				maxScore = max(maxScore, wordlist[i].score + wordlist[j].score);
		}
	}

	fout << maxScore << endl;

	for (int i = 0; i < cnt; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			u64 g = wordlist[i].gene*wordlist[j].gene;
			if (allgene %g == 0 && wordlist[i].score + wordlist[j].score == maxScore)
			{
				fout << wordlist[i].word;
				if (j != cnt - 1)
					fout << " " << wordlist[j].word;
				fout << endl;
			}
		}
	}

	return 0;
}
