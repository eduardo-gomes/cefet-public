#include <stdio.h>
int main(){
	int earn = 0, x, y, ganha[] = {400000, 300000, 200000, 100000};
	scanf("%d%d", &x, &y);
	if(x < 4)
		earn += ganha[x];
	if(y < 4)
		earn += ganha[y];
	if(x == y && x == 1)
		earn += ganha[0];
	printf("%d\n", earn);
}