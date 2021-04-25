package DMOJ;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Present {
	String name;
	float price;
	
	public Present(String name, float price) {
		this.name = name;
		this.price = price;
	}
}

class Teacher {
	String name;
	int rating;
	
	public Teacher(String name, int rating) {
		this.name = name;
		this.rating = rating;
	}
}

public class Christmas_Presents {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int P = in.nextInt();
		int T = in.nextInt();
		in.nextLine();
		
		Present[] presents = new Present[P];
		for (int i = 0; i < presents.length; i++) {
			presents[i] = new Present(in.nextLine(), in.nextFloat());
			in.nextLine();
		}
		
		Arrays.sort(presents, new Comparator<Present>() {
			public int compare(Present o1, Present o2) {
				return Float.compare(o1.price, o2.price);
			}
		});
		
		Teacher[] teachers = new Teacher[T];
		for (int i = 0; i < teachers.length; i++) {
			teachers[i] = new Teacher(in.nextLine(), in.nextInt());
			in.nextLine();
		}
		
		Arrays.sort(teachers, new Comparator<Teacher>() {
			public int compare(Teacher o1, Teacher o2) {
				return Integer.compare(o1.rating, o2.rating);
			}
		});
		
		for (int i = 0; i < teachers.length; i++) {
			System.out.println(teachers[i].name + " will get a " + presents[i].name);
		}
	}

}