#include <stdlib.h>
#include <stdio.h>

struct par{
    int x;
    int y;
};

int compara(const void* st, const void* nd){
    struct par a = *(struct par*)st, b = *(struct par*)nd;
    if(a.y < b.y) return -1;
    if(a.y > b.y) return 1;
    if(a.x < b.x) return -1;
    if(a.x > b.x) return 1;
    return 0;
}

int main(){
    int n, x,y;
    scanf("%d", &n);
    struct par vetor[n];
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &x, &y);
        vetor[i].x=x;
        vetor[i].y=y;
    }
    qsort(vetor, n, sizeof(struct par), compara);
    for(int i = 0; i < n; ++i){
        printf("%d: %d %d\n", i, vetor[i].x, vetor[i].y);//cout<<vetor[i].x<<" "<<vetor[i].y<<'\n';
    }
    return 0;
}