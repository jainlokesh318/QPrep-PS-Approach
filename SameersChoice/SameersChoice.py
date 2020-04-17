from solution import Solution



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
    main()
