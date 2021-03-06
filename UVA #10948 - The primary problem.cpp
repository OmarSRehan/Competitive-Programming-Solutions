#include <bits/stdc++.h>
using namespace std;

vector<bool> prime((1e6) + 2, 1);
void Seive() {
    prime[0] = prime[1] = 0;
    for (int i = 2; i*i <= (1e6); i++) {
        if (prime[i])
            for (int j = i*i; j <= (1e6); j += i) prime[j] = 0;
    }
}

int main() {
    int n;
    Seive();
    while (scanf("%d", &n) && n) {
        if (n&1) {
            if (prime[n-2]) printf("%d:\n%d+%d\n", n, 2, n-2);
            else printf("%d:\nNO WAY!\n", n);
        } else {
            int i = 1;
            while(!prime[n-i] || !prime[i]) i++;
            printf("%d:\n%d+%d\n", n, i, n-i);
        }
    }
}
