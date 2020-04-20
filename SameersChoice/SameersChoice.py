from solution import Solution

# DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE


def test_valid_number_pattern():
    number1 = Solution().is_valid_number_pattern("TN-12-1234")
    number2 = Solution().is_valid_number_pattern("TN-12-A-1234")
    number3 = Solution().is_valid_number_pattern("TN-12-AB-1234")
    number4 = Solution().is_valid_number_pattern("TN-12-ABC-1234")

    assert number1
    assert number2
    assert number3
    assert number4

    number5 = Solution().is_valid_number_pattern("TN-12-ABCD-1234")
    number6 = Solution().is_valid_number_pattern("OLA1234")
    number7 = Solution().is_valid_number_pattern("TN-12-12345")
    number8 = Solution().is_valid_number_pattern("UT-12-abcd")
    number9 = Solution().is_valid_number_pattern("UT-12--4578")


    assert not number5
    assert not number6
    assert not number7
    assert not number8
    assert not number9


def test_number_pattern():
    number1 = Solution().is_registered_in_india("3145", "31-23-45")
    number2 = Solution().is_registered_in_india("3245", "31-23-45")
    number3 = Solution().is_registered_in_india("3135", "31-23-45")
    number4 = Solution().is_registered_in_india("3235", "31-23-45")

    assert number1[0]
    assert number2[0]
    assert number3[0]
    assert number4[0]

    number1 = Solution().is_registered_in_india("4435", "31-23-45")
    number2 = Solution().is_registered_in_india("4445", "31-23-45")
    number3 = Solution().is_registered_in_india("4415", "31-23-45")
    expected1 = "3135"
    expected2 = "3145"
    expected3 = "3135"

    assert expected1 == number1[1]
    assert expected2 == number2[1]
    assert expected3 == number3[1]


def test_palindrome():
    assert Solution().is_number_palindrome("1221")
    assert Solution().is_number_palindrome("2112")
    assert Solution().is_number_palindrome("1111")
    assert not Solution().is_number_palindrome("2121")
    assert not Solution().is_number_palindrome("2221")
    assert not Solution().is_number_palindrome("2212")

def main():

    t = int(input())
    pattern_list = list()
    for _ in range(t):
        vehicle_type, pattern = input().rstrip("\n\r").split(" ")
        pattern_list.append([vehicle_type, pattern])

    n = int(input())
    queries = list()
    for _ in range(n):
        plate_string, vehicle_type = input().rstrip("\n\r").split(' ')
        queries.append([plate_string, vehicle_type])
    Solution().lucky_number(pattern_list, queries)


if __name__ == "__main__":
    test_valid_number_pattern()
    test_number_pattern()
    test_palindrome()
    main()
