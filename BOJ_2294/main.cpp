#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

constexpr auto INF = numeric_limits<ll>::max() / 2;

int n, k;
vi vals;
vl dp;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> k;
	vals = vi(n);
	for (auto&& x : vals) {
		cin >> x;
	}

	dp = vl(k + 1, INF);
	dp[0] = 0;

	for (auto i = 0; i < vals.size(); ++i) {
		for (auto j = vals[i]; j <= k; ++j) {
			dp[j] = min(dp[j], dp[j - vals[i]] + 1);
		}
	}

	if (INF == dp[k]) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}

	return 0;
}