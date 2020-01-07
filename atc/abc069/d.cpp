#include <bits/stdc++.h>
using namespace std;
vector<int> cores;
vector<vector<int>> grid;
int main(){
	int h, w, n, rd;
	int ph = 0, pw = 0, sentido = 1;
	cin >> h >> w >> n;
	for(int i = 0; i < n; ++i){
		cin >> rd;
		cores.push_back(rd);
	}
	grid.resize(h);
	for(int i = 0; i < h; ++i){
		grid[i].resize(w);
	}
	for(int i = 0; i < n; ++i){
		int k = cores[i]; 
		for(int j = 0; j < k; ++j){
			grid[ph][pw] = i+1;
			if(pw + sentido >= w || pw + sentido < 0){
				sentido = -sentido;
				ph++;
			}
			else pw += sentido;
		}
	}
	for(auto i: grid){
		bool st = 1;
		for(auto j: i){
			if(!st) cout<<' ';
			else st = 0;
			cout<< j;
		}
		cout << endl;
	}
	return 0;
}