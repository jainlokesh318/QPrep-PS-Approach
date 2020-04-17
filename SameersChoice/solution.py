import re
from collections import defaultdict

class Solution:
    # This function will take full plate string and 
    # then check if it follows all the rules
    # and returns a boolean value at the end.

    def is_valid_number_pattern(self, plate_string):
        nums = plate_string.split('-')
        lists = ["AP", "AR", "AS", "BR", "CG", "GA", "GJ", "HR", "HP", "JH", "KA", "KL", "MP", "MH", "MN", "ML", "MZ", "NL", "OD", "PB", "RJ", "SK", "TN", "TS", "TR", "UP", "UK", "WB", "AN", "CH", "DD", "DL", "JK", "LA", "LA", "LD", "PY"]
        pre_condition = True
        if len(nums) < 3 or len(nums) > 4:
            pre_condition = False
        # checking for first rule
        elif nums[0] not in lists:
            pre_condition = False
        # checkigng for second rule
        elif len(nums[1]) != 2 or nums[1].isdigit() == False:
            pre_condition = False
        # checking for third rule and fourth rule collectively
        elif len(nums) == 3:
            if len(nums[-1]) != 4 or nums[-1].isdigit() == False:
               pre_condition = False
        elif len(nums) == 4:
            if len(nums[2]) > 3 or nums[2].isupper() == False:
                pre_condition = False
            if len(nums[-1]) != 4 or nums[-1].isdigit() == False:
                pre_condition = False

        return pre_condition

    # This function will take the last four digits of plate_string 
    # and the choice string i.e will be the pattern like "08-94-56-9"
    # and at last will return boolean value if its registered or not and 
    # the string which will require minimal replacement &
    # will be  lexicographically smallest possible string.

    def is_registered_in_india(self, plate_number, pattern):
        condition = True
        least = ""
        pattern_list = [list(map(int, i[0].split('-'))) for i in re.findall("(\d(-\d)?)", pattern)] 
        for j, i in enumerate(plate_number):
            number = int(i)
            if not(number >= pattern_list[j][0] and number <= pattern_list[j][-1]):
                condition = False
                least += str(pattern_list[j][0])
            else:
                least += i
        if condition == True:
            least = plate_number
        return condition, least


    # This function will take the last four digits of the plate_string
    # and will return boolean value at the end.

    def is_number_palindrome(self, plate_number):
        return plate_number == plate_number[::-1]

    # This function will take the pattern_list which have this 
    # structue [vehicle_type, pattern_format] and another argument
    # queries which will have this structure [plate_string, vehicle_type].
    # This function will not return anything and will print out
    # result for all queries and wishlist in the end.


    def lucky_number(self,pattern_list, queries):
