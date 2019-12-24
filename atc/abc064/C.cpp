#include <bits/stdc++.h>
using namespace std;
int escolhem[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int main(){
	int read, mini, maxi, n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> read;
		int atu = read/400;
		if(atu > 8) atu = 8;
		escolhem[atu]++;
	}
	mini = 0;
	for(int i = 0; i < 8; ++i){
		if(escolhem[i]) mini++;
	}
	maxi = mini + escolhem[8];
	if(mini == 0 && escolhem[8] > 0) mini = 1;
	cout << mini << ' ' << maxi << endl;
}