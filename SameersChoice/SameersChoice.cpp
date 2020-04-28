#include <iostream>
#include "solution.cpp"
#include <cassert>


// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE



/*void test_valid_numer_pattern()
{
    {
        vehicle_info number1("TN-12-1234");
        vehicle_info number2("TN-12-A-1234");
        vehicle_info number3("TN-12-AB-1234");
        vehicle_info number4("TN-12-ABC-1234");
        vehicle_info number5("TN-12-ba-1234");

        assert(true == number1.is_valid_number_pattern());
        assert(true == number2.is_valid_number_pattern());
        assert(true == number3.is_valid_number_pattern());
        assert(true == number4.is_valid_number_pattern());
        assert(true == number5.is_valid_number_pattern());

        vehicle_info number6("TN-12-abcd-1234");
        vehicle_info number7("TN-12-abcd-12-1234");
        vehicle_info number8("TN-12-12345");
        vehicle_info number9("TN-12-abcd");

        assert(false == number6.is_valid_number_pattern());
        assert(false == number7.is_valid_number_pattern());
        assert(false == number8.is_valid_number_pattern());
        assert(false == number9.is_valid_number_pattern());
    }
}*/

/*void test_number_pattern()
{
    {
        number_pattern pattern("31-23-45", "Car");

        assert(pattern.number_matches_the_pattern("3145"));
        assert(pattern.number_matches_the_pattern("3245"));
        assert(pattern.number_matches_the_pattern("3135"));
        assert(pattern.number_matches_the_pattern("3235"));

        assert(!pattern.number_matches_the_pattern("2235"));
        assert(!pattern.number_matches_the_pattern("3435"));
        assert(!pattern.number_matches_the_pattern("3255"));
        assert(!pattern.number_matches_the_pattern("3236"));
    }

    {
        number_pattern pattern("31-23-45", "Car");
        string expected("3135");
        assert(expected == pattern.get_number_suggestion("4435"));
    }

    {
        number_pattern pattern("31-23-45", "Car");
        string expected("3145");
        assert(expected == pattern.get_number_suggestion("4445"));
    }
}


void test_palindrome()
{
    {
        assert(true == is_palindrome("1221"));
        assert(true == is_palindrome("121"));
        assert(true == is_palindrome("11"));
        assert(true == is_palindrome("1"));

        assert(false == is_palindrome("1222"));
        assert(false == is_palindrome("122"));
        assert(false == is_palindrome("12"));
    }
}*/


int main()
{
    int n;
    cin >> n;

  // test_valid_numer_pattern();
    //test_number_pattern();
   // test_palindrome();

    vector<number_pattern> patterns;
    for (int i = 0; i < n; ++i) {
        string pattern;
        string type;

        cin >> type >> pattern;

        number_pattern one_pattern(pattern, type);
        patterns.push_back(one_pattern);
    }

    int m;
    cin >> m;
    vector<vehicle_info> vehicles;
    for (int i = 0; i < m; ++i) {
        string type;
        string number;

        cin >> number >> type;

        vehicle_info info(number, type);
        vehicles.push_back(info);
    }

    lucky_number(vehicles, patterns);
    return 0;
}

