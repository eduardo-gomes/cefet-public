#include <bits/stdc++.h>

/*
Make all emement on each vector equal nimimal cost:
- Find minimum of each since only can remove itens
- If neet to remove both from one gift remoe together

*/

int main() {
	int cases;
	std::vector<int> a, b;
	scanf("%d", &cases);
	while(cases--){
		int gifts;
		scanf("%d", &gifts);
		a.clear();
		b.clear();
		long long int cost = 0;

		{//read
			for(int i = 0; i < gifts; ++i){
				int tmp;
				scanf("%d", &tmp);
				a.push_back(tmp);
			}
			for(int i = 0; i < gifts; ++i){
				int tmp;
				scanf("%d", &tmp);
				b.push_back(tmp);
			}
		}

		{//calc cost
			int mina = *std::min_element(a.begin(), a.end()), minb = *std::min_element(b.begin(), b.end());
			long long int cost_this_gift = 0;
			for(int i = 0; i < gifts; ++i){
				int this_a = a[i], this_b = b[i];
				int dif_a = this_a - mina, dif_b = this_b - minb; //this >= min
				cost_this_gift += std::max(dif_a, dif_b);
			}
			cost += cost_this_gift;
		}
		printf("%lld\n", cost);
	} //end case
	return 0;
}
