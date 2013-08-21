#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define s(n)                         scanf("%d",&n)
#define sc(n)                        scanf("%c",&n)
#define sl(n)                        scanf("%lld",&n)
#define sf(n)                        scanf("%lf",&n)
#define ss(n)                        scanf("%s",n)
#define scana(a,t)                   for(int i = 0; i < t; i++){cin >> a[i];}

#define FOR(i,a,b)                       for(int i=a;i<b;i++)
#define FOREACH(v, c)                for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define REP(i,a)                     for (int i=0; i<a; i++)

#define all(a)                        a.begin(), a.end()
#define in(a,b)                       ( (b).find(a) != (b).end())
#define pb                            push_back
#define fill(a,v)                     memset(a, v, sizeof a)
#define sz(a)                         ((int)(a.size()))

#define maX(a,b)                      ( (a) > (b) ? (a) : (b))
#define miN(a,b)                      ( (a) < (b) ? (a) : (b))
#define PI                                acos(-1)
#define sqr(x)                            ((x) * (x))

#define p(n)                          printf("%d\n",n)
#define pl(n)                         printf("%lld\n",n)
#define pul(n)                        printf("%llu\n", n);
#define pf(n)                         printf("%f\n",n)
#define pc(n)                         printf("%c\n",n)
#define ps(n)                         printf("%s\n",n)

#define sort(x)                       sort(all(x))

#define DEBUG(x)                          { cerr << #x << " = " << x << endl; }
#define PR(a,n)                           {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n)                          {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}

#define numTest(t)                    int t; s(t); while(t--)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;

typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;

typedef vector<string> VS;
typedef vector<VS> VVS;

inline __int64 get_sum(const vector<__int64> &sum, int l, int r)
{
        return (l == 0) ? sum[r] : (sum[r] - sum[l - 1]);
}

int main()
{
        #ifndef ONLINE_JUDGE
                freopen ("in.txt", "r", stdin);
                // freopen ("out.txt", "w", stdout);
        #endif
        int n, k;
        scanf("%d %d", &n, &k);
        vector<__int64> a(n), sum(n);
        scanf("%I64d", &a[0]);
        sum[0] = a[0];
        for (int i = 1; i < n; ++i)
        {
                scanf("%I64d", &a[i]);
                sum[i] = sum[i - 1] + a[i];
        }
        pair<int, int> ans = make_pair(n - 2 * k, n - k);
        // PR0(sum,n);
        // DEBUG(ans.first);
        // DEBUG(ans.second);

        __int64 ans_sum = get_sum(sum, n-2*k, n-k-1) + get_sum(sum, n-k, n-1);
        // DEBUG(ans_sum);
        pair<int, __int64> suff_max = make_pair(n - k, get_sum(sum, n-k, n-1));
        for (int i = n-2*k-1; i >= 0; --i)
        {
                __int64 cur = get_sum(sum, i + k, i + 2*k - 1);
                if (cur >= suff_max.second)
                        suff_max = make_pair(i + k, cur);
                cur = get_sum(sum, i, i + k - 1) + suff_max.second;
                if (cur >= ans_sum)
                {
                        ans_sum = cur;
                        ans = make_pair(i, suff_max.first);
                }
        }
        printf("%d %d\n", ans.first + 1, ans.second + 1);
        return 0;
}
