// Menor area conectada
#include <bits/stdc++.h>
using namespace std;
int **matriz, **grupo, atgrupo = 0, mini = -1, h, l;
pair<int, int> dif[] = {make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0)};

void bfs(pair<int, int> ori){
	queue<pair<int, int>> fila;
	fila.push(ori);
	int sz = 0, cor = matriz[ori.first][ori.second];
	grupo[ori.first][ori.second] = atgrupo++;
	while(!fila.empty()){
		pair<int, int> veri = fila.front();
		fila.pop();
		sz++;
		//cout << "PASS2\n";
		for(int i = 0; i < 4; ++i){
			pair<int, int> totest = make_pair(veri.first + dif[i].first, veri.second + dif[i]. second);
			//Verifica se ta dentro da matriz
			if(totest.first >= 0 && totest.second >= 0 && totest.first < h && totest.second < l){
				if(matriz[totest.first][totest.second] == cor && grupo[totest.first][totest.second] == -1){
					grupo[totest.first][totest.second] = grupo[ori.first][ori.second];
					//cout << "PASS3\n";
					fila.push(totest);
				}
			}
		}
	}
	if(mini == -1) mini = sz;
	mini = min(mini, sz);
}

int main(){
	scanf("%d%d", &h, &l);
	matriz = (int **)malloc(sizeof(int *) * h);
	grupo = (int **)malloc(sizeof(int *) * h);
	for(int i = 0; i < h; ++i){
		matriz[i] = (int *)malloc(sizeof(int) * l);
		grupo[i] = (int *)malloc(sizeof(int) * l);
		memset(grupo[i], -1, sizeof(int) * l);
	}
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < l; ++j){
			scanf("%d", &matriz[i][j]);
		}
	}
	//cout<<"PASS\n";
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < l; ++j){
			if(grupo[i][j] == -1){
				//cout<<i<<'\t'<<j<<'\n';
				bfs(make_pair(i, j));
			}
		}
	}
	/*for(int i = 0; i < h; ++i){
		for(int j = 0; j < l; ++j){
			printf("%d ", grupo[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n", mini);
}