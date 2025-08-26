#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    double myPow (double x, int n) {
        /*
        if (n == 0)
            return 1;

        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        double ans = 1;  
        while (n > 0) {
            ans *= x; 
            n--;      
        }
        return ans;
        */
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        double current_product = x;

        while (N > 0) {
            if (N % 2 == 1)
                result *= current_product;
            current_product *= current_product; 
            N /= 2; 
        }

        return result; 
    }
};

int main() {
	Solution sol;
    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    double ans = sol.myPow(x, n);
    cout << x << " ^ " << n << " = " << ans << endl;

    return 0;
}
