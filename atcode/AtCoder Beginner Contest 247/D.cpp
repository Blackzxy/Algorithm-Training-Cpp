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

int Q;
//queue<ll> q;
ll ans = 0;
const int N = 2e5+5;
ll v[N],pos[N];
ll cnt=1;
ll cur_p = 1;
ll real_p = 0;


int main(){
    //ios::sync_with_stdio(false);
    Q = read();
    while(Q--){
        int q; q = read();
        if(q==1){
            ll x,c; scanf("%lld %lld", &x,&c);
            pos[cnt] = pos[cnt-1]+c;
            v[cnt] = x;
            cnt+=1;
        }
        else{
            ll c; scanf("%lld", &c);
            ll next_p = real_p+c;
            //cout<<"next pos:"<<next_p<<endl;
            ans=0;
            for(;cur_p<cnt;cur_p++){
                if(pos[cur_p]<=next_p){
                    ans+= ll(v[cur_p]*(pos[cur_p]-real_p));
                    real_p = pos[cur_p];
                }
                else{
                    ans+= ll(v[cur_p]*(next_p-real_p));
                    real_p = next_p;
                    break;
                }

            }
            
            //cout<<real_p<<endl;
            printf("%lld\n", ans);
        }
    }
}