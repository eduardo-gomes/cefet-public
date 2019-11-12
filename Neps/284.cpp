#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> calls;
	deque<int> hold_on;
	priority_queue<pair <int, int>> next;
	pair<int, int> tmp;
	int n, l, read;
	scanf("%d%d", &n, &l);
	calls.resize(n);
	for(int i = 0; i < n; ++i) next.push(make_pair(0, -i));
	/*for(int i = 0; i < n; ++i){
		printf("\t%d %d\n", next.top().first, next.top().second);
		next.pop();
	}
	for (int i = 0; i < n; ++i)
		next.push(make_pair(0, -i));*/
	for(int i = 0; i < l; ++i){
		scanf("%d", &read);
		hold_on.push_back(read);
		tmp = next.top();
		next.pop();
		tmp.first -= hold_on.front();
		hold_on.pop_front();
		calls[-tmp.second]++;
		next.push(tmp);
	}
	for(int i = 0; i < n; ++i){
		printf("%d %d\n", i+1, calls[i]);
	}
	return 0;
}