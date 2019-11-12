#include <bits/stdc++.h>
using namespace std;
int main(){
    set<int> liga[100005];
    int n, m, t, a, b;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d", &t, &a, &b);
        if(t == 0){
            printf("%d\n", liga[a].find(b) != liga[a].end());
        }else{
            liga[a].insert(b);
            liga[b].insert(a);
        }
    }
    return 0;
}