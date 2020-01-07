#include <bits/stdc++.h>
using namespace std;
int main(){
	int md4 = 0, md2 = 0, md1 = 0, n, rd;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &rd);
		if(rd%4 == 0)
			md4++;
		else if(rd%2 == 0)
			md2++;
		else
			md1++;
	}
	if(md1 <= md4 || (md1 <= md4+1 && md2 == 0)){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	//printf("%d %d %d\n", md1, md2, md4);
	return 0;
}