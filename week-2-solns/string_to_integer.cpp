class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long ans = 0;

        // ignoring initial white spaces
        while(i < s.length() && s[i] == ' '){
            i++;
        }

        // sign
        if (s[i] == '-'){
            sign = -1;
            i++;
        }

        else if (s[i] == '+'){
            sign = 1;
            i++;
        }

        // Storing the number if it is a number
        while (i < s.length()){
            if (s[i] >= '0' && s[i] <= '9'){
                ans = ans * 10 + (s[i] - '0');

                // If greater than INT_MAX and positive, then replace with INT_MAX
                if (ans > INT_MAX && sign == 1){
                    return INT_MAX;
                }

                // If greater than INT_MAX but negative, then replace with INT_MIN
                else if (ans > INT_MAX && sign == -1){
                    return INT_MIN;
                }

                i++;
            }
            // Encountering a non-numeric character
            else{
                return (ans * sign);
            }
        }

        return (ans * sign);
    }
};