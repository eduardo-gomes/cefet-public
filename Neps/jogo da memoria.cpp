//2019/12/25 21:00 - 22:21(codigo) -22:50(analise, como funciona)
#include<bits/stdc++.h>
#define MAXL 17 //log n
using namespace std;
vector<vector<int>> adj;
vector<vector<int>> ancestral;
vector<int> pai;
vector<int> nivel;
vector<int> carta;
vector<int> par;

void DFS(int v){
	for(auto i: adj[v]){
		if(nivel[i] == -1){
			nivel[i] = nivel[v] + 1;
			pai[i] = v;
			DFS(i);
		}
	}
}

int LCA(int a, int b){
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

int main(){
	int n, r1, r2, c;
	cin >> n;
	adj.resize(n+1);
	nivel.resize(n+1, -1);
	pai.resize(n+1, -1);
	par.resize(n + 1);
	carta.resize(n+1);
	ancestral.resize(n+1);
	for(int i = 0; i <= n; ++i) ancestral[i].resize(MAXL, -1);
	for(int i = 1; i <= n; ++i){
		cin >> c;
		if(carta[c]){
			par[i] = carta[c];
			par[carta[c]] = i;
		}
		carta[c] = i;
	}
	for(int i = 1; i < n; ++i){
		cin >> r1 >> r2;
		adj[r1].push_back(r2);
		adj[r2].push_back(r1);
	}
	//raiz nivel 0;
	nivel[1] = 0;
	pai[1] = 1;
	DFS(1);

	//ancestral
	for(int i = 1; i <= n; ++i) ancestral[i][0] = pai[i];
	for(int j = 1; j < MAXL; ++j){
		for (int i = 1; i <= n; ++i){
			ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
		}
	}
	long long resp = 0;
	for(int i = 1; i <= n; ++i){
		resp += nivel[i] + nivel[par[i]] - 2 * nivel[LCA(i, par[i])];
	}
	cout << resp/2 << endl;
	return 0;
}