#include <stdio.h>
#include <stdlib.h>
typedef struct freze{
	int custo;
	int num;
} freze;
typedef struct cha{
	int a;
	int b;
}cha;
int comp(const void *a, const void *b){
	return ((const freze *)a)->custo - ((const freze *)b)->custo;
}
int main(){
	freze geladeira[1001];
	cha lista[2001];
	int cost, cases, frezers, chains, atuchain;
	scanf("%d", &cases);
	for(int i = 0; i < cases; ++i){
		atuchain = cost = 0;
		scanf("%d%d", &frezers, &chains);
		for(int j = 0; j < frezers; ++j){
			scanf("%d", &geladeira[j].custo);
			geladeira[j].num = j+1;
		}
		qsort(geladeira, frezers, sizeof(freze), comp);
		if(chains == frezers){
			for(int j = 0; j < frezers-1; ++j){
				lista[atuchain].a = geladeira[j].num;
				lista[atuchain++].b = geladeira[j+1].num;
				cost += geladeira[j+1].custo + geladeira[j].custo;
			}
			lista[atuchain].a = geladeira[0].num;
			lista[atuchain++].b = geladeira[frezers-1].num;
			cost += geladeira[0].custo + geladeira[frezers-1].custo;
		}
		else if(frezers > 2 && ((chains >= 2*(frezers - 2) && chains > 3) || (chains >= 2*(frezers - 2)+1)) ){//if chains > 3 1 and 2 has 2+ chains,(chains -2) if 3 1 and 2 has 1
			for(int j = 2; j < frezers; ++j){
				// printf("qs\n");
				for(int k = 0; k < 2; ++k){
					lista[atuchain].a = geladeira[k].num;
					lista[atuchain++].b = geladeira[j].num;
					cost += geladeira[k].custo + geladeira[j].custo;
				}
				// printf("qs\n");
			}
		}else{
			printf("-1\n");
			continue;
		}
		if((chains - atuchain) >= 0){
			int falta = chains - atuchain;
			for(int k = 0; k < falta; ++k){
				lista[atuchain].a = geladeira[0].num;
				lista[atuchain++].b = geladeira[1].num;
				cost += geladeira[0].custo + geladeira[1].custo;
			}
			printf("%d\n", cost);
		}else{
			printf("-1\n");
			continue;
		}
		for(int j = 0; j < chains; ++j){
			printf("%d %d\n", lista[j].a, lista[j].b);
		}
	}
	return 0;
}