#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <cstring>
using namespace std;

struct number_pattern {
    string pattern;
    string type;

    number_pattern() {}
    number_pattern(const string & p, const string & t) : pattern(p), type(t)
    {
    }

    number_pattern(const number_pattern & other) {
    }


    bool number_matches_the_pattern(const string & number) {
    }


    string get_number_suggestion(const string & number) {

        return string("-1");
    }
};


struct vehicle_info {

    vehicle_info(const string & number, string type = "optional") {
    }


    bool is_valid_number_pattern() {

        return true;
    }
};

bool is_palindrome(const string & s)
{
}

void lucky_number(vector<vehicle_info> & vehicles, vector<number_pattern> & patterns)
{
}
