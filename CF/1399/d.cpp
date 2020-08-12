#include <bits/stdc++.h>

#define STR_LIMIT (int)(3 * 1e5)

void read(char (&to)[STR_LIMIT], unsigned int n) {
	char tmp;
	for(unsigned i = 0; i < n; ++i){
		scanf(" %c", &to[i]);
	}
	to[n] = 0;
}


int main(){
	int cases, len;
	scanf("%d", &cases);
	char str[STR_LIMIT];
	std::vector<int> pos0, pos1, ans;
	for(int i = 0; i < cases; ++i){
		ans.clear();
		pos0.clear();
		pos1.clear();
		scanf("%d", &len);
		read(str, len);
		for(int j = 0; j < len; ++j){
			int newPos = pos0.size() + pos1.size() + 1;
			if(str[j] == '1'){
				if(pos0.empty())
					pos1.push_back(newPos);
				else{
					newPos = pos0.back();
					pos0.pop_back();
					pos1.push_back(newPos);
				}
			}else{
				if (pos1.empty())
					pos0.push_back(newPos);
				else {
					newPos = pos1.back();
					pos1.pop_back();
					pos0.push_back(newPos);
				}
			}
			ans.push_back(newPos);
		}
		printf("%ld\n", pos0.size() + pos1.size());
		for(int j = 0; j < len; ++j){
			printf("%s%d", (j ? " " : ""), ans[j]);
		}
		printf("\n");
	}
}