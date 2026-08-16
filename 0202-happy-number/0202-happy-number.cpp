class Solution {
public:
    int digitSquareSum(int n){
        int sum = 0;
        while(n != 0){
            int digit = n % 10;
            sum += digit* digit;
            n /= 10;
        }
        return sum;

    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = digitSquareSum(slow);         // Move slow by 1 step
            fast = digitSquareSum(digitSquareSum(fast)); // Move fast by 2 steps
        } while (slow != fast);

        return slow == 1;
    }
};