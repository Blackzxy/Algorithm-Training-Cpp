#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<bitset>
#include<ctime>
#include<deque>
#include<stack>
#include<functional>
#include<sstream>
typedef long long ll;
using namespace std;
typedef unsigned long long int ull;
#define maxn 200005
#define ms(x) memset(x,0,sizeof(x))
#define Inf 0x7fffffff
#define inf 0x3f3f3f3f
const int mod = 1e9 + 7;
#define pi acos(-1.0)
#define pii pair<int,int>
#define eps 1e-5
#define pll pair<ll,ll>
#define lson 2*x
#define rson 2*x+1

long long  qupower(int a, int b) {
	long long  ans = 1;
	while (b) {
		if (b & 1)ans = ans * a;
		b >>= 1;
		a = a * a;
	}
	return ans;
}

inline int read() {
	int an = 0, x = 1; char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') {
			x = -1; 
		}
		c = getchar();
	}
	while (c >= '0'&&c <= '9') {
		an = an * 10 + c - '0'; c = getchar();
	}
	return an * x;
}

int n,m;
const int N = 2e5+3;
ll a[N];
ll dp[N][2];
ll sum[N];
int q[N];
// dp[i][0] = max(dp[i-1][0],dp[i-1][1])
// dp[i][1] = max(sum[i]-sum[j])
ll MAX = -inf;
int main(){
    //ios::sync_with_stdio(false);
    n =read(); m  =read();
	dp[0][0] = dp[0][1] = -inf;
	for(int i=1;i<=n;i++){
		scanf("%lld", &a[i]);
		sum[i] = ll(sum[i-1]+a[i]);
		MAX = max(MAX, a[i]);
		dp[i][0] = dp[i][1]=-inf;
	}
	//cout<<MAX<<endl;
	int head=0,tail=0;
	q[head]=0;q[tail]=0;
	for(int i=1;i<=n;i++){
		dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
		while(head<tail && i-q[head]>m)++head;
		dp[i][1] = sum[i]-sum[q[head]];
		while(head<=tail && -sum[i]>-sum[q[tail]])--tail;
		q[++tail] = i;
	}
	cout<<ll(max(MAX,max(dp[n][0],dp[n][1])))<<endl;
}