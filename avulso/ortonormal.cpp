#include <bits/stdc++.h>
using namespace std;
unsigned int esp_vetorial, n_vecs;
long double **vetores, *ortogonaliando;
void aloca_e_le(){
	vetores = (long double**)malloc(sizeof(void*)*n_vecs);
	ortogonaliando = (long double *)malloc(sizeof(long double) * esp_vetorial);
	for(int i = 0; i < n_vecs; ++i){
		vetores[i] = (long double*)malloc(sizeof(long double)*esp_vetorial);
		for(int j = 0; j < esp_vetorial; ++j){
			scanf("%Lf", &vetores[i][j]);
		}
	}
}

void imprime(){
	for(int i = 0; i < n_vecs; ++i){
		printf("V%d:", i+1);
		for(int j = 0; j < esp_vetorial; ++j){
			printf(" %.16Lf", vetores[i][j]);
		}
		printf("\n");
	}
}

long double prod_escalar(long double *a, long double *b){
	long double out = 0;
	for(int i = 0; i < esp_vetorial; ++i){
		out += a[i] * b[i];
	}
	return out;
}

void sub_vec(long double *a, long double *b){//subtrai b em a
	long double out = 0;
	for(int i = 0; i < esp_vetorial; ++i){
		a[i] -= b[i];
	}
	return;
}

void vec_multp(long double a, long double *v){
	//printf("ver recebe: %Lf", a);
	for(int i = 0; i < esp_vetorial; ++i){
		v[i] *= a;
	}
	return;
}

void ortogonizador(){
	for(int i = 1; i < n_vecs; ++i){
		for(int j = 0; j < i; ++j){
			memcpy(ortogonaliando, vetores[j], sizeof(long double) * esp_vetorial);
			//printf("divide = %Lf %Lf\t", prod_escalar(vetores[j], vetores[i]), prod_escalar(vetores[j], vetores[j]));
			vec_multp((	prod_escalar(vetores[j], vetores[i])/
						prod_escalar(vetores[j], vetores[j])	), ortogonaliando);
			sub_vec(vetores[i], ortogonaliando);
		}
	}
}

void ortonormalizador(){
	for(int i = 0; i < n_vecs; ++i){
		vec_multp( (1 / sqrtl(prod_escalar(vetores[i], vetores[i])) ) , vetores[i]);
	}
}
int main(){
	printf("Digite o tamanho do espaço vetorial, e a quantidade de elementos:\n");
	scanf("%u%u", &esp_vetorial, &n_vecs);
	aloca_e_le();
	ortogonizador();
	printf("Vetores ortogonais:\n");
	imprime();
	ortonormalizador();
	printf("Vetores ortonormais:\n");
	imprime();
	return 0;
}