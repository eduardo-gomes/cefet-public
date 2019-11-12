#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
	char num[15];
	long long n, found;
	scanf("%lld", &n);
	found = n;
	long long root = ceil(sqrt(n));
	for(int i = 2; i <= root; ++i){
		if(n%i == 0){
			found = n/i;
		}
	}
	sprintf(num, "%lld", found);
	printf("%ld\n", strlen(num));
	return 0;
}