#include <bits/stdc++.h>
using namespace std;
int main(){
	int d, n, sle, j, siz, topri;
	deque<char>num;
	char rmv[112345];
	//int rmvqnt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	scanf("%d%d", &n, &d);
	while (d != 0 && n != 0){
		topri = n-d;
        j = 0;
		scanf(" %[^\n]", rmv);
        num.push_back(rmv[0]);
        for(int i = 1; i < n; ++i){
            //int mini = rmv[i], pos = i;
            siz = num.size();
            while(siz && d){
                if(rmv[i] > num.back()){
                    d--;
					num.pop_back();
                }else break;
				siz--;
            }
			num.push_back(rmv[i]);
			//cout<<rmv[i]<<'\t';
        }
        //////////////////////////////////
		n = num.size();
		for (int i = 0; i < topri; ++i){
			printf("%c", num[i]);
		}
		num.clear();
		printf("\n");
		scanf("%d%d", &n, &d);
	}
	return 0;
}