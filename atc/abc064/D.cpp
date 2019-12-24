#include <bits/stdc++.h>
using namespace std;

deque<int> working;
int num = 0;
int main(){
	int n;
	char read;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf(" %c", &read);
		if(read == '(') read = 1;
		else if(read == ')') read = -1;
		//else continue;
		if(num == 0 && read == -1){
			working.push_front(1);
			num++;
		}
		working.push_back(read);
		num += read;
	}
	for(int i = 0; i < num; ++i) working.push_back(-1);
	for(auto k: working){
		cout << (k == 1 ? "(": ")");
	}
	cout << endl;
}