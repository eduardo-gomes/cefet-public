#include <stdio.h>
#include <string.h>
int main(){
	char entrada[10], *dia[8] = {"", "SAT", "FRI", "THU", "WED", "TUE", "MON", "SUN"};
	int resp = 0;
	scanf("%s", entrada);
	for(int i = 0; i < 8; ++i){
		if(strcmp(dia[i], entrada) == 0){
			resp = i;
			break;
		}
	}
	printf("%d\n", resp);
}