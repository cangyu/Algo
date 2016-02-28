//数据格式的设计，注意scanf的空格

#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>

using namespace std;

const int NbrOfPrizes = 5;

typedef struct{
	char name[20];
	int gpa;
	int class_credit;
	bool isClassRepresentative;
	bool isWest;
	int papaerNbr;
	int scholarship;
} StudentTypeDef, *pStudentTypeDef;

typedef struct{
	bool(*awardJudge) (StudentTypeDef *);
	int reward;
} PrizeTypeDef, *pPrizeTypeDef;

bool canGetYuanshiPrize(StudentTypeDef *student)
{
	if ((*student).gpa > 80 && (*student).papaerNbr >= 1)
		return true;
	else
		return false;
}

bool canGetWusiPrize(StudentTypeDef *student)
{
	if ((*student).gpa > 85 && (*student).class_credit > 80)
		return true;
	else
		return false;
}

bool canGetChenjiyouxiuPrize(StudentTypeDef *student)
{
	if ((*student).gpa > 90)
		return true;
	else
		return false;
}

bool canGetXibuPrize(StudentTypeDef *student)
{
	if ((*student).gpa > 85 && (*student).isWest)
		return true;
	else
		return false;
}

bool canGetBanjigongxianPrize(StudentTypeDef *student)
{
	if ((*student).class_credit > 80 && (*student).isClassRepresentative)
		return true;
	else
		return false;
}

PrizeTypeDef availablePrizes[NbrOfPrizes] =
{
	{ canGetYuanshiPrize, 8000 },
	{ canGetWusiPrize, 4000 },
	{ canGetChenjiyouxiuPrize, 2000 },
	{ canGetXibuPrize, 1000 },
	{ canGetBanjigongxianPrize, 850 }
};

void calcScholarship(StudentTypeDef * students, int n)
{
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		for (int j = 0; j < NbrOfPrizes; j++)
		{
			if ((*availablePrizes[j].awardJudge)(students + i))
				tmp += availablePrizes[j].reward;
		}
		students[i].scholarship = tmp;
	}
}

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	StudentTypeDef candidates[100];
	for (int i = 0; i < n; i++)
	{
		scanf("%s ", &candidates[i].name);
		scanf("%d ", &candidates[i].gpa);
		scanf("%d ", &candidates[i].class_credit);
		char t;
		scanf("%c ", &t);
		candidates[i].isClassRepresentative = (t == 'Y');
		scanf("%c ", &t);
		candidates[i].isWest = (t == 'Y');
		scanf("%d", &candidates[i].papaerNbr);
	}
	calcScholarship(candidates, n);
	int total = 0, max = -1, honorID = -1;
	for (int i = 0; i < n; i++)
	{
		total += candidates[i].scholarship;
		if (candidates[i].scholarship > max)
		{
			max = candidates[i].scholarship;
			honorID = i;
		}
	}
	printf("%s\n%d\n%d", candidates[honorID].name, max, total);

	//system("pause");
}
