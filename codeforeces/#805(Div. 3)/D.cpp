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
string s;
int p;

int map_to_int(char x){
    return x-'a'+1;
}

vector<char> vec;
map<char,int> mp;

int cal_sum(string s){
    int n = s.length();
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += (s[i]-'a'+1);
    }
    return ans;
}

int main(){
    //ios::sync_with_stdio(false);
    t = read();
    while(t--){
        cin>>s;
        int comp = cal_sum(s);
        cin>>p;
        if(p>=comp) cout<<s<<endl;
        
        else{
            vec.clear(); mp.clear();
            string ans="";
            int n = s.length();
            int Min = 30;
            for(int i=0;i<n;i++)vec.push_back(s[i]), Min = min(Min,map_to_int(s[i]));
            if(Min>p){
                cout<<""<<endl;
            }
            else{
                sort(vec.begin(),vec.end()); reverse(vec.begin(),vec.end());
                for(int i=0;i<n;i++){
            //    cout<<vec[i]<<" ";
                    if(comp-map_to_int(vec[i])<=p){
                        mp[vec[i]]++; break;
                    }
                    mp[vec[i]]++;comp -= map_to_int(vec[i]);
                }
                for(int i=0;i<n;i++){
                    if(mp[s[i]]==0){
                        ans = ans+s[i];
                    }
                    else mp[s[i]]--;
                }
                cout<<ans<<endl;
            }
        }
    }
}