// 11/11 14:00-18:30 -3
// 
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define X first
#define Y second
#define SX second.second
#define SY second.first
#define INF 1000000
using namespace std;
int **mina, **distancia, **proc, n;

pair<int, int> dire[4] = {{.first = 0, .second = 1}, {.first = 0, .second = -1}, {.first = 1, .second = 0}, {.first = -1, .second = 0}};//Direçôes alteraveis

typedef pair<int, pair<int, int>> dbi; //double int pair

vector<dbi> adj[100][100];

void createadj(){
    int x = 0, y = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            pair<int, int> now = make_pair(i, j);
            for(int k = 0; k < 4; ++k){
                if(now.X + dire[k].X < n && now.X + dire[k].X >= 0 && now.Y + dire[k].Y < n && now.Y + dire[k].Y >= 0){//ve se ta dentro do mapa
                    dbi viz = {make_pair(mina[now.Y + dire[k].Y][now.X + dire[k].X], make_pair(now.Y + dire[k].Y, now.X + dire[k].X))};//novo vizinho
                    adj[now.Y][now.X].push_back(viz);
                }
            }
        }
    }
}

int dijkstra(dbi st){
    distancia[st.SY][st.SX] = 0;
    set<dbi> lista;
    lista.insert(st);
    while(1){
        dbi torun = make_pair(0, make_pair(-1, -1));
        int minimo = INF;
        while(!lista.empty()){
            dbi atu = *lista.begin();
            lista.erase(lista.begin());
            //printf("T1\n");
            //printf("%d %d %p\n", atu.SY, atu.SX, proc[atu.SY]);
            if(!proc[atu.SY][atu.SX]){
                //printf("T1.5\n");
                torun = atu;
                break;
            }
            //printf("T2\n");

        }
        if(torun == make_pair(0, make_pair(-1, -1))) break;
        proc[torun.SY][torun.SX] = 1;
        //printf("1\n");
        for(auto viz: adj[torun.SY][torun.SX]){
            int peso = viz.first;
            if(distancia[viz.SY][viz.SX] > distancia[torun.SY][torun.SX] + peso){
                distancia[viz.SY][viz.SX] = distancia[torun.SY][torun.SX] + peso;
                //printf("%d %d\n", viz.SY, viz.SX);
                dbi novo;
                novo.first = distancia[viz.SY][viz.SX];
                novo.SX = viz.SX;
                novo.SY = viz.SY;
                lista.insert(novo);
            }
        }
    }
}

int main(){
    //int r;
    scanf("%d", &n);
    mina = (int**)malloc(sizeof(int*) * n);
    distancia = (int**)malloc(sizeof(int*) * n);
    proc = (int**)malloc(sizeof(int*) * n);
    for(int i = 0 ; i < n; ++i){
        mina[i] = (int*)malloc(sizeof(int) * n );
        distancia[i] = (int*)malloc(sizeof(int) * n);
        proc[i] = (int*)malloc(sizeof(int) * n);
        //printf("-- %d %p\n", i, proc[i]);
        for(int j = 0; j < n; ++j){
            distancia[i][j] = INF;
            proc[i][j] = 0;
        }
        //printf("-- %d %p\n", i, proc[i]);
        //memset(&proc[i][0], 0, sizeof(int) * n);
        //for(int )
    }
    //printf("%d", distancia[n-1][n-1]);

    
    for(int i = 0; i < n; ++i){
        
        for(int j = 0; j < n; ++j){
            //printf("***%d %d %p %p\n", i, j, &mina[i][j], proc);
            int qqcoisa;
            scanf("%d", &qqcoisa);
            mina[i][j] = qqcoisa;
            
        }
    }
    
    createadj();
    
    /*for(auto viz: adj[0][1]){
        printf("%d %d %d\n", viz.first, viz.SY, viz.SX);
    }*/
    dbi start = make_pair(0, make_pair(0, 0));
    dijkstra(start);
    printf("%d\n", distancia[n-1][n-1]);
}