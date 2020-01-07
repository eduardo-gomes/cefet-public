#include <bits/stdc++.h>
#define tax 1.08
using namespace std;
int main(){
	int x, qnt = -1, iup, ido;
	double up, down;
	cin >> x;
	up = (double)x / tax;
	down = floor(up);
	up = ceil(up);
	iup = floor(up * tax);
	ido = floor(down * tax);
	//cout << up << ' ' << down;
	if(iup == x) qnt = up;
	else if(ido == x) qnt = down;
	if(qnt > 0){
		cout << qnt << "\n";
	}else
		cout << ":(\n";
	return 0;
}