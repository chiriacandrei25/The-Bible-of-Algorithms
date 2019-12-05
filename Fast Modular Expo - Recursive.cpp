#include <iostream>

using namespace std;

int fastExpo(int a, long long n, int MOD) {
    if(n == 0)
        return 1;
    /// (a^n) % MOD
    if(n % 2 == 0)
        /// a ^ n = ((a ^ 2) ^ (n/2))
        return fastExpo((1LL * a * a) % MOD, n / 2, MOD);
    /// a ^ n = a * (a ^ (n - 1))
    return (1LL * a * fastExpo(a, n - 1, MOD)) % MOD;

}

int main()
{
    cout << fastExpo(5, 0, 1000000007);
    return 0;
}
