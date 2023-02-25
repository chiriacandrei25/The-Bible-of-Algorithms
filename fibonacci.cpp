int fibonacci(int n) {
    if (n < 2) {
        return n;
    }
    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        int next = curr + prev;
        prev = curr;
        curr = next;
    }
    return curr;
}