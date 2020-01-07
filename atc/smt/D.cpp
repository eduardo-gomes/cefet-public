#include <bits/stdc++.h>
using namespace std;
int test(const char *num, char *tr){
	char *last = tr;
	for(int i = 0; i < 3; ++i){
		last = strchr(last, num[i]);
		//cout << num << i << ' ' << tr << '\n';
		if(last == NULL) return 0;
		last++;
	}
	return 1;
}
int main(){
	int sum = 0, d;
	char num[4] = {0, 0, 0, '\0'}, str[30004];
	cin >> d >> str;
	for(int x0 = '0'; x0 <= '9'; ++x0){
		num[0] = x0;
		for (int x1 = '0'; x1 <= '9'; ++x1){
			num[1] = x1;
			for (int x2 = '0'; x2 <= '9'; ++x2){
				num[2] = x2;
				sum += test(num, str);
			}
		}
	}
	cout << sum << '\n';
}