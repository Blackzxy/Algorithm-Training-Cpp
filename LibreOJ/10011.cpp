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
const int N = 1e5+5;
int x[N];
int ans = 0;

bool check(int ans){
    int cnt=1;
    int st = x[1];
    //cout<<st<<" ";
    for(int i=2;i<=n;i++){
        if(x[i]-st<ans)continue;
        else{
            cnt++;st=x[i];
            //cout<<st<<" ";
        }
    }
    if(cnt>=m)return true;
    return false;
}

int main(){
    //ios::sync_with_stdio(false);
    n = read(); m = read();
    for(int i=1;i<=n;i++)x[i] = read();
    sort(x+1,x+1+n);
    int l=1,r = x[n];
    int mid;
    while(l<r){
        mid = (l+r)>>1;
        //cout<<"l:"<<l<<" "<<"r:"<<r<<endl;
        if(check(mid)){
        //    cout<<"mid:"<<mid<<endl;
            l = mid+1;
            ans = max(ans,mid);
            //cout<<"l:"<<l<<endl;
        }
        else r = mid;
        //cout<<l<<endl;
    }
    cout<<ans<<endl;
}