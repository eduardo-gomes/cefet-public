#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define aloca 7200
struct Megabyte{
    char m[1000000];
};
typedef struct Megabyte MB;
int main(){
    MB defa, *mem;
    memset(defa.m, 127, 1000000);
    for(int i = 0; i < 10; ++i){
        mem = malloc(sizeof(MB) * aloca);
        for(int i = 0; i < aloca; ++i){
            mem[i] = defa;
            //mem[i].m[0] = 1;
        }
        scanf("%*c");
        free(mem);
    }
}