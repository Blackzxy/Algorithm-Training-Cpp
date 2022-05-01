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
int n;
vector<int> nums;

bool compare(int a,int b){
    string v1 = to_string(a) + to_string(b);
    string v2 = to_string(b) + to_string(a);
    return v1>v2;
}

int main(){
    //ios::sync_with_stdio(false);
    n = read();
    for(int i=0;i<n;i++){
        int tmp = read();
        nums.push_back(tmp);
    }
    sort(nums.begin(),nums.end(),compare);
    //for(int i=0;i<n;i++)cout<<nums[i]<<" ";
    bool check_zero = true;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0)continue;
        else{
            check_zero = false;
            break;
        }
    }
    if(check_zero){cout<<"0"<<endl;}
    else{
        string ans = "";
        for(int i=0;i<nums.size();i++){
            ans = ans+to_string(nums[i]);
        }
        cout<<ans<<endl;
    }
}