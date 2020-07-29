#include <bits/stdc++.h>

int main(){
	int n;
	scanf("%d ", &n);
	while(n--){
		char string[1010];
		fgets(string, 1010, stdin);
		//-1 = -"\n"
		int len = strlen(string)-1, cost = 0, one = 0, zero = 0;
		for(int i = 0; i < len; ++i)
			if(string[i] == '0')
				++zero;
			else
				++one;
		int trocas = 0, atual = string[0];
		for (int i = 0; i < len - 1; ++i)
			if (string[i] != atual){
				++trocas;
				atual = string[i];
			}
		//0000111, 1110000, 000, 111 good
		//00000000000011110101010100000000000000000000001
		int zerosum[1010], one1sum[1010];
		zerosum[0] = one1sum[0] = 0;
		for(int i = 0; i < len; ++i){
			zerosum[i + 1] = zerosum[i];
			one1sum[i + 1] = one1sum[i];
			if(string[i] == '0')
				++zerosum[i+1];
			else
				++one1sum[i+1];
		}
//n of 0 0123456789ABCCCCCDDEEFF00123456789ABCDEF01234566//0x36 54
//n of 1 000000000000012344556677888888888888888888888889// 9
		//st 0 termina 1/0 ou st 1 termina 0/1
		//0 to 1
	//	 0 <-X-> 1 cost to every number before be 0 and after be 1
		// X = number of 1 before + number of zero after or 1 after and 0 before
	//	 00000000000000000000000076543210FEDCBA98765432101
		
		//cost to
		int zerobeg[1010], one1beg[1010];
		for(int i = 0; i < len + 1; ++i){//0123 1000
			zerobeg[i] = one1sum[i] + zerosum[len+1] - zerosum[i];	 //01|01 1 before + 0 after
			one1beg[i] = zerosum[i] + one1sum[len+1] - one1sum[i];	 //01|01 0 before + 1 after
		}
		//001
		//
		int min = INT_MAX;
		/*for (int i = 0; i < len + 1; ++i)
			printf("%d", zerobeg[i]);
		printf("\n");
		for (int i = 0; i < len + 1; ++i)
			printf("%d", one1beg[i]);
		printf("\n");*/
		for (int i = 0; i < len + 1; ++i) {
			min = std::min(min, std::min(zerobeg[i], one1beg[i]));
		}
		printf("%d\n", min);
	}
}