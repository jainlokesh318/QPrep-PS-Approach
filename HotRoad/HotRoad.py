from Solution import *


# DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE

def test_reg_number_to_integer():
    assert(reg_number_to_integer('KA01AA0001') == 1)
    assert(reg_number_to_integer('KA01AA0002') == 2)
    assert(reg_number_to_integer('KA01AB0001') == 10000)
    assert(reg_number_to_integer('KA01BA0001') == 26 * 9999 + 1)
    assert(reg_number_to_integer('KA01BA0001') == 259975)
    assert(reg_number_to_integer('KA02AA0001') == 6759325)

def test_find_maximum_number_of_people_accomodated():

    # normal case
    broken = [('KA01MQ1012', 2), ('KA01MQ1045', 4)]
    good = [('KA01MQ1002', 2, 4), ('KA01MQ1050', 4, 10)]

    assert(find_maximum_number_of_people_accomodated(broken, good, 10) == 6)
    
    # normal case
    broken = [('KA01MQ1012', 2), ('KA01MQ1045', 4)]
    good = [('KA01MQ1002', 2, 4), ('KA01MQ1050', 4, 10)]

    assert(find_maximum_number_of_people_accomodated(broken, good, 5) == 4)
   
    # no good car in range 
    broken = [('KA01MQ1012', 2), ('KA01MQ1045', 4)]
    good = [('KA01MQ1002', 2, 4), ('KA01MQ1055', 4, 10)]

    assert(find_maximum_number_of_people_accomodated(broken, good, 9) == 0)

    # large broke car accomodated by multiple good cars
    broken = [('KA01MQ1012', 6)]
    good = [('KA01MQ1002', 2, 4), ('KA01MQ1021', 3, 4)]

    assert(find_maximum_number_of_people_accomodated(broken, good, 10) == 3)

    # car with large capacity accomodates people from multiple cars    
    broken = [('KA01MQ1002', 2), ('KA01MQ1021', 2)]
    good = [('KA01MQ1012', 2, 8)]

    assert(find_maximum_number_of_people_accomodated(broken, good, 10) == 4)

def main():

    test_reg_number_to_integer()
    test_find_maximum_number_of_people_accomodated()

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

