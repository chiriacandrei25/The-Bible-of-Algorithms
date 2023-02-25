int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
}
    
int magicNumber(int n) {
        while (n > 9) {
            n = digitSum(n);
        }
        return n;
}
