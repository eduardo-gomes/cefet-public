#include <bits/stdc++.h>
using namespace std;
int main(){
    int vertices[101];
    int a, b, c, d, maxi, teste = 1;
    bool nfirs = 0;
    scanf("%d%d", &a, &b);
    while(a != 0 || b != 0){
        nfirs = 0;
        maxi = 0;
        memset(vertices, 0, sizeof(vertices));
        for(int i = 0; i < b; ++i){
            scanf("%d%d", &c, &d);
            vertices[c]++;
            vertices[d]++;
            maxi = max(maxi, max(vertices[c], vertices[d]));
        }
        printf("Teste %d\n", teste++);
        for(int i = 1; i <= a; ++i){
            if(vertices[i] == maxi){
                if(nfirs) printf(" ");
                else nfirs = !nfirs;
                printf("%d", i);
            }
        }
        printf("\n\n");
        scanf("%d%d", &a, &b);
    }
    return 0;
}