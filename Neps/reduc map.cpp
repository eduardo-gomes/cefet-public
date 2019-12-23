#include <bits/stdc++.h>
using namespace std;
struct rua{
	int pes;
	int x, y;
};
bool comp_rua(rua a, rua b){
	return a.pes < b.pes;
}
deque<rua> ruas;
vector<int> pai;
vector<int> dist;
int find(int x){
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}
void join(int x, int y){
	x = find(x);
	y = find(y);
	if(dist[x] < dist[y])
		pai[x] = y;
	else if (dist[x] > dist[y])
		pai[y] = x;
	else{
		pai[y] = x;//y esta em x
		dist[x]++;
	}
}
int suma = 0;
int main(){
	int n, m;
	cin >> n >> m;
	dist.resize(n + 1, 0);
	//pai.resize(n + 1);
	for(int i = 0; i <= n; ++i) pai.push_back(i);
	rua nova;
	for(int i = 0; i < m; ++i){
		cin>> nova.x >> nova.y >> nova.pes;
		ruas.push_back(nova);
	}
	sort(ruas.begin(), ruas.end(), comp_rua);
	while(!ruas.empty()){
		rua atual = ruas.front();
		ruas.pop_front();
		if(find(atual.x) != find(atual.y)){
			join(atual.x, atual.y);
			suma += atual.pes;
		}
	}
	cout<< suma << '\n';
}