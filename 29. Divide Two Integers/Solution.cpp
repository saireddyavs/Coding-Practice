class Solution
{
public:
    int divide(int dividend, int divisor)
    {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = abs(dividend);
        long long b = abs(divisor);

        int res = 0;
        int x = 0;

        while (a - b >= 0)
        {
            x = 0;

            while (a - (b << 1 << x) >= 0)
                ++x;

            res += 1 << x;

            a -= b << x;
        }
        // cout << x << endl;

        if (x == 31)
            return res;

        // cout<<res<<endl;

        return (dividend >= 0) == (divisor >= 0) ? res : res * -1;
    }
};