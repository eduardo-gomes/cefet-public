#include <bits/stdc++.h>

int main(){
	int count;
	long long int n;
	scanf("%d", &count);
	for(int i = 0; i < count; ++i){
		scanf("%lld", &n);
		printf("%lld\n", n/2 + 1);
	}
	return 0;
}