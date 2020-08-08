#include <bits/stdc++.h>

//need to know after eache event if there is 4 pair and 2 equal

int nums[112345], repets[112345];
inline void add(int x){
	++nums[x];
	++repets[nums[x]];
}
inline void clearFor(){
	memset(nums, 0, sizeof(nums));
	memset(repets, 0, sizeof(repets));
}
unsigned findLast(){
	unsigned last = 1;
	while(repets[++last] > 0);
	return last-1;
}
int sumRepets(unsigned x){
	int sum = 0;
	for(unsigned i = 1; i < x; ++i)
		sum += repets[i];
	return sum;
}

int main(){
	int cases;
	scanf("%d", &cases);
	for(int i = 0; i < cases; ++i){
		int size;
		scanf("%d", &size);
		clearFor();
		for(int j = 0; j < size; ++j){
			int tmp;
			scanf("%d", &tmp);
			add(tmp);
		}
		unsigned maxRepeats = findLast();
		unsigned maxMinDist = (sumRepets(maxRepeats) / (maxRepeats - 1)) - 1;
		//" It is guaranteed that each bag contains at least two patty-cakes with the same filling. "
		printf("%u\n", maxMinDist);
	}
	return 0;
}