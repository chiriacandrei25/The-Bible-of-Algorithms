#include <iostream>
#include <cmath> /// We need the "cmath" library for the sqrt function

using namespace std;

bool isPrime(int n) {
    if(n <= 1)
        return false;
    for(int i = 2; i < sqrt(n); i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    cout << isPrime(137);
    return 0;
}
