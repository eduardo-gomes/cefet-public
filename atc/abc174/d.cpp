#include <bits/stdc++.h>

int main() {
	int n, count = 0;
	char cor[200001];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf(" %c", &cor[i]);
	bool vai = 1;
	unsigned int st = 0, ed = n - 1;
	while (vai) {
		while (cor[st] != 'W') {
			st++;
			if (st == ed) vai = false;
		}
		if (!vai) break;
		while (cor[ed] != 'R') {
			ed--;
			if (st == ed){
				vai = false;
				break;
			}
		}
		if (!vai) break;
		char _1st = cor[st], _2nd = cor[ed];
		cor[st] = _2nd;
		cor[ed] = _1st;
		count++;
	}
	printf("%d\n", count);
	return 0;
}