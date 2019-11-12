#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    int qnt, t;
    scanf("%d", &qnt);
    for(int i = 0; i < qnt; ++i){
        scanf("%d", &t);
        s.insert(t);
    }
    printf("%lu\n", s.size());
}