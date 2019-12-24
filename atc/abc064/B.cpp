#include <bits/stdc++.h>
using namespace std;
int maxi = 0, mini = INT_MAX;
int main(){
	int n, read;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> read;
		mini = min(mini, read);
		maxi = max(maxi, read);
	}
	cout << maxi - mini << endl;
}