//11:50-12:20 12:55-13:08 38 min
#include <bits/stdc++.h>
#include <limits.h>
#define INF INT_MAX
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>> adj;
vector<int> dist;
vector<bool> proc;

int prim(){
	dist[0] = 0;
	set<pii> fila;
	fila.insert(make_pair(dist[0], 0));//dist, qual
	while(1){
		int pega = -1;
		while(!fila.empty()){
			int novo = fila.begin()->second;
			fila.erase(fila.begin());
			if(!proc[novo]){
				pega = novo;
				break;
			}
		}

		if(pega == -1) break;
		proc[pega] = true;
		for(auto vizinho: adj[pega]){
			int dst_from = vizinho.second, to_from = vizinho.first;

			if(dst_from < dist[to_from] && !proc[to_from]){
				dist[to_from] = dst_from;
				fila.insert(make_pair(dist[to_from], to_from));
			}
		}
	}
	int custo_total = 0;
	for(auto i: dist)
		custo_total += i;
	return custo_total;
}

int main(){
	int vertices, arestas;
	cin >> vertices >> arestas;
	adj.resize(vertices);
	dist.resize(vertices, INF);
	proc.resize(vertices, 0);
	for(int i = 0; i < arestas; ++i){
		int x, y, custo;
		cin >> x >> y >> custo;
		adj[x].push_back(make_pair(y, custo));
		adj[y].push_back(make_pair(x, custo));
	}
	cout << prim() << endl;
}