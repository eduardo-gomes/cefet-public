#include <bits/stdc++.h>

short int board[101][101] = {0};//zero initialize

int main() {
	int sizeX, sizeY, x, y;
	std::cin >> sizeX >> sizeY >> x >> y;
	x--;
	y--;
	board[x][y] = 1;
	std::cout << x + 1 << ' ' << y + 1 << std::endl;
	{// go to corner
		y = 0;
		board[x][y] = 1;
		std::cout << x + 1 << ' ' << y + 1 << std::endl;
		x = 0;
		board[x][y] = 1;
		std::cout << x + 1 << ' ' << y + 1 << std::endl;
	}
	int step = 1;
	for(;;){
		if (x + step >= 0 && x + step < sizeX){
			x += step;
		}else{
			step = -step;
			if (y + 1 < sizeY) {
				y++;
			} else break;//end
		}
		if (board[x][y]) continue;//only happens tho times and aren't on the side borders
		std::cout << x + 1 << ' ' << y + 1 << std::endl;
		board[x][y] = 1;
	}

}
