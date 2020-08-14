/*
Testa para todos os numeros de 0 a 2^9-1 se é possivel obter o or
a & b nao pode ter nenhum bit que nao esteja em d = (c1|...|cn)
a&b | d = d
*/

#include <bits/stdc++.h>

std::vector<int> a, b;

bool tryThis(int x) {
	for (auto ai : a){
		bool foundForThis_ai = false;
		for (auto bi : b){
			if (((ai & bi) | x) == x){
				foundForThis_ai = true;
				break;
			}
		}
		if(!foundForThis_ai) return 0;
	}
	return 1;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int tmp;
		std::cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < m; ++i) {
		int tmp;
		std::cin >> tmp;
		b.push_back(tmp);
	}
	int min;
	for (int i = 0; i < (1 << 9); ++i) {
		if (tryThis(i)) {
			min = i;
			break;
		}
	}
	std::cout << min << std::endl;
}