int secondLargest(int A, int B, int C) {
        if (min(B, C) <= A && A <= max(B, C)) {
            return A;
        }
        if (min(A, C) <= B && B <= max(A, C)) {
            return B;
        }
        return C;
}
