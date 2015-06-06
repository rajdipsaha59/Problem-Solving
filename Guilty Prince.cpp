/*
    Author : Rajdip Saha
*/

#define _CRT_SECURE_NO_WARNINGS

#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define MAX 1000000
#define PI 2*acos(0.0)
#define MOD 1000000007

typedef long long int ll;
typedef unsigned long long int llu;

using namespace std;

int va_1[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int va_2[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int n, m;
char grid[105][105];
bool visit[105][105];

int BFS()
{
	memset(visit, false, sizeof(visit));
	int count = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (grid[i][j] == '@'&&visit[i][j] == false){
				queue < int > q;
				visit[i][j] = true;
				q.push(i);
				q.push(j);
				while (!q.empty()){
					int a = q.front();
					q.pop();
					int b = q.front();
					q.pop();
					for (int k = 0; k < 8; k++){
						int x = a + va_1[k];
						int y = b + va_2[k];
						if ((x >= 0 && x < n) && (y >= 0 && y < m)){
							if (visit[x][y] == false && grid[x][y] == '@'){
								q.push(x);
								q.push(y);
								visit[x][y] = true;
							}
						}
					}
				}
				count++;
			}
		}
	}
	return count;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (~scanf("%d %d", &n, &m)){
		if (!n)break;
		for (int j = 0; j < n; j++){
			scanf("%s", grid[j]);
		}
		printf("%d\n", BFS());
	}
	//system("pause");
	return 0;
}