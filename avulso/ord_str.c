#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp(const void *a, const void *b){// se antes -1, se depois 1
    void *aa = *(void**)a;
    void *bb = *(void**)b;
    double na = *(double*)(aa+1),nb = *(double*)(bb+1);
    char *sa = (char*)aa, *sb = (char*)bb;
    //printf("comp %lf %lf\nstr %s %s\n", na, nb, sa, sb);
    if(na != nb){
        if(na < nb)return -1;
        if(na > nb)return 1;
    }else return strcmp(sa, sb);
}
int main(){
    void *indi[100][2];
    char nome[100][255];
    int lendo = 0;
    double nota[100];
    for(int i = 0; i < 100; ++i){
        indi[i][0] = &nome[i];
        indi[i][1] = &nota[i];
    }
    while(scanf(" %s%lf", (char*)indi[lendo][0], (double*)indi[lendo][1]) != EOF){
        lendo++;
    }
    qsort(indi, lendo, sizeof(void*)*2, comp);
    for(int i = 0; i < lendo; ++i){
        printf("%s %lf\n", (char*)indi[i][0], *(double*)indi[i][1]);
    }
}