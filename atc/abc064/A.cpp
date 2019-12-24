#include <bits/stdc++.h>
using namespace std;
int main(){
	char read[4];
	scanf(" %c %c %c", &read[0], &read[1], &read[2]);
	read[3] = 0;
	int num;
	sscanf(read, "%d", &num);
	printf("%s\n", num%4 == 0 ? "YES" : "NO");
}