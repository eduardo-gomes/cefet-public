#include <bits/stdc++.h>
using namespace std;
int mar(char a){
    return a == '.' ? 1: 0;
}
int **mapa;
pair<int, int> dire[4] = {make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0)};
int verify(int m, int n){
    int count = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            bool e = 0;
            if(mapa[i][j] == 0){
                for(int k = 0; k < 4; ++k){
                    if(i + dire[k].first < m && i + dire[k].first >= 0 && j + dire[k].second < n && j + dire[k].second >= 0){
                        if(mapa[i + dire[k].first][j + dire[k].second] == 1){
                            e = e || 1;
                        }
                    }else e = 1;
                }
                if(e) count++;
                e = 0;
            }
        }
    }
    return count;
}

int main(){
    int m, n;
    char read;
    scanf("%d%d", &m, &n);
    mapa = (int**)malloc(sizeof(int*) * m);
    for(int i = 0; i < m; ++i){
        mapa[i] = (int*)malloc(sizeof(int) * n);
    }
    //printf("vai\n");
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            scanf(" %c", &read);
            mapa[i][j] = mar(read);
            //printf("%c", read);
        }
        //cout<<"\n";
    }
    //printf("vai\n");

    printf("%d\n", verify(m, n)); 
    return 0;
}