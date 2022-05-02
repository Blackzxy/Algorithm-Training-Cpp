// 区间更新 单点查询
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




int n,q;
const int N = 1e6+5;
ll a[N], b[N];
ll c[N];

ll lowbit(int x){return x&(-x);}

void update(int i, ll k){
    // add k on i-th position
    while(i<=N){
        c[i]+=ll(k); i+= lowbit(i);
    }
}
ll get_sum(int i){
    // get sum from 1-i
    ll ans = 0;
    while(i>0){
        ans+=ll(c[i]);i-=lowbit(i);
    }
    return ans;
}

int main(){
    //ios::sync_with_stdio(false);
    n = read();q = read();
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        b[i] = a[i]-a[i-1];
        update(i,b[i]);
    }
    while(q--){
        int tmp = read();
        if(tmp==1){
            int l=read(),r = read();
            ll x;scanf("%lld",&x);
            update(l,x);update(r+1,-x);
        }
        else{
            int pos = read();
            cout<<get_sum(pos)<<endl;
        }
    }
    
}