#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

vector<vector<int>> matrizadj;
int main(){
	int n, m;
	cin >> n >> m;
	matrizadj.resize(n);
	for(int i = 0; i < n; ++i) matrizadj[i].resize(n, INF);
	for(int i = 0; i < n; ++i) matrizadj[i][i] = 0;
	for(int i = 0; i < m; ++i){
		int a, b, peso;
		cin >> a >> b >> peso;
		a--;
		b--;
		if(peso < matrizadj[a][b])
			matrizadj[a][b] = matrizadj[b][a] = peso;
	}
	//Algoritmo de Floyd-Warshall
	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				matrizadj[i][j] = min(matrizadj[i][j], matrizadj[i][k] + matrizadj[k][j]);
				//dist i-j = min i-j, i-k-j
	vector<int> maiordistfrom;
	maiordistfrom.resize(n, 0);
	int mindst = INF;
	for(int i = 0; i < n; ++i){
		for(auto j: matrizadj[i])
			maiordistfrom[i] = max(maiordistfrom[i], j);
		mindst = min(mindst, maiordistfrom[i]);
	}
	cout << mindst << endl;
}