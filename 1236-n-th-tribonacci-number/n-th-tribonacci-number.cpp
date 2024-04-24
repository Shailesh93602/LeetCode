class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int first = 0;
        int second = 1;
        int third = 1;
        while(n >= 3) {
            int temp = third;
            third += first+second;
            first = second;
            second = temp;
            n--;
        }
        return third;
    }
};