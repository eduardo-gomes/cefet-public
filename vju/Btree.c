#define MOD 998244353
#define MAX 100005
#include <stdio.h>
#include <string.h>
int nivel[MAX];
int max(int b, int a){
	return a > b ? a: b;
}
long long int ans = 1;
int main(){
	memset(nivel, 0, sizeof(int) * MAX);
	int n, maxl = 0, read;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &read);
		maxl = max(maxl, read);
		nivel[read]++;
	}
	for(int i = 1; i <= maxl; ++i){
		if(nivel[0] != 1){
			ans = 0;
			break;
		}
		for(int j = 0; j < nivel[i]; ++j){
		ans = (ans * (nivel[i-1])) % MOD;
		}
	}
	printf("%lld\n", ans);
}