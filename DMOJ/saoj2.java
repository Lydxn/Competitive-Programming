package DMOJ;
import java.util.Scanner;

public class Sword_Art_Online_Judge_2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		System.out.println("#include <iostream>");
		System.out.println("using namespace std;");
		System.out.println("int main()");
		System.out.println("{");
		System.out.println("	cout << " + (long) N * (N + 1) / 2 + ";");
		System.out.println("	return 0;");
		System.out.println("}");
	}

}