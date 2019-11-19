#include <bits/stdc++.h>
#define INF 99999999
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
vector<vector< pii > > pode_ir;
int n, m, k, c;
vector<bool> proc;
vector<int> dst;

void dijkstra(){
	//st = k
	set<pii> fila;
	dst[k] = 0;
	fila.insert(make_pair(dst[k], k));//dst, vertice
	while(1){
		pii n_vert = {.F = -1, .S = -1};
		while(!fila.empty()){
			pii atu = *fila.begin();
			fila.erase(fila.begin());
			if(!proc[atu.S]){
				n_vert = atu;
				break;
			}
		}
		if(n_vert.S == -1) break;
		proc[n_vert.S] = 1;
		for(auto viz: pode_ir[n_vert.S]){//to pedagio
			if(dst[viz.F] > dst[n_vert.S] + viz.S){
				dst[viz.F] = dst[n_vert.S] + viz.S;
				fila.insert({dst[viz.F], viz.F});
			}
		}
	}
}

bool pode(int a, int b){
	if (a >= c)
		return 1;
	
	if (a+1 == b and b < c)
		return 1;

	return 0;
	
}
int main(){
	while(1){
		cin >> n >> m >> c >> k;
		if(!n || !m || !c || !k) break;
		dst.assign(n, INF);
		proc.assign(n, false);
		pode_ir.assign(n, vector<pii>());

		for(int i = 0; i < m; ++i){
			int r1,r2, ped;
			scanf("%d%d%d", &r1, &r2, &ped);
			pii to[2] = {make_pair(r2, ped), make_pair(r1, ped)};
			if(pode(r1, r2)) pode_ir[r1].push_back(to[0]);
			if(pode(r2, r1)) pode_ir[r2].push_back(to[1]);
		}
		/*for(int i = 0; i < n; ++i){
			printf("%d\n", i);
			for(auto got : pode_ir[i]){
				printf("\t%d\n", got.first);
			}
		}*/
		dijkstra();
		cout<<dst[c-1]<<'\n';
	}
	return 0;
}