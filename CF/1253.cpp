//#include <stdio.h>
//#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
	int st = 1;
	unsigned long long sum = 0;
	unsigned long long doces[200005], add[200005];
	int m, n;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%d", &doces[i]);
	}
	sort(&doces[0], &doces[n]);
	for(int i = 0; i < n; ++i){
		if(i < m)
			add[i] = doces[i];
		else
			add[i] = doces[i] + add[i - m];
		sum += add[i];
		if(!st){
			printf(" ");
		}else st = !st;
		printf("%lld", sum);
	}
	printf("\n");
}