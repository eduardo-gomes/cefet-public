#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct I2{
	long long int x, y;
	int val;
};

int comp(const void* a, const void* b){
	struct I2 x = *((struct I2*) a), y = *((struct I2*) b);
	return x.val - y.val;
}

int main(){
	struct I2 pontos[10];
	for(int i = 0; i < 10; ++i){
		pontos[i].x = i;
		pontos[i].y = i*2 + 1;
		printf("Digite o indice do ponto %d:", i);
		scanf("%d", &pontos[i].val);
	}
	qsort(pontos, 10, sizeof(struct I2), comp);
	for(int i = 0; i < 10; ++i){
		printf("Ponto %d: X = %lld\tY = %lld\t Index = %d\n", i, pontos[i].x, pontos[i].y, pontos[i].val);
	}
	return 0;
}