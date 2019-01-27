#include <bits/stdc++.h>
#define SIZE 100000002

using namespace std;

int isPrime[(SIZE >> 6) + 2];
vector<int> prime;

#define CHECK(n) (isPrime[n >> 6] & (1 << ((n & 63) >> 1)))
#define SET(n) (isPrime[n >> 6] |= (1 << ((n & 63) >> 1)))

void sieve() {
    int root = sqrt(SIZE);
    prime.push_back(2);

    for(int i = 3; i < SIZE; i += 2) {
        if(CHECK(i) == false) {
            prime.push_back(i);

            if(i <= root) {
                for(int j = i * i; j < SIZE; j += i << 1) {
                    SET(j);
                }
            }
        }
    }
}

int nodPrime(int n) {
    map<int, int> m;
    int root = sqrt(n);

    for(int i = 0, length = prime.size(); i < length && prime[i] <= root; i++) {
        while(n % prime[i] == 0) {
            m[prime[i]]++;
            n /= prime[i];
        }
    }

    if(n > 1) {
        m[n]++;
    }

    int c = 0;

    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        if(it->second > c) {
            c = it->second;
        }
    }

    return c;
}

int main()
{
    sieve();
    int T, n;

    scanf("%d", &T);

    while(T--) {
        scanf("%d", &n);
        printf("%d\n", nodPrime(n));
    }

    return 0;
}
