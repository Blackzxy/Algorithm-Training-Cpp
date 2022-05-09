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

int n,K,X;
const int N = 2e5 + 5;
ll a[N];
ll cnt[N], mod_[N];
ll sum=0;

int main(){
    //ios::sync_with_stdio(false);
    n = read(); K = read(); X = read();
    
    for(int i=0;i<n;i++)scanf("%lld",&a[i]), sum += a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)cnt[i] = a[i]/X, mod_[i] = a[i]%X;
    ll tot_cnt = 0;
    for(int i=0;i<n;i++)tot_cnt += cnt[i];
    
    if(tot_cnt >= K){
        cout<<(ll)(sum - (ll)K*X)<<endl;
    }
    else{
        // more coupons
        ll ans = sum - (ll)tot_cnt*X;
        K -= tot_cnt;
        sort(mod_,mod_+n);
        for(int i=n-1;i>=0;i--){
            if(K==0)break;
            ans = ans-mod_[i];
            K--;
        }
        cout<<ans<<endl;
    }
}