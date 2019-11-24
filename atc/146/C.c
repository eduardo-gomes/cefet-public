#include <stdio.h>
#include <string.h>
const long long nums[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
long long bs(long long maxnum, long long minnum, long long lim, long long a){
	long long meio = (maxnum + minnum)/2;
	if((maxnum - minnum) == 1){
		if((maxnum * a) > lim) return minnum;
		else return maxnum;
	}
	if(maxnum == minnum) return maxnum;
	else if((meio * a) == lim) return meio;
	else{
		if((meio * a) < lim) return bs(maxnum, meio, lim, a);
		else return bs(meio, minnum, lim, a);
	}
}
int main(){
	long long a, b, x, res = 0;
	scanf("%lld%lld%lld", &a, &b, &x);
	int maxi = 0;
	for(int i = 1; i < 10; ++i){
		if((a * nums[i] + b * (i+1)) > x) break;
		maxi = i;
	}// b * i fixed
	if(!((a + b) > x)){
		//bs
		long long maxnum = nums[maxi]*10 -1, minnum = nums[maxi];
		maxnum = maxnum > nums[9] ? nums[9]: maxnum;
		res = bs(maxnum, minnum, (x-b*(maxi+1)), a);
	}
	printf("%lld\n", res);
}