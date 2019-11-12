#include <bits/stdc++.h>
using namespace std;
int main(){
	int c, n, t, d, qnt = 0, last;
	priority_queue<int> caixas;
	scanf("%d%d", &c, &n);
	for(int i = 0; i < c; ++i) caixas.push(0);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &t, &d);
		last = -caixas.top();
		caixas.pop();
		if(last - t > 20) qnt++;
		if(last < t){
			last = t+d;
		}else{
			last += d;
		}
		caixas.push(-last);
	}
	printf("%d\n", qnt);
	return 0;
}