#include <stdio.h>
unsigned long long mi(unsigned long long a, unsigned long long b){
	return a < b ? a: b;
}
int main(){
	unsigned long long int bars[200005], sum[200005], min;
	int n;
	scanf("%d", &n);
	//scanf("%llu", &bars[1]);
	sum[0] = 0;
	//sum[1] = bars[1];
	for(int i = 1; i <= n; ++i){
		scanf("%llu", &bars[i]);
		sum[i] = sum[i-1] + bars[i];
		//printf("%llu ", sum[i]);
	}
	min = sum[n];
	unsigned long long u, dif, j;
	for(int i = 1; i < n; ++i){
		j = sum[i];//<-
		u = sum[n] > j ? sum[n] - j : j - sum[n]; //positive//->
		dif = u > j ? u - j: j - u;//positive
		//printf("%d %llu %llu %llu\n", i, u, j, dif);
		min = mi(min, dif);
	}
	printf("%llu\n", min);
}