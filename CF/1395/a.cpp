#include <bits/stdc++.h>

int main(){
	int t, r, g, b, w;
	std::cin >> t;
	for(int i = 0; i < t; ++i){
		std::cin >> r >> g >> b >> w;
		int maxOperations = std::min(r, std::min(g, b));
		int colorOdds = r%2 + g%2 +b%2;//if 2 can change to 1, if 3 can change to 0
		bool isWiteOdd = w%2;//toggle with each operation
		bool possible = (colorOdds + isWiteOdd) <= 1;
		if(maxOperations > 0) possible |= ((colorOdds^3) + (isWiteOdd^1)) <= 1;
		std::cout << (possible ? "Yes" : "No") << std::endl;
	}
}