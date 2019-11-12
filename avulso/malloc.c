#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int soma(int *a, int *b){
	return *a + *b;
}
int sub(int *a, int *b){
	return *a - *b;
}
int prod(int *a, int *b){
	return *a * *b;
}

int main(){
	int (*func)(int*, int*);
	void *f[] = {&soma, &sub, &prod};
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i = 0; i < 3; ++i){
		func = f[i];
		printf("%d\n", (*func)(&a, &b));
	}
	return 0;
}