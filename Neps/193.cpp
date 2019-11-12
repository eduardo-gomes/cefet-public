// 05/11 - 19:47-21:12 -3
// 07/11 - 13:30-15:15 -3
// 07/11 - 16:10-17:45 -3
// 08/11 - 23:28-23:38 -3
#include <bits/stdc++.h>
using namespace std;
char matriz[1000][1000];
int dst[1000][1000];
vector<pair<int, int>> adj[1000][1000];
int lin, col;
pair<int, int>dois, tres;

void pega_adj(){
	for(int i = 0; i < lin; ++i){
		for(int j = 0; j < col; ++j){
			if(matriz[i][j] == '0') continue;
			pair<int, int> next[4], atu = make_pair(i, j);
			next[0] = make_pair(i+1, j);
			next[1] = make_pair(i-1, j);
			next[2] = make_pair(i, j+1);
			next[3] = make_pair(i, j-1);
			for(int ne = 0; ne < 4; ++ne){
				if(next[ne].first == -1 || next[ne].first == lin || next[ne].second == -1 || next[ne].second == col)
					continue;//fora do intervalo
				if(matriz[next[ne].first][next[ne].second] != '0'){
					adj[i][j].push_back(next[ne]);//add como vizinho
					adj[next[ne].first][next[ne].second].push_back(atu);
				}
			}
		}
	}
}

int BFS(){
	queue<pair<int, int> > fila;
	fila.push(dois);
	dst[dois.first][dois.second] = 1;
	while(!fila.empty()){
		pair<int, int> atu = fila.front();//Pega o proximo da fila
		fila.pop();//retira da fila
		for(auto viz: adj[atu.first][atu.second]){////for(int i = 0; i < adj[atu.first][atu.second].size(); ++i){
			//pega os vizinhos do proximo
			////pair<int, int> viz = adj[atu.first][atu.second][i];
			if(dst[viz.first][viz.second] == -1){//se ainda nao foi contado add + 1 \/
				dst[viz.first][viz.second] = (dst[atu.first][atu.second] + 1);//BFS conta distancia
				fila.push(viz);//adiciona na fila
				if(viz == tres)
					return dst[viz.first][viz.second];
			}
		}
	}
}

/*void print_adj(){
	for(int i = 0; i < lin; ++i){
		for(int j = 0; j < col; ++j){
			printf("%c|", matriz[i][j]);
		}
	}
	printf("\n");
	for(int i = 0; i < lin; ++i){
		for(int j = 0; j < col; ++j){
			printf("viz de %d %d:\n", i, j);
			for(int k = 0; k < adj[i][j].size(); ++k){
				printf("%d %d dst%d\n", adj[i][j][k].first, adj[i][j][k].second, dst[adj[i][j][k].first][adj[i][j][k].second]);
			}
			printf("\n");
		}
	}
}*/

int main(){
	scanf("%d%d ", &lin, &col);
	for(int i = 0; i < 1000; ++i){
		memset(dst[i], -1, sizeof(int) * 1000);
	}
	for(int i = 0; i < lin; ++i){
		for(int j = 0; j < col; ++j){
			scanf(" %c", &matriz[i][j]);
			if(matriz[i][j] == '2') dois = make_pair(i, j);
			if(matriz[i][j] == '3') tres = make_pair(i, j);
		}
	}
	pega_adj();
	//BFS();
	//print_adj();
	//int passa_por = dst[tres.first][tres.second];
	printf("%d\n", BFS());
	return 0;
}