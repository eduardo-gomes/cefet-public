#include <stdio.h>
#include <stdlib.h>
//	todo list, verificar qual é melhor 1 -1 1 ou -1 1 -1
//	alocacao dinamica
//	end
int sinal(int a){
	if(a < 0) return -1;
	return 1;
}
int main(){
	int n, sum = 0, read;
	long long int alt = 0;
	scanf("%d%d", &n, &sum);
	for(int i = 1; i < n; ++i){
		//printf("%d\t", sum);read = sum;
		scanf("%d", &read);
		if(i == 1 && sum == 0){//se o primeiro for zero
			if(read >= 0){
				sum = -1;
			}else{
				sum = 1;
			}
			alt = 1;
		}
		//if(i == 1)printf("%d ", sum);
		int tosum = -sinal(sum) -sum - read;
		if(sum + read != 0){
			if(sinal(sum) != sinal(sum + read)){
				sum += read;
				//printf("%d ", read);
				continue;
			}
		}else{
			tosum = -sinal(sum);
		}
		//printf("alt%d ", alt);
		alt += abs(tosum);
		sum += tosum + read;
		//printf("%d ", read + tosum);

	}
	printf("%lld\n", alt);
}