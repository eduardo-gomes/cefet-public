#include <bits/stdc++.h>

//need to know after eache event if there is 4 pair and 2 equal

int nums[112345];
int quad = 0, pairs = 0;
inline void add(int x){
	nums[x]++;
	if(nums[x] % 4 == 0)
		++quad;
	if(nums[x] % 2 == 0)
		++pairs;
}
inline void rm(int x){
	if(nums[x] % 4 == 0)
		--quad;
	if (nums[x] % 2 == 0)
		--pairs;
	nums[x]--;
}

int main(){
	memset(nums, 0, sizeof(nums));
	int count, tmp;
	scanf("%d", &count);
	for(int i = 0; i < count; ++i){
		scanf("%d", &tmp);
		add(tmp);
	}
	int changes;
	scanf("%d", &changes);
	char type;
	for (int i = 0; i < changes; ++i) {
		scanf(" %c %d", &type, &tmp);
		if(type == '+')
			add(tmp);
		else
			rm(tmp);
		printf("%s\n", ((quad && pairs >= 4) ? "YES" : "NO"));
	}
	return 0;
}