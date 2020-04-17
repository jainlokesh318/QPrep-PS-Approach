#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <cstring>

using namespace std;

struct one_digit {
    int start;
    int end;

    one_digit() {}
    one_digit(const one_digit & other) {
        this->start = other.start;
        this->end = other.end;
    }
};

static inline int dist(const char * candidate_number, const char * actual_number)
{
    int n = strlen(candidate_number);
    int d = 0;
    for (int i = 0; i < n; ++i) {
        if (candidate_number[i] != actual_number[i]) {
            ++d;
        }
    }

    return d;
}

struct number_pattern {
    one_digit digits[4];
    string pattern;
    string type;

    number_pattern() {}
    number_pattern(const string & p, const string & t) : pattern(p), type(t)
    {
        parse_pattern();
    }

    number_pattern(const number_pattern & other) {
        memcpy(digits, other.digits, sizeof(digits));
        pattern = other.pattern;
        type = other.type;
        parse_pattern();
    }

    void parse_pattern() {
        //printf("\nPattern = %s\n", pattern.c_str());
        int n = pattern.length();
        int s = 0;
        for (int i = 0; i < n; ) {
            if ((i + 1 == n) || pattern[i+1] != '-') {
                digits[s].start = pattern[i] - '0';
                digits[s].end = pattern[i] - '0';
                ++i;
            } else {
                digits[s].start = pattern[i] - '0';
                digits[s].end = pattern[i + 2] - '0';
                i += 3;
            }
            //printf("start = %d end = %d\n", digits[s].start, digits[s].end);
            ++s;
        }
        //printf("\n");
    }

    bool number_matches_the_pattern(const string & number) {

        //cout << "number = " << number << endl;
        for (size_t i = 0; i < number.length(); ++i) {
            int n = number[i] - '0';
            //printf("n = %d start = %d end = %d\n", n, digits[i].start, digits[i].end);
            if (!(n >= digits[i].start && n <= digits[i].end))
                return false;
        }
        return true;
    }

    vector<int> get_candidate_numbers(const string & number) {
        vector<int> nums;

        for (size_t i = 0; i < number.length(); ++i) {
            vector<int> temp;
            for (int k = digits[i].start; k <= digits[i].end; ++k) {
                if (i == 0) {
                    temp.push_back(k);
                } else {
                    for (size_t j = 0; j < nums.size(); ++j) {
                        temp.push_back(nums[j] * 10 + k);
                    }
                }
            }
            nums = temp;
        }

        return nums;
    }


    string get_number_suggestion(const string & number) {
        vector<int> nums = get_candidate_numbers(number);
        const char * actual_number = number.c_str();

        map<int, int> res;
        for (size_t i = 0; i < nums.size(); ++i) {
            char candidate_number[5];
            sprintf(candidate_number, "%d", nums[i]);

            int d = dist(candidate_number, actual_number);

            if (res.find(d) == res.end()) {
                res[d] = nums[i];
            }
        }

        for (int i = 0; i < 4; ++i) {
            if (res.find(i) != res.end()) {
                char p[5];
                sprintf(p, "%d", res[i]);
                return string(p);
            }
        }

        return string("-1");
    }
};

map<string, bool> code;

void fill_table() {
    string state_codes[] = {"AP", "AR", "AS" , "BR" , "CG", "GA", "GJ", "HR", "HP", "JH" ,"KA", "KL", "MP", "MH", "MN", "ML", "MZ", "NL", "OD", "PB", "RJ", "SK", "TN", "TS", "TR", "UP", "UK", "WB", "AN", "CH", "DD", "DL", "JK", "LA", "LA", "LD", "PY"};

    for (size_t i = 0; i < sizeof(state_codes)/sizeof(state_codes[0]); ++i) {
        code[state_codes[i]] = true;
    }
}

struct vehicle_info {
    string type;
    string number;
    vector<string> tokens;

    vehicle_info(const string & number, string type = "optional") {

        if (code.size() == 0) {
            fill_table();
        }

        this->type = type;
        this->number = number;
        istringstream f(number);
        string s;
        while (getline(f, s, '-')) {
            tokens.push_back(s);
        }
    }

    bool is_letters(const string & str) {
        for (size_t i = 0; i < str.length(); ++i) {
            if (!isalpha(str[i]))
                return false;
        }

        return true;
    }

    bool is_num(const string & num) {
        for (size_t i = 0; i < num.length(); ++i) {
            if (!(num[i] >= '0' && num[i] <= '9'))
                return false;
        }

        return true;
    }

    bool is_valid_number_pattern() {
        int n = tokens.size();

        if (!(n == 3 || n == 4)) {
            return false;
        }

        string p1 = tokens[0];
        string p2 = tokens[1];
        string p3 = "";
        string p4 = tokens[n-1];
        if (n == 4) {
            p3 = tokens[2];
            if (p3.length() > 3)
                return false;
        }

        int num = 0;
        sscanf(p4.c_str(), "%d", &num);

        if (!is_num(p4) || p4.length() == 0 || p4.length() > 4) {
            return false;
        }

        if (!is_letters(p3) || p3.length() > 3) {
            return false;
        }

        if (!is_num(p2) || p2.length() == 0 || p2.length() > 2) {
            return false;
        }

        if (code.find(p1) == code.end())
            return false;

        return true;
    }

    string get_number() {
        return tokens[tokens.size() - 1];
    }
};

bool is_palindrome(const string & s)
{
    int n = s.length();

    for (int i = 0; 2 * i < n; ++i) {
        if (s[i] != s[n-1-i])
            return false;
    }

    return true;
}

void lucky_number(vector<vehicle_info> & vehicles, vector<number_pattern> & patterns)
{
}
