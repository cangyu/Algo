//二维数组的动态分配与释放
//注意换行
//做竖直交换时，可利用C++的数组内存分配规则，用交换指针来代替交换整行，提高效率

#include<iostream>

using namespace std;

void processMatrixRevert();
void HorizontalRevert(int **m, int level);
void VerticalRevert(int **m, int level);
void DiagonalRevert(int **m, int level);
void DisplayMatrix(int **m, int level);
void swap(int *a, int *b);

int main(int argc, char **argv)
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		processMatrixRevert();

	//system("pause");
	return 0;
}

void processMatrixRevert()
{
	int level = 0, direction = -1;
	cin >> level >> direction;
	//Allocate memory
	int **matrix = new int *[level];//Row
	for (int i = 0; i < level; i++)
		matrix[i] = new int[level];//Column
	//Record data
	for (int i = 0; i < level; i++)
		for (int j = 0; j < level; j++)
			cin >> matrix[i][j];

	//Process
	switch (direction)
	{
	case 0:
		HorizontalRevert(matrix, level);
		break;
	case 1:
		VerticalRevert(matrix, level);
		break;
	case 2:
		DiagonalRevert(matrix, level);
		break;
	default:
		return;
	}
	DisplayMatrix(matrix, level);

	//Free memory
	for (int i = 0; i < level; i++)
	{
		delete[]matrix[i];
		matrix[i] = NULL;
	}
	delete[]matrix;
	matrix = NULL;
}

void HorizontalRevert(int **m, int level)
{
	for (int i = 0; i < level; i++)
	{
		int left = 0, right = level - 1;
		while (left < right)
			swap(&m[i][left++], &m[i][right--]);
	}
}

void VerticalRevert(int **m, int level)
{
	int up = 0, down = level - 1;
	while (up < down)
	{
		int *t;
		t = m[up];
		m[up] = m[down];
		m[down] = t;
		up++;
		down--;
	}
}

void DiagonalRevert(int **m, int level)
{
	for (int i = 0; i < level; i++)
		for (int j = 0; j < i; j++)
			swap(&m[i][j], &m[j][i]);
}

void DisplayMatrix(int **m, int level)
{
	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j < level; j++)
		{
			cout << m[i][j];
			if (j != level - 1)
				cout << " ";
		}
		cout << endl;
	}
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
