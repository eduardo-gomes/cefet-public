#include <bits/stdc++.h>
using namespace std;
const int A = 0x2B375;
const int B = 0xF6DA;
const int n = 0xEDEDE;//32 bit
const int g = 0xEDU;
long long pow(int b, int p){
	long long po = 1;
	for(int i = 0; i < p; ++i){
		po = (po * b) % n;
	}
	return po;
}
int main(){
	cout<<"Alice a "<<A<<" g "<<g<<" n "<<n<<"\n";
	cout<<"Bob b"<<B<<" receives g and n\n";
	int ga = pow(g, A) % n;
	cout<<"Alice send ga g^a%n "<<ga<<'\n';
	int gb = pow(g, B) % n;
	cout<<"Bob send gb g^b%n "<<gb<<'\n';
	int sa = pow(ga, B) % n;
	cout<<"Alice calc s = gb^a%n "<<sa<<'\n';
	int sb = pow(gb, A) % n;
	cout<<"Bob calc s = ga^b%n "<<sb<<'\n';


}