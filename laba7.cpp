#define _CRT_SECURE_NO_WARNINGS
#include<list>
#include <deque>
#include<stack>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <locale.h>
using namespace std;
void DFS(int s);
void DFS2(int s);
int* visited;
int** a;
int n;
int main()
{
	srand(time(0));
	int s = 0;

	setlocale(LC_ALL, "rus");
	printf("Введите количество элементов для графа:");
	scanf("%d", &n);
	visited = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		visited[i] = 0;
	}
	a = (int**)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{


		for (int j = i; j < n; j++)
		{
			a[i][j] = rand() % 2;

			if (i == j)
			{
				a[i][j] = 0;

			}
			a[j][i] = a[i][j];

		}

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%-5d  ", a[i][j]);

		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("\n");
	DFS(s);
	for (int i = 0; i < n; i++)
	{
		visited[i] = 0;
	}
	printf("\n");
	DFS2(s);
}
void DFS(int s)
{
	visited[s] = 1;
	printf("%d ", s);
	for (int i = 0; i < n; i++)
	{
		if (visited[i]==0 && a[s][i] == 1)
		{
			DFS(i);
		}
	}

}

void DFS2(int s)
{
	stack<int> S;
	int t;
	S.push(s);
	visited[s]++;
	while (!S.empty())
	{
		t = S.top();
		S.pop();
		cout << t << " ";
		for (int i = n - 1; i >= 0; i--)
		{
			if (!visited[i] && a[t][i] )
			{
				S.push(i);
				visited[i]++;
			}
		}
	}
}