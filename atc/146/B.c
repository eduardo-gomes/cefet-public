#include <stdio.h>
#include <string.h>
int main(){
	char intra[10004];
	int shift;
	scanf("%d %s", &shift, intra);
	for(int i = 0; intra[i] != '\0'; ++i){
		intra[i] = ((intra[i]-'A') + shift)%26 + 'A';
	}
	printf("%s\n", intra);
}