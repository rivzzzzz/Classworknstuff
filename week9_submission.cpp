#include <iostream>
// #include <fstream>
#include <string.h>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <queue>
// gcc --std=c++17 q1.cpp -o q1 &&./q1
using namespace std;
/*shortcuts*/
#define ll long long
#define ld long double
#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
// #define sz(x) (int)((x).size())
#define pii pair<int, int>
#define rep(a, b) for (int i = a; i <= b; i++)
#define forn(i, b) for (int i = 0; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define mset(v2, v1) memset(v2, v1, sizeof(v2))
#define display(v) \
  for (auto i : v) \
    cout << i << " "; \
  cout << "\n";
#define fi first
#define se second
// #define endl '\n'
#define quick                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define decimal                     \
  cout << fixed << setprecision(9); 

const int MAX_N = 4e5 + 1;
const int N = 3e5 + 10;
const ll MOD = 998244353;
const ll mod = 1e9 + 7;
const ll INF = 1e17;
const int inf = 1e9;

ll n, m, k, w;
//char s[N], ts[N];

string s;
ll l, r, L, R;

bool isPrime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        } 
    }
    return true;
}


void solve(){
    cin >> n;
    if(n <= 2 || n & 2 != 0){
        return;
    }
    vector<pair<int, int>> a;
    for(int i = 2; i <= n / 2; i++){
        int p1 = i;
        int p2 = n - i;
        if(isPrime(p1) && isPrime(p2)){
            a.pb({p1, p2});
        }
    }

    for(auto pair: a){
        cout << pair.fi << " " << pair.se << "\n";
    }
    cout << "\nBonus: \n";
    
    pair<int, int> largestPair = {0, 0};
    int mx = -1;
    for(auto pair : a){
        if(abs(pair.fi - pair.se) > mx){
            mx = abs(pair.fi - pair.se);
            largestPair = pair;
        }
    }

    cout << largestPair.fi << " " << largestPair.se;

}

int main()
{ 
//   quick int tc = 1; 
//   cin >> tc;
//   for (int t = 1; t <= tc; t++)
//   {
//     // cout << "Case #" << t  << ": ";
//     solve();
//   } 
    solve();
}
