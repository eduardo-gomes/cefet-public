#include <bits/stdc++.h>
using namespace std;
vector<int> num;
vector<int> change;
int qnum;
int main(){
	int n, rd, mx = 0, last;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &rd);
		num.push_back(rd);
	}
	sort(num.begin(), num.end());
	change.push_back(0);
	last = num[0];
	int sz = num.size();
	for(int i = 0; i < sz; ++i){
		if(num[i] != last){
			last = num[i];
			change.push_back(i);
		}
	}
	num.push_back(INT_MAX);
	for(int i = 0; i < 4; ++i) change.push_back(sz);
	sz = change.size();
	qnum = num[0];
	for(int i = 0; i < sz - 2; ++i){
		int st = change[i], ed = change[i+1];
		qnum = num[change[i]];
		if (num[change[i+1]] - qnum <= 2)
			ed = change[i+2];
		if (num[change[i + 2]] - qnum <= 2)
			ed = change[i + 3];
		mx = max(mx, ed - st);
	}
	printf("%d\n", mx);
}