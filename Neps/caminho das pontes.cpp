//Eduardo de Matos Gomes
// 2019/11/12 20:10 - 21:45 -3
// https://neps.academy/lesson/212
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
vector<pair<int, int> > adj[1005];
int *proc;
int *dst, n;

void dijkstra(int st){
	dst[st] = 0;
	set<pair<int, int>> fila;//distancia, vertice
	fila.insert(make_pair(dst[st], st));
	while(1){
		int vert = -1;
		//int menor = INF;
		while(!fila.empty()){//Pega proximo
			int nvert = (*fila.begin()).second;
			fila.erase(fila.begin());
			if(!proc[nvert]){//Que nao tenha sido pego
				vert = nvert;
				break;
			}
		}
		if(vert == -1) return;//se nao pego ninguem
		proc[vert] = 1;
		for(auto viz: adj[vert]){
			//viz st = to, nd = dst
			if(dst[viz.first] > dst[vert] + viz.second){//se é mais perto
				dst[viz.first] = dst[vert] + viz.second;
				fila.insert(make_pair(dst[viz.first], viz.first));//add queue
			}
		}
	}
}

int main(){
	int m, s, t, b;
	scanf("%d%d", &n, &m);
	proc = (int *)malloc( sizeof(int) * n+10);
	//memset(proc, 0, sizeof(bool) * n+2);
	dst = (int *)malloc( sizeof(int) * n+10);
	for(int i = 0; i < n+2; ++i){
		dst[i] = INF;
		proc[i] = false;
	}
	for(int i = 0; i < m; ++i){
		scanf("%d%d%d", &s, &t, &b);
		adj[s].push_back(make_pair(t, b));
		adj[t].push_back(make_pair(s, b));
	}
	dijkstra(0);
	printf("%d\n", dst[n+1]);
}