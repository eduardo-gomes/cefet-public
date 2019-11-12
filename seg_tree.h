////////////////////////////
// 2019/11/02 20:58 - 21:40
////////////////////////////
#include <bits/stdc++.h>

using namespace std;
/////////////////////////////////////////////////////////////
// Menor elemento do segmento
int *arvore = (int *)calloc(100, sizeof(int)), *elemento = (int *)calloc(100, sizeof(int));
void atualiza(int no, int i, int j, int pos, int n_val){ //Seg tree
	if(i == j){ //ultimo nivel do segmento;
		arvore[no] = i;
		elemento[pos] = n_val;
	}else{
		int esquerda = 2 * no, direita = 2 * no + 1;
		int meio = (i + j) / 2;

		//se antes do meio vai esquerda, se nao direita
		if(pos <= meio) atualiza(esquerda, i, meio, pos, n_val);
		else atualiza(direita, meio+1, j, pos, n_val);

		// Pega o melhor resultado
		arvore[no] = elemento[arvore[esquerda]] < elemento[arvore[direita]] ? arvore[esquerda] : arvore[direita];
	}
	return;
}

int consulta(int no, int i, int j, int A, int B){
	//Se [i, j] esta contido em [A, B]
	if(A <= i && B <= j){
		return arvore[no];
	}
	//Se disjunto retorna -1
	if(i > B || A > j){
		return -1;
	}

	int esquerda = 2*no, direita = 2*no+1;
	int meio = (i + j) / 2;

	int res_esq = consulta(esquerda, i, meio, A, B);
	int res_dir = consulta(direita, meio + 1, j, A, B);
	//Se um for disjunto retorna o outro
	if(res_esq == -1) return res_dir;
	if(res_dir == -1) return res_esq;

	//Se os dois sao validos retorna o menor
	if(res_esq < res_dir) return res_esq;
	else return res_dir;
}