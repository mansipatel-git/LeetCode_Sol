class Solution {
public:
    
    bool checkDivisibility(int n) {
        int x = n;
        int sum =0;
        int product = 1;
        while(x != 0){
            int d = x%10;
            sum += d;
            product *= d;

            x /= 10;

        }

        return n % (sum + product) == 0;
    }
};