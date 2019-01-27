#include <bits/stdc++.h>
#define SIZE 1000002

using namespace std;

int prime[(SIZE >> 6) + 2];
vector<int> p;

#define CHECK(n) (prime[n >> 6] & (1 << ((n & 63) >> 1)))
#define SET(n) (prime[n >> 6] |= (1 << ((n & 63) >> 1)))

void sieve() {
	int root = sqrt(SIZE);
	p.push_back(2);

	for(int i = 3; i < SIZE; i += 2) {
		if(CHECK(i) == false) {
            p.push_back(i);

            if(i <= root) {
                for(int j = i * i; j < SIZE; j += i << 1) {
                    SET(j);
                }
            }
		}
	}
}

int bigMod(string n, int m) {
	int mod = 0;

	for(int i = 0; n[i]; i++) {
		mod = (mod * 10 + n[i] - '0') % m;
	}

	return mod;
}

int main()
{
	sieve();
	string k;
	int l, length = p.size();

	while(cin >> k >> l && l) {
        bool ck = true;

        for(int i = 0; i < length && p[i] < l; i++) {
            if(bigMod(k, p[i]) == 0) {
                ck = false;
                l = p[i];
                break;
            }
        }

        if(ck) {
            puts("GOOD");
        } else {
            printf("BAD %d\n", l);
        }
	}

	return 0;
}
