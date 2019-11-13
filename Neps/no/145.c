#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num[10];
int main(){
	memset(num, 0, sizeof(int) * 10);
	char a[100];
	int c;
	scanf("%d", &c);
	for(int i = 0; i < c; ++i){
		scanf(" %[^\n]", a);
		for(int i = 0; i < strlen(a); ++i){
			num[a[i]-'0']++;
		}
	}
	for(int i = 0; i < 10; ++i){
		printf("%d - %d\n", i, num[i]);
	}
	return 0;
}