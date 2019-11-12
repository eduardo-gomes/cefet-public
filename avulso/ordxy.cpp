#include<iostream>
#include<cstdlib>
using namespace std;
struct par{
    int x;
    int y;
};

int compara(const void* st, const void* nd){
    par a = *(par*)st, b = *(par*)nd;
    if(a.y < b.y) return -1;
    if(a.y > b.y) return 1;
    if(a.x < b.x) return -1;
    if(a.x > b.x) return 1;
    return 0;
}

int main(){
    int n, x,y;
    cin>>n;
    par vetor[n];
    for(int i = 0; i < n; ++i){
        cin>>x>>y;
        vetor[i].x=x;
        vetor[i].y=y;
    }
    qsort(vetor, n, sizeof(par), compara);
    for(int i = 0; i < n; ++i){
        cout<<vetor[i].x<<" "<<vetor[i].y<<'\n';
    }
    return 0;
}