#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char yes[] = "Yes\n";
const char no[] = "No\n"; 
char **toalloc(int n){
	char **aloc = malloc(sizeof(char*)*n);
	for(int i = 0; i < n; ++i){
		aloc[i] = malloc(sizeof(char)*n+5);
	}
	return aloc;
}
void read(char **vetor, int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf(" %c", &vetor[i][j]);
		}
	}
	return;
}
int main(){
	int m, n, found = 0, sposi;
	char **a, **b, *start;
	scanf("%d%d", &n/*A*/, &m/*B*/);
	a = toalloc(n);
	b = toalloc(m);
	read(a, n);
	read(b, m);
	//search
	for(int lin = 0; lin < n; ++lin){
		for(int col = 0; col < n; ++col){
			if(lin + m -1> n || col + m -1> n) continue;
			found = 1;
			for(int lb = 0; lb < m; ++lb){
				for(int cb = 0; cb < m; ++cb){
					if(a[lin+lb][col+cb] != b[lb][cb]){
						found = 0;
						break;
					}
					if(!found) break;
				}
				if(!found) break;
			}
			if(found) break;
		}
		if(found) break;
	}
	printf("%s", found ? yes: no);
	return 0;
}