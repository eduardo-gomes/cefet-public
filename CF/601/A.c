#include <stdio.h>
#include <stdlib.h>
int main(){
	int sum, n, a, b, dif;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		sum = 0;
		scanf("%d%d", &a, &b);
		dif = abs(b - a);
		sum += dif / 5;
		dif = dif % 5;
		sum += dif / 2;
		dif = dif % 2;
		sum += dif;
		printf("%d\n", sum);
	}
	return 0;
}