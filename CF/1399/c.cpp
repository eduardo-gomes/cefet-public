#include <bits/stdc++.h>

/*
Find the s that maximize the number of teams to find n of teams
*/

int main() {
	int cases;
	scanf("%d", &cases);
	std::vector<int> w;
	while(cases--){
		w.clear();
		int n;
		scanf("%d", &n);


		for(int i = 0; i < n; ++i){//read
			int tmp;
			scanf("%d", &tmp);
			w.push_back(tmp);
		}

		std::sort(w.begin(), w.end());

		unsigned max_pairs = 0;
		{//find s and max_pairs
			int max_s = w.back() * 2;
			for(int s = 2; s <= max_s; ++s){
				int st = 0, ed = w.size()-1;
				unsigned int pairs = 0;
				while(st < ed){//count pairs
					if(w[st] + w[ed] == s){
						pairs++;
						st++;
						ed--;
					} else if (w[st] + w[ed] > s) ed--;
					  else if (w[st] + w[ed] < s) st++;
				}

				max_pairs = std::max(max_pairs, pairs);
			}
		}
		printf("%u\n", max_pairs);

	}
	return 0;
}
