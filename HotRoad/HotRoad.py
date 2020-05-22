from Solution import *


# DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE


def main():


    (n, dist) = [ int(x) for x in input().strip().split()]
    broken = []
    for i in range(n):
        temp = input().strip().split()
        (number, people) = (temp[0], int(temp[1]))
        broken.append((number, people))
    m = int(input().strip())
    good = []
    for i in range(m):
        temp = input().strip().split()
        (number, people, capacity) = (temp[0], int(temp[1]), int(temp[2]))
        good.append((number, people, capacity))
        
    print(find_maximum_number_of_people_accomodated(broken, good, dist))
    
main()       

