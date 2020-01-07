#include <bits/stdc++.h>
using namespace std;
vector<int> num;
int main(){
	int n, rd, count = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &rd);
		num.push_back(rd);
	}
	for(int i = 0; i < n-1; ++i){
		if(num[i] == i+1 && num[i+1] == i+2){
			swap(num[i], num[i+1]);
			count++;
		}
	}
	for(int i = 0; i < n-1; ++i){
		if(num[i] == i+1 || num[i+1] == i+2){
			swap(num[i], num[i+1]);
			count++;
		}
	}
	printf("%d\n", count);
}