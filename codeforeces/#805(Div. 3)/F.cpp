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

int t;
int n;

void solve(){
    n = read();
    multiset<int> a, b;
    for(int i=0;i<n;i++){
        int x = read();
        while(x%2==0)x/=2;
        a.insert(x);
    }

    for(int i=0;i<n;i++){
        int x = read(); b.insert(x);
    }

    while(!b.empty()){
        // max value of b
        int x = *b.rbegin();
        if(!a.count(x)){
            // cannot find x
            if(x==1) break;
            b.erase(b.find(x));b.insert(x/2);
        }
        else{
            // find x
            a.erase(a.find(x)); b.erase(b.find(x));
        }
    }
    if(b.empty()) printf("YES\n");
    else printf("NO\n");

}

int main(){
    //ios::sync_with_stdio(false);
    t = read();
    while(t--){
        solve();
    }
}