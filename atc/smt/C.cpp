#include <bits/stdc++.h>
using namespace std;
int custo[] = {100, 101, 102, 103, 104, 105};
vector<int> resto;
int fpd(int resta){
	if(resto[resta] != -1)
		return resto[resta];
	if(resta < 100)
		return resto[resta] = resta;
	if(resta == 0)
		return resto[resta] = 0;
	for(int i = 0; i < 6; ++i){
		if(resta >= custo[i]){
			if (resta - custo[i] < 0) continue;
			if(fpd(resta - custo[i]) == 0)
				return resto[resta] = 0;
		}
	}
	return resto[resta] = 1;
}
int main(){
	int x;
	cin >> x;
	resto.resize(x + 10, -1);
	cout << !fpd(x) << '\n';
}