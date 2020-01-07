#include <bits/stdc++.h>
using namespace std;
int main(){
	char str[110];
	scanf("%s", str);
	char st, last;
	int len = strlen(str)-2;
	st = str[0];
	last = str[strlen(str)-1];
	printf("%c%d%c\n", st, len, last);
	return 0;
}