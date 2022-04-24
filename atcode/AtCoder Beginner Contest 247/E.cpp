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

const int N = 2e5 + 5;
int a[N];
int X,Y;
int n;
ll res=0;

ll cal(vector<int> &vec){
    ll ans=0;
    int l = 0, r = vec.size()-1;
    int lp=l,rp=l;
    int cnt_max=0, cnt_min = 0;
    //int len = r-l+1;
    while(lp<=r){
        while(rp<=r && (cnt_max==0 || cnt_min==0)){
            if(vec[rp]==X)cnt_max+=1;
            if(vec[rp]==Y)cnt_min+=1;
            rp+=1;
        }
        if(cnt_max>0 && cnt_min>0){
            ans = ans+ll(r-rp+2);
        }
        if(vec[lp]==X)cnt_max-=1;
        if(vec[lp]==Y)cnt_min-=1;
        lp+=1;
    }
    return ans;
}

void sol(){
    int i=0;
    int st=0,ed=0;
    while(i<n){
        // split to subproblem
        vector<int> vec;
        while(i<n && a[i]<=X && a[i]>=Y){vec.push_back(a[i]);i+=1;}
        if(vec.size()>0){
            res+= cal(vec);
        }
        else i+=1;
        
    }
}


int main(){
    //ios::sync_with_stdio(false);
    n = read();
    X = read(); Y = read();
    for(int i=0;i<n;i++) a[i] = read();
    sol();
    printf("%lld\n", res);
    system("pause");
}