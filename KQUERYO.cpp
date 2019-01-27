#include <bits/stdc++.h>

using namespace std;

#define SIZE 100001
#define LEFT(n) (n << 1)
#define RIGHT(n) ((n << 1) + 1)
#define MID(left, right) (left + ((right - left) >> 1))

vector<int> segment[SIZE << 2];
int data[SIZE];

void build(int node, int left, int right) {
	if(left == right) {
		segment[node].push_back(data[left]);
		return;
	}

	build(LEFT(node), left, MID(left, right));
	build(RIGHT(node), MID(left, right) + 1, right);
	merge(segment[LEFT(node)].begin(), segment[LEFT(node)].end(), segment[RIGHT(node)].begin(), segment[RIGHT(node)].end(), back_inserter(segment[node]));
}

int query(int node, int left, int right, int x, int y, int k) {
	if(left > y || right < x) {
		return 0;
	}

	if(left >= x && right <= y) {
		return segment[node].end() - upper_bound(segment[node].begin(), segment[node].end(), k);
	}

	return query(LEFT(node), left, MID(left, right), x, y, k) + query(RIGHT(node), MID(left, right) + 1, right, x, y, k);
}

int main(int argc, char const *argv[])
{
	int n, q;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &data[i]);
	}

	build(1, 1, n);
    
    scanf("%d", &q);
    int ans = 0, l, r, k;

	while(q--) {
		scanf("%d%d%d", &l, &r, &k);

        l ^= ans;
        r ^= ans;
        k ^= ans;
        ans = query(1, 1, n, l, r, k);

		printf("%d\n", ans);
	}
	
	return 0;
}