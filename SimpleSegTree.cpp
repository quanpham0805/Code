#include    <bits/stdc++.h>
#define     ll long long
#define     ull unsigned long long
#define     ld long double
#define     prec(k) fixed << setprecision(k)
#define     up(i, k, n) for (int i = k ; i < n ; i ++)
#define     down(i, k, n) for (int i = k ; i >= n ; i --)
#define     ii pair<int, int>
#define     pll pair <ll, ll>
#define     X first
#define     Y second
#define     str basic_string <int>
const int maxN = (int) 1e4 + 7;
const int maxM = (int) 1e5 + 7;
const int maxT = (int) 1e6 + 7;

using namespace std;

int n, q, a[maxM * 2], g, h; char y;
int node[maxT], leaf[maxT];

void Build(int x, int l, int r)
{
    if (l == r)
    {
        node[x] = a[l];
        leaf[l] = x;
    }
    else
    {
        int mid = l + r >> 1;
        Build(2 * x, l, mid), Build(2 * x + 1, mid + 1, r);
        node[x] = min (node[2 * x], node[2 * x + 1]);
    }
}

void enter()
{
    cin >> n >> q;
    up(i, 1, n + 1) cin >> a[i];
    Build(1, 1, n);
}

int Query(int x, int Start, int End, int l, int r)
{
    if (r < Start || l > End) return maxT;
    if (l <= Start && End <= r) return node[x];
    int mid = Start + End >> 1;
    return min (Query(2 * x, Start, mid, l, r), Query(2 * x + 1, mid + 1, End, l, r));
}

void Update(int id, int val)
{
    int x = leaf[id];
    a[id] = val;
    node[x] = val;
    for (x /= 2 ; x > 0 ; x /= 2)
    node[x] = min(node[2 * x], node[2 * x + 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    enter();
    while (q --)
    {
        cin >> y >> g >> h;
        switch(y)
        {
            case 'q': cout << Query(1, 1, n, g, h) << '\n'; break;
            case 'u': Update(g, h); break;
        }
    }

    return 0;
}
