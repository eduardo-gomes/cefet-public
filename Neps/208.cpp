#include <bits/stdc++.h>
#define MAXQ 100005
using namespace std;
vector<int> adj[MAXQ];
int nivel[MAXQ], n;

int DFS(int st){
	int lm = adj[st].size(), sum = 1;
	//if(lm == 0) sum = 1;
	for(auto viz: adj[st]){
		sum += DFS(viz);
	}
	return nivel[st] = sum;
}

int verifica(int st){
	if(adj[st].size() == 0) return 1;
	int sz = -1;
	for(auto viz: adj[st]){
		if(verifica(viz) == 0) return 0;
		if(sz == -1){
			sz = nivel[viz];
			continue;
		}
		if(sz != nivel[viz]) return 0;
	}
	return 1;
}

int main(){
	memset(nivel, -1, sizeof(int) * MAXQ);
	// memset(sizen, -1, sizeof(int) * MAXQ);
	scanf("%d", &n);
	int peca, em, raiz;
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &peca, &em);
		//if(em == 0) raiz = peca;
		adj[em].push_back(peca);
	}
	//BFS(raiz);
	raiz = 0;
	int x = DFS(raiz);
	printf("%s\n", verifica(raiz) == 1 ? "bem": "mal");
	/*for(int i = 1; i <= n; ++i){
		printf("NIVEL %d %d\n", i, nivel[i]);
	}*/
}