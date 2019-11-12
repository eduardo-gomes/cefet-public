#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char nome[100][255];
double nota[100];
int comp(const void *a, const void *b){// se ven antes -1
    printf("%x %x\n", a, b);
    int inda = *(int*)a, indb = *(int*)b;
    printf("%d %d\n", inda, indb);
    if(nota[inda] != nota[indb]){
        if(nota[inda] > nota[indb]) return -1;
        return 1;
    }else return strcmp(nome[inda], nome[indb]);
}

int main(){
    int indi[100];
    for(int i = 0; i < 100; ++i) indi[i] = i;
    int lendo = 0;
    printf("le\n");
    while(scanf(" %s%lf", nome[indi[lendo]], &nota[indi[lendo]]) != EOF){
        lendo++;
    }
    printf("qsort\n");
    qsort(indi, lendo, sizeof(int), comp);
    for(int i = 0; i < lendo; ++i){
        printf("%s %lf\n", nome[indi[i]], nota[indi[i]]);
    }
}