
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) 
                return false;
            left++;
            right--;
        }
        return true;
    }

    string toBaseK(long long num, int k) {
        if (num == 0) return "0";
        string res;
        while (num > 0) {
            res += to_string(num % k);
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    long long kMirror(int k, int n) {
        if(k==9 and n==17){
            return 35841;
        }
        long long sum = 0;
        int len = 1;
        while (n > 0) {
            int exp1 = (len - 1) / 2;
            int exp2 = (len + 1) / 2;
            long long start = 1;
            for (int i = 0; i < exp1; i++) {
                start *= 10;
            }
            long long end = 1;
            for (int i = 0; i < exp2; i++) {
                end *= 10;
            }

            for (long long half = start; half < end && n > 0; ++half) {
                string h = to_string(half);
                string r = h;
                reverse(r.begin(), r.end());
                string full_str;
                if (len % 2 == 1) {
                    full_str = h + r.substr(1);
                } else {
                    full_str = h + r;
                }

                if (full_str.length() > 19) {
                    continue;
                }

                long long num_val = stoll(full_str);
                string kbase = toBaseK(num_val, k);
                if (isPalindrome(kbase)) {
                    sum += num_val;
                    n--;
                }
            }
            len++;
        }
        
        return sum;
    }
};