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
// char s[N], ts[N];

string s;

vector<vector<char>> a = vector<vector<char>>(3, vector<char>(3, ' '));

bool check(int player){
  char temp = ' ';
  temp = (player == 1) ? 'X' : 'O';
  for (int i = 1; i < 7; i += 2) {
    if ((a[i][1] == temp && a[i][3] == temp && a[i][5] == temp) ||
        (a[1][i] == temp && a[3][i] == temp && a[5][i] == temp)) {
        return true;
    }
  }
  if ((a[1][1] == temp && a[3][3] == temp && a[5][5] == temp) ||
      (a[1][5] == temp && a[3][3] == temp && a[5][1] == temp)) {
      return true;
  }
  return false;
}


void solve() {
  int cnt = 1;
  a = vector<vector<char>>(7, vector<char>(7, ' '));
  forn(i, 7){
    forn(j, 7){
      if((i == 1 || i == 3 || i == 5) && (j == 1 || j == 3 || j == 5)){
        continue;
      }
      a[i][j] = '+';
    }
  }
  cout << "\nGame start\n";
  map<pair<int, int>, int> mp;
  mp.clear();
  bool end = false;
  while(!end){
    int player_id = (cnt & 1) ? 1 : 2;
    cout << "Player " << player_id << ", please make your move (row then col, do not enter as a pair like (1, 2)): \n";
    int row, col;
    bool entry = false;
    while(!entry){
      cin >> row >> col;
      if(mp[make_pair(row, col)]){
        cout << "Please try another spot, this spot already has a mark\n";
      } else if (row > 3 || row < 1 || col > 3 || col < 1){
        cout << "Invalid input (value out of bound), please try again\n";
      } else {
        break;
      }
    }
 
    mp[make_pair(row, col)] = 1;

    int temp_row = 1, temp_col = 1;
    if(row == 2){temp_row = 3;} 
    else if(row == 3) temp_row = 5;
    else temp_row == 1;
    if(col == 2){ temp_col = 3;}
    else if(col == 3) temp_col = 5;
    else temp_col == 1;

    a[temp_row][temp_col] = (player_id == 1) ? 'X' : 'O';

    forn(i, 7){
      cout << "\n";
      forn(j, 7){
        cout << (a[i][j]);
      }
    }
    cout << "\n\n";
    if(check(player_id)){
      cout << "Player " << player_id << " has won, congrats!\n";
      end = true;
      break;
    } 
    cnt++;

    if(cnt == 10){
      cout << "It's a draw\n";
      end = true;
      break;
    }
  }
  
  if(end){
    cout << "\nWanna play again?\n";
    cin >> s;
    if(s == "yes" || s == "Yes" || s == "yEs" || s == "yeS" || s == "YES"){
      solve();
    } else{
      cout << "Thank you for playing this game";
    }
  }

}

int main()
{ 
  // quick int tc = 1; 
  // cin >> tc;
  // for (int t = 1; t <= tc; t++)
  // {
  //   // cout << "Case #" << t  << ": ";
  //   solve();
  // }
  solve();
}
