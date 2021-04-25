package euler100;

public class P071 {

	public static void main(String[] args) {
		int targetN = 2;
		int targetD = 5;
		
		while (targetD <= 1000000) {
			targetN += 3;
			targetD += 7;
		}
		System.out.println(targetN - 3);
	}

}
