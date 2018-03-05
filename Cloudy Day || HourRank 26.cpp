#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

typedef long long ll;
const int INF = 2e9+10;

const int N = 2e5;
const int M = 1e5;
const int X = 1e9;

int p[N];
int x[N];

int y[M];
int r[M];

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    assert(n >= 1 && n <= N);

    FOR(i, n) cin >> p[i];
    FOR(i, n) assert(p[i] >= 1 && p[i] <= X);

    FOR(i, n) cin >> x[i];
    FOR(i, n) assert(x[i] >= 1 && x[i] <= X);

    int m;
    cin >> m;
    assert(m >= 1 && m <= M);

    FOR(i, m) cin >> y[i];
    FOR(i, m) assert(y[i] >= 1 && y[i] <= X);

    FOR(i, m) cin >> r[i];
    FOR(i, m) assert(r[i] >= 1 && r[i] <= X);


    map<pii, int> tmp;
    FOR(i, n) tmp.insert(mp(mp(x[i], i), 0));
    ll total_killed_anyway = 0;
    FOR(i, m)
    {
        int low = y[i] - r[i];
        int high = y[i] + r[i] + 1;
        auto it1 = tmp.lower_bound(mp(low, -1));
        auto it2 = tmp.upper_bound(mp(high, -1));

        while(it1 != tmp.end() && it1 != it2)
        {
            int cid = it1->fi.se;
            it1->se++;
            if(it1->se == 2)
            {
                total_killed_anyway += p[cid];
                auto it3 = it1;
                ++it1;
                tmp.erase(it3);
            }
            else
            {
                ++it1;
            }
        }
    }
    vector<pii> cities;
    for(auto it = tmp.begin(); it != tmp.end(); ++it) cities.pb(mp(it->fi.fi, it->fi.se));
    sort(ALL(cities));

    ll all_unique_kills = 0;
    ll best = -1;
    FOR(i, m)
    {
        ll tmp = 0;
        int low = y[i] - r[i];
        int high = y[i] + r[i] + 1;
        auto it1 = lower_bound(ALL(cities), mp(low, -1));
        auto it2 = upper_bound(ALL(cities), mp(high, -1));

        while(it1 != cities.end() && it1 != it2)
        {
            int cid = it1->se;
            tmp += p[cid];
            ++it1;
        }
        all_unique_kills += tmp;
        REMAX(best, tmp);
    }
    ll total_people = 0;
    FOR(i, n) total_people += p[i];
    cout << total_people - total_killed_anyway - all_unique_kills + best << endl;
    return 0;
}
//https://www.hackerrank.com/contests/hourrank-26/challenges/cloudy-day
