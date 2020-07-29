#include <iostream>

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		int numbers, select, impar, par;
		scanf("%d %d", &numbers, &select);
		impar = par = 0;
		while(numbers--){
			int read;
			scanf("%d", &read);
			if(read%2)
				++impar;
			else
				++par;
		}
		//odd number of odds
		//odd > 0, odd selected is odd
		int selected = select > par ? par : select;
		int resta = select - selected;//<= select
		if(resta%2 == 0 && (resta == impar || selected == 0))//no
			printf("No\n");
		else
		printf("Yes\n");
	}
}