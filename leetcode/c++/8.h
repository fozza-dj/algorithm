class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int sign = 1;
        int i = 0;
        // remove front spaces
        while (str[i] == ' ') ++i;
        if (str[i] >= '0' && str[i] <= '9') {
            res += 10 * res + str[i] - '0';
        } else if (str[i] == '+' || str[i] == '-') {
            sign = (str[i] == '+') ? 1 : -1;
        } else {
            return 0;
        }
        // process following chars
        while (++i < str.size() && str[i] >= '0' && str[i] <= '9') {
            int a = str[i] - '0';
            if (sign == 1) {
                if (res >= (INT_MAX - a) / 10 + ((INT_MAX - a) % 10 != 0))
                    return INT_MAX;
                res = 10 * res + a;
            } else {
                if (res <= (INT_MIN + a) / 10 - ((INT_MIN + a) % 10 != 0))
                    return INT_MIN;
                res = 10 * res - a;
            }
        }
        return res;
    }
};