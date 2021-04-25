package euler100;

public class P030 {

	public static void main(String[] args) {
		int bigSum = 0;
		for (int a = 10; a < 6 * Math.pow(9, 5); a++) {
			String aStr = Integer.toString(a);
			int sum5 = 0;
			
			for (int i = 0; i < aStr.length(); i++) {
				sum5 += Math.pow(Character.getNumericValue(aStr.charAt(i)), 5);
			}
			
			if (sum5 == a) {
				bigSum += a;
			}
		}
		System.out.println(bigSum);
	}

}
