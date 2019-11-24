#include <stdio.h>
#include <math.h>
typedef struct cord{
	int x;
	int y;
} cord;
int main(){
	cord town[8];
	long double sum = 0.0;
	int n, r1, r2, fact = 1;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &r1, &r2);
		town[i].x = r1;
		town[i].y = r2;
	}
	for(int i = 0; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			if(i == j) continue;
			sum += sqrtl(powl(town[i].x - town[j].x, 2) + powl(town[i].y - town[j].y, 2));
		}
	}
	sum = sum*2/n;
	printf("%.10Lf\n", sum);
}