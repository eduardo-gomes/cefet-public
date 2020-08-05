#include <bits/stdc++.h>

int main(){
	int cases, n, tmp;
	std::vector<int> a;
	scanf("%d", &cases);
	while(cases--){
		a.clear();
		scanf("%d", &n);
		while(n--){
			scanf("%d", &tmp);
			a.push_back(tmp);
		}
		std::sort(a.begin(), a.end());
		int last = a.front();
		bool result = true;
		for(int i = 1; i < a.size(); ++i){
			if(a[i] - last > 1){
				result = false;
				break;
			}
			last = a[i];
		}
		printf("%s\n", (result ? "YES" : "NO"));
	}
	return 0;
}