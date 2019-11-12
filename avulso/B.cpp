#include <bits/stdc++.h>
void (*ftype[10])(const void *);
void *data[10];
int next = 0, end = 10;
void chama(int i){
	(ftype[i])(data[i]);
}
void print_str(const void *st){
	printf("%s\n", (char*) st);
}
void vai_pra(const void *i){
	int to = *((int*)i);
	printf("vai_pra: %d\n", to);
	next = to;
}
void (*func)(const void *) = NULL;

int main(){
	for(int i = 0; i < 10; ++i){
		ftype[i] = &print_str;
		data[i] = malloc(sizeof(char) * 255);
		scanf("%[^\n]%*c", (char*)data[i]);
	}
	ftype[6] = &vai_pra;
	data[6] = malloc(sizeof(int));
	*((int*)data[6]) = 8;
	printf("\nStart\n");
	while(next < end){
		chama(next++);
	}
}