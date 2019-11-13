#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b){
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
}

char line[1000][12345];
int main(){
    int i;
    FILE *in = fopen("inp", "r"), *par = fopen("out2", "w"), *impar = fopen("out1", "w");
    printf("LEU\n");
    for(i = 0; fgets(line[i], 12345, in) != NULL; ++i);
    printf("LEU2\n");
    i++;
    qsort(line, 2, sizeof(char*), cmp);
    printf("Sorted\n");
    for(int j = 0; j < i; ++j){
        //printf("Print l%d", j);
        //if(j%2){
            fprintf(par, "%s", line[j]);
        //}else{
            fprintf(impar, "%s", line[j]);
        //}
    }
}