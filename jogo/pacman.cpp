#include <bits/stdc++.h>
#include <ncurses.h>
using namespace std;
/*int mapa[9][7] = {
{-1, -1, -1,-1, -1, -1, -1},
{-1, 0, 0, 0, 0, 0, -1},
{-1, 0, -1, 0, -1, 0, -1},
{0, 0, -1, 0, -1, 0, 0},
{-1, 0, -1, 0, -1, 0, -1},
{0, 0, -1, 0, -1, 0, 0},
{-1, 0, -1, -1, -1, 0, -1},
{-1, 0, 0, 0, 0, 0, -1},
{-1, -1, -1, -1, -1, -1, -1}};
int mapaori[9][7] = {
	{-1, -1, -1, -1, -1, -1, -1},
	{-1, 0, 0, 0, 0, 0, -1},
	{-1, 0, -1, 0, -1, 0, -1},
	{0, 0, -1, 0, -1, 0, 0},
	{-1, 0, -1, 0, -1, 0, -1},
	{0, 0, -1, 0, -1, 0, 0},
	{-1, 0, -1, -1, -1, 0, -1},
	{-1, 0, 0, 0, 0, 0, -1},
	{-1, -1, -1, -1, -1, -1, -1}};*/
bool vivo = 1;
int mapadist[20][19], mapa[20][19] = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
				{-1, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, -1},
				{-1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, 0, -1},
				{-1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1},
				{-1, -1, -1, -1, 0, -1, 0, -1, -1, 0, -1, -1, 0, -1, 0, -1, -1, -1, -1},
				{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
				{-1, 0, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, 0, -1},
				{-1, 0, -1, 0, -1, 0, 0, -1, 0, -1, -1, -1, 0, 0, -1, 0, -1, 0, -1},
				{-1, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, -1},
				{-1, 0, -1, 0, -1, 0, 0, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1, 0, -1},
				{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
				{-1, 0, 0, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, -1},
				{-1, 0, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, 0, -1},
				{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
				{-1, 0, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, 0, -1},
				{-1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1},
				{-1, 0, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, 0, -1},
				{-1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, 0, 0, -1},
				{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
				{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
struct posidire{
	int x;
	int y;
	int dx;
	int dy;
};
struct posi{
	int x;
	int y;
};
posi dire[4] = {{.x = 0, .y = 1}, {.x = 1, .y = 0}, {.x = 0, .y = -1}, {.x = -1, .y = 0}};
posi mapas = {.x = 19, .y = 20};
posi player = {.x = 1, .y = 1};
posi p1dire = {.x = 1, .y = 0};
posidire inimi[3] = {{.x = 9, .y = 8, .dx = 1, .dy = 0}, {.x = 9, .y = 8, .dx = 1, .dy = 0}, {.x = 9, .y = 8, .dx = 1, .dy = 0}};
void printmapa(){
	move(0, 0);
	for(int i = 0; i < mapas.y; ++i){
		for(int j = 0; j < mapas.x; ++j){
			if(mapa[i][j] == -1){
				printw("#");
			}else if (mapa[i][j] == 0){
				if(i == player.y && j == player.x){
					printw("@");
				}else{
					printw(" ");
				}
			}
		}
		printw("\n");
	}
	refresh();
}
void playerdist(){
	for(int i = 0; i < mapas.y; ++i){
		memcpy(mapadist[i], mapa[i], sizeof(int) * mapas.x);
	}
	queue<pair<int, int> > fila;
	fila.push(make_pair(player.y, player.x));
	int dst = 0;
	mapadist[player.y][player.x] = 0;
	while(!fila.empty()){
		pair<int, int> now = fila.front();
		fila.pop();
		for(int i = 0; i < 4; ++i){
			if(mapadist[now.first + dire[i].y][now.second + dire[i].x] == 0){
				fila.push(make_pair(now.first + dire[i].y, now.second + dire[i].x));
				mapadist[now.first + dire[i].y][now.second + dire[i].x] = dst++;
			}
		}
	}
}
int inimicanchange(int ini){
	int count = 0;
	for(int i = 0; i < 4; ++i){
		if(mapa[inimi[ini].y + dire[i].y][inimi[ini].x + dire[i].x] != -1) count++;
	}
	return count;
}
void inimirand(int ini){
	int rd = rand() % 4;
	if(inimi[ini].dy == -dire[rd].y && inimi[ini].dx == -dire[rd].x && inimicanchange(ini) > 2) return;
	inimi[ini].dy = dire[rd].y;
	inimi[ini].dx = dire[rd].x;
}
void moveinimi(int ini){
	if (mapa[inimi[ini].y + inimi[ini].dy][inimi[ini].x + inimi[ini].dx] == -1)	{
		while (mapa[inimi[ini].y + inimi[ini].dy][inimi[ini].x + inimi[ini].dx] == -1){
			inimirand(ini);
		}
	}
	inimi[ini].y += inimi[ini].dy;
	inimi[ini].x += inimi[ini].dx;
	if(inimicanchange(ini) > 2) inimirand(ini);
}
void iniAI(int ini){
	if(inimicanchange(ini) > 2){
		for(int i = 0; i < 4; ++i){
			if (mapadist[inimi[ini].y][inimi[ini].x] > mapadist[inimi[ini].y + dire[i].y][inimi[ini].x + dire[i].x] && mapa[inimi[ini].y + dire[i].y][inimi[ini].x + dire[i].x] != -1){
				inimi[ini].dy = dire[i].y;
				inimi[ini].dx = dire[i].x;
			}
		}
	}
	moveinimi(ini);
}
void printinimi(int ini){
	attron(COLOR_PAIR(ini+1));
	mvprintw(inimi[ini].y, inimi[ini].x, "$");
	attroff(COLOR_PAIR(ini+1));
	move(0, 0);
}
int death(){
	for(int i = 0; i < 3; ++i){
		if (player.x == inimi[i].x && player.y == inimi[i].y){
			return 1;
		}
	}
	return 0;
}
void p1anda(){
	if(mapa[player.y + p1dire.y][player.x +p1dire.x] == 0){
		player.x += p1dire.x;
		player.y += p1dire.y;
	}
}
void procentrada(char ent){
	printf("%c", ent);
	if(ent == 's'){
		p1dire.x = 0;
		p1dire.y = 1;
		return;
	}
	if(ent == 'w'){
		p1dire.x = 0;
		p1dire.y = -1;
		return;
	}
	if(ent == 'a'){
		p1dire.x = -1;
		p1dire.y = 0;
		return;
	}
	if(ent == 'd'){
		p1dire.x = 1;
		p1dire.y = 0;
		return;
	}
}
void printa(){
	printmapa();
	printinimi(0);
	printinimi(1);
	printinimi(2);
}
clock_t t = clock(), ini1 = clock(), ini2 = clock(), ini3 = clock() + CLOCKS_PER_SEC * 10;
void inimigos(){
	if(clock() > ini1 + CLOCKS_PER_SEC * 0.2){
		moveinimi(0);
		printa();
		ini1 = clock();
	}
	if(clock() > ini2 + CLOCKS_PER_SEC * 0.15){
		moveinimi(1);
		printa();
		ini2 = clock();
	}
	playerdist();
	if(clock() > ini3 + CLOCKS_PER_SEC * 0.02){
		//moveinimi(2);
		iniAI(2);
		printa();
		ini3 = clock();
	}
}
int main(){
	char pressed, last;
	initscr();
	timeout(0);
	noecho();
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	while(vivo){
		pressed = getch();
		if(pressed >= 'a' && pressed <= 'z'){
			procentrada(pressed);
			//break;
			//printf("%c", pressed);
		}
		//printw("a");
		if(clock() > t + CLOCKS_PER_SEC * 0.1){
			p1anda();
			printa();
			t = clock();
		}
		inimigos();
		if (death())
			vivo = !vivo;
		if(pressed == ';') break;
	}
	if(!vivo){
		clock_t endcoold = clock() + CLOCKS_PER_SEC * 3;
		while(endcoold > clock());
	}
	endwin();
}