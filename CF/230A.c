#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct drag{
    int st;
    int bon;
} drag;
int comp(const void *a, const void *b){
    const drag *A = a, *B = b;
    return A->st - B->st;
}
int main(){
    int stren, ndrag;
    scanf("%d%d", &stren, &ndrag);
    drag *lista = malloc(sizeof(drag) * ndrag);
    for(int i = 0; i < ndrag; ++i){
        scanf("%d%d", &lista[i].st, &lista[i].bon);
    }
    qsort(lista, ndrag, sizeof(drag), comp);
    for(int i = 0; i < ndrag; ++i){
        if(stren > lista[i].st) stren += lista[i].bon;
        else{
            stren = -1;
            break;
        }
    }
    if(stren == -1){
        printf("NO\n");
    }else {
        printf("YES\n");
    }
}