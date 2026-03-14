#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[20][200][2];
string s;

ll dfs(int pos, int sum, bool tight, int k) {
    if (sum > k) return 0;
    if (pos == s.size()) return sum == k;

    if (dp[pos][sum][tight] != -1) return dp[pos][sum][tight];

    int limit = tight ? (s[pos] - '0') : 9;
    ll res = 0;

    for (int d = 0; d <= limit; d++) {
        res += dfs(pos + 1, sum + d, tight && (d == limit), k);
    }

    return dp[pos][sum][tight] = res;
}

ll countDigitSum(ll n, int k) {
    if(!n) return 0;
    s = to_string(n);
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, true, k);
}
