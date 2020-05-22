import java.io.*;
import java.util.*;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE

class HotRoad {
    public static void main(String [] args) {


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
