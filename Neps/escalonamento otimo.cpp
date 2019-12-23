#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dependencia; //dep...[x] = {y}, x vem antes de y
vector<int> grau;
vector<int> ordem;
set<int> proximos_disp;
int main(){
	int n, m;
	cin >> n >> m;
	dependencia.resize(n);
	grau.resize(n, 0);
	int x, y;
	for(int i = 0; i < m; ++i){
		cin >> x >> y;
		grau[y]++;
		dependencia[x].push_back(y);
	}

	for(int i = 0; i < n; ++i) if(grau[i] == 0) proximos_disp.insert(i);//adicionas os que ja podem começar

	while(!proximos_disp.empty()){
		int atual = *proximos_disp.begin();
		proximos_disp.erase(proximos_disp.begin());
		ordem.push_back(atual);

		for(auto i: dependencia[atual]){
			grau[i]--;
			if(grau[i] == 0) proximos_disp.insert(i);
		}
	}

	if(ordem.size() < n) cout << "*\n";
	else{
		for(auto i: ordem) cout << i << endl;
	}
}