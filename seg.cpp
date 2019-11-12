////////////////////////////
// 2019/11/02 21:40 - 22:00 WIP
////////////////////////////
#include <bits/stdc++.h>
#include "seg_tree.h"
#define Astart 0
#define Aend 9
using namespace std;
int main(){
	int read;
	for(int i = 0; i < 10; ++i){
		printf("Digito o valor do elemento %d:\n", i);
		scanf("%d", &read);
		atualiza(0, Astart, Aend, i, read);
	}
	for(int i = 0; i < 10; ++i){
		for(int j = i; j < 10; ++j){
			printf("Menor do segmento %d %d: %d\n", i, j, consulta(0, Astart, Aend, i, j));
		}
	}
	return 0;
}