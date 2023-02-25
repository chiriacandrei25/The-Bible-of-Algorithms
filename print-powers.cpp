void printPowers(int A, int B) {
        int power = 1;
        while (power <= B) {
            cout << power << endl;
            power *= A;
        }
}
