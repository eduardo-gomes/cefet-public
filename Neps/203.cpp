#include <bits/stdc++.h>
#define SIZEM 1123
using namespace std;
int n, times[SIZEM], tatu = 0;
vector<int> adj[SIZEM];

void BFS(int a){
	queue<int> fila;
	fila.push(a);
	times[a] = tatu++;
	while(!fila.empty()){
		int now = fila.front();
		fila.pop();
		for(auto viz: adj[now]){
			if(times[viz] == -1){
				times[viz] = times[a];
				fila.push(viz);
			}
		}
	}
}

int main(){
	int m, r1, r2;
	scanf("%d%d", &n, &m);
	memset(times, -1, sizeof(int) * SIZEM);
	for(int i = 0; i < m; ++i){
		scanf("%d%d", &r1, &r2);
		adj[r1].push_back(r2);
		adj[r2].push_back(r1);
	}
	for(int i = 1; i <= n; ++i){
		if(times[i] == -1){
			BFS(i);
		}
	}
	printf("%d\n", tatu);
}