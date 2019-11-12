#include <stdio.h>
char string[512345];int num[512345];
long long sum = 0;
int maxv(int a, int b){
	//return a > b ? a: b;
	if(a <= b){
		return b-a;
	}
	return a;
}
char last; int pos = 0; int lnum = 1; int volta = 0;
int funcao(/*char last, int pos, int lnum, int volta*/){// volta = seq start;
	//printf("%c %d %d %d %d\n", last, pos, lnum, volta, num[volta]);
	//if(pos > 10) return -1;
	if(string[pos+1] != last){
		num[pos] = lnum;
		if(last == '<'){
			last = '>';
			volta = pos;
			pos++;
			lnum = 0;
			//funcao();
		}else{
			//printf("sa%d\n", sum);
			sum += ((lnum)*(lnum+2))/2;//pa
			//printf("sa%d\n", sum);
			sum += maxv(num[volta], lnum+1) +1;
			//printf("sd%d\n", sum);
			last = '<';
			pos++;
			lnum = 0;
			volta = 0;
			//funcao();
		}
		if(string[pos/*+1*/] == '\0') return -1;
		return 1;
	}else{
		if(last == '<'){
			//printf("else\n");
			sum += ++lnum;
			pos++;
			//lnum++;
			//funcao();
		}else{
			pos++;
			lnum++;
			//funcao();
		}
		return 1;
	}
}

int main(){
	scanf(" %s", string);
	num[0] = 0;
	last = string[0];
	while(funcao() == 1);
	printf("%lld\n", sum);
	return 0;
}