//2019/12/26 12:50 - 14:52
#include <bits/stdc++.h>
#define MAXL 18 //Log N
using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> ancestral;
vector<vector<pii>> adj;
vector<int> pai;
vector<int> nivel;
vector<long long> distancia_raiz;
void dfs(int a){
	for(auto i: adj[a]){
		if(nivel[i.first] == -1){
			nivel[i.first] = nivel[a]+1;
			pai[i.first] = a;
			distancia_raiz[i.first] = distancia_raiz[a] + i.second;
			dfs(i.first);
		}
	}
}

int lca(int a, int b){
	if(nivel[a] < nivel[b]) swap(a, b);
	for(int i = MAXL-1; i >=0; --i){
		if(nivel[a] - (1<<i) >= nivel[b])
			a = ancestral[a][i];
	}
	if(a == b) return a;

	for(int i = MAXL-1; i >=0; --i){
		if (ancestral[a][i] != -1 && ancestral[a][i] != ancestral[b][i]){
			a = ancestral[a][i];
			b = ancestral[b][i];
		}
	}
	return pai[a];
}

long long calc_dist(int a, int b){
	return distancia_raiz[a] + distancia_raiz[b] - 2 * distancia_raiz[lca(a, b)];
}

int main(){
	int n, liga, dist, sz = 0;
	scanf("%d", &n);
	while(n != 0){
		adj.resize(n);
		if(sz < n){
			ancestral.resize(n);
			pai.resize(n);
			nivel.resize(n);
			distancia_raiz.resize(n);
			for(int i = 0; i < n; ++i) ancestral[i].resize(MAXL, -1);
			sz = n;
		}
		//inicializa
		for(int i = 0; i < n; ++i){
			pai[i] = nivel[i] = -1;
			//for(int j = 0; j < MAXL; ++j) ancestral[i][j] = -1;
		}
		for(int i = 1; i < n; ++i){
			scanf("%d%d", &liga, &dist);
			adj[i].push_back(make_pair(liga, dist));
			adj[liga].push_back(make_pair(i, dist));
		}
		distancia_raiz[0] = pai[0] = nivel[0] = 0;
		dfs(0);
		for(int i = 0; i < n; ++i) ancestral[i][0] = pai[i];
		for(int j = 1; j < MAXL; ++j){
			for(int i = 0; i < n; ++i)
				ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
		}
		int qnt, r1, r2, first = 1;
		scanf("%d", &qnt);
		for(int i = 0; i < qnt; ++i){
			scanf("%d%d", &r1, &r2);
			if (!first)
				printf(" ");
			else first = 0;
			printf("%lld", calc_dist(r1, r2));
		}
		printf("\n");
		cin >> n;
		adj.clear();
	}
}
