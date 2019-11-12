#include <stdio.h>
void printcor(){
    char a[6][10] = {{"Red"}, {"Green"}, {"Yellow"}, {"Blue"}, {"Magenta"}, {"Cyan"}};
    int bold, cor;
    char ca;
    for (int i = 0; i < 6; ++i) printf("%s\t%d\n", a[i], i+1);
    printf("Digite o numero da cor e 1 para negrito ou 0 para normal:\n");
    scanf("%d%d", &cor, &bold);
    printf("\033[%d;3%dm", bold, cor);
    while(scanf("%c", &ca) != EOF){
        printf("%c", ca);
    }
    printf("\033[0m\n");
}
int main(){
    printcor();
}