//T.C & S.C -> O(n) & O(1)

class Solution {
public:
    double myPow(double x, int n) {
       
        double ans = 1.0;
        long long positive = abs(n);
        
        while(positive)
        {
            // check for 1 bit
            if(positive & 1)
                ans *= x;
            
            positive >>= 1;
            x *= x;
        }
        return (n > 0) ? ans : 1 / ans;
    }
};
        /*
        double ans = 1.0;
        long long nn = n;
        
        if(nn < 0) nn = -1 * nn;
        
        while(nn)
        {
            if(nn % 2)
            {
                ans = ans * x;
                nn -= 1;
            }
            else
            {
                x *= x;
                nn /= 2;
            }
        }
        if(n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
    }
    */