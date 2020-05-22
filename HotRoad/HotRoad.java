import java.io.*;
import java.util.*;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE

class HotRoad {

    public static void test_reg_number_to_integer() {
	String s = "KA01AA0001";
	assert Solution.reg_number_to_integer(s) == 1;
	assert Solution.reg_number_to_integer("KA01AA0002") == 2;
	assert Solution.reg_number_to_integer("KA01AB0001") == 10000 ;
	assert Solution.reg_number_to_integer( "KA01BA0001") == 26 * 9999 + 1;
	assert Solution.reg_number_to_integer("KA01BA0001") == 259975;
	assert Solution.reg_number_to_integer("KA02AA0001") == 6759325;
    }

    public static void test_find_maximum_number_of_people_accomodated() {

	// normal case
	ArrayList<Entity1> broken = new ArrayList<Entity1> ();
	ArrayList<Entity2> good = new ArrayList<Entity2> ();
	String a = "KA01MQ1012"; int b = 2;
	Entity1 car = new Entity1(a, b);
	broken.add(car);
	String a1 = "KA01MQ1045"; int b1 = 4;
	Entity1 car1 = new Entity1(a1, b1);
	broken.add(car1);
	String c = "KA01MQ1002";
	int d = 2;
	int e = 4;
	Entity2 gcar = new Entity2(c, d, e);
	good.add(gcar);
	String c1 = "KA01MQ1050";
	int d1 = 4;
	int e1 = 10;
	Entity2 gcar1 = new Entity2(c1, d1, e1);
	good.add(gcar1);
	assert (Solution.find_maximum_number_of_people_accomodated(broken, good, 10)) == 6;
	good.clear();
	broken.clear();
	//  normal case

	car.first = "KA01MQ1012"; car.second = 2;
	broken.add(car);
	car1.first = "KA01MQ1045"; car1.second = 4;
	broken.add(car1);
	gcar.first = "KA01MQ1002"; gcar.second = 2; gcar.third = 4;
	good.add(gcar);
	gcar1.first = "KA01MQ1050"; gcar1.second = 4; gcar1.third = 10;
	good.add(gcar1);
	assert Solution.find_maximum_number_of_people_accomodated(broken, good, 5) == 4;
	good.clear();
	broken.clear();

	// no good car in range

	car.first = "KA01MQ1012"; car.second = 2;
	broken.add(car);
	car1.first = "KA01MQ1045"; car1.second = 4;
	broken.add(car1);
	gcar.first = "KA01MQ1002"; gcar.second = 2; gcar.third = 4;
	good.add(gcar);
	gcar1.first = "KA01MQ1055"; gcar1.second = 4; gcar1.third = 10;
	good.add(gcar1);
	assert Solution.find_maximum_number_of_people_accomodated(broken, good, 9) == 0;
	good.clear();
	broken.clear();

	// large broke car accomodated by multiple good cars

	car.first = "KA01MQ1012"; car.second = 6;
	broken.add(car);
	gcar.first = "KA01MQ1002"; gcar.second = 2; gcar.third = 4;
	good.add(gcar);
	gcar1.first = "KA01MQ1021"; gcar1.second = 3; gcar1.third = 4;
	good.add(gcar1);
	assert Solution.find_maximum_number_of_people_accomodated(broken, good, 10) == 3;
	good.clear();
	broken.clear();

	//  car with large capacity accomodates people from multiple cars

	car.first = "KA01MQ1002"; car.second = 2;
	broken.add(car);
	car1.first = "KA01MQ1021"; car1.second = 2;
	broken.add(car1);
	gcar.first = "KA01MQ1012"; gcar.second = 2; gcar.third = 8;
	good.add(gcar);
	assert Solution.find_maximum_number_of_people_accomodated(broken, good, 10) == 4;

    }

    public static void main(String [] args) {


	test_reg_number_to_integer();
	test_find_maximum_number_of_people_accomodated();

	Scanner sc = new Scanner(System.in);
	int n, k, m;
	n = sc.nextInt();
	k = sc.nextInt();

	ArrayList<Entity1> broken = new ArrayList<Entity1>( );
	for ( int i = 0; i < n; i++) {
	    String a = sc.next();
	    int  b =  sc.nextInt();
	    Entity1 car = new Entity1(a, b);

	    broken.add(car);

	}

	m = sc.nextInt();
	ArrayList<Entity2> good = new ArrayList<Entity2>(m + 1);
	for ( int i = 0; i < m; i++) {

	    String a = sc.next();
	    int  b =  sc.nextInt();
	    int c = sc.nextInt();
	    Entity2 car = new Entity2(a, b, c);

	    good.add(car);

	}
	int ans = Solution.find_maximum_number_of_people_accomodated(broken, good, k);
	System.out.println(ans);
    }


}

class Pair {
    int first;
    int second;
    Pair(int p, int q) {
	first = p;
	second = q;
    }

    static Comparator<Pair> comp = new Comparator<Pair>() {
	public  int compare(Pair A, Pair B) {
	    int x = Integer.compare(A.first, B.first);
	    if (x == 0) {
		return Integer.compare(A.second, B.second);
	    }
	    return x;
	}
    };

}
class Entity1 {
    String first;
    int second;
    Entity1(String p, int q ) {
	first = p;
	second = q;
    }
}
class Entity2 {
    String first;
    int second;
    int third;
    Entity2(String p, int q, int r) {
	first = p;
	second = q;
	third  = r;
    }
}
