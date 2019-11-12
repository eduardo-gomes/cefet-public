#include <stdio.h>
int main(){
	int k, s, qnt = 0;
	scanf("%d%d", &k, &s);
	for(int x = 0; x <= k; ++x){
		for(int y = 0; y <= k; ++y){
			int z = s - x - y;
			//printf("%d %d %d\n", x, y, z);
			if(z >=0 && z <= k)qnt++;
		}
	}
	printf("%d\n", qnt);
}