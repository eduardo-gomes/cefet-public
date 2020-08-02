#include <bits/stdc++.h>

int main(){
	int n, d, count = 0;
	scanf("%d%d", &n, &d);
	long long int x, y;
	for(int i = 0; i < n; ++i){
		scanf("%lld%lld", &x, &y);
		count += (sqrt(x*x + y*y) <= d);
	}
	printf("%d\n", count);
	return 0;
}