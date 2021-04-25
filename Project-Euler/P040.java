package euler100;

public class P040 {

	public static void main(String[] args) {
		int prod = 1;
		for (int i = 1; i < 6; i++) {
			int pow = (int) Math.pow(10, i);
			int dig = (pow * 10 - (pow * i - (pow - 1) / 9));
			int n = dig / (i + 1) + pow - 1;
			int dec = Character.getNumericValue(Integer.toString(n).charAt(dig % (i + 1) - 1));
			prod *= dec;
		}
		System.out.println(prod);
	}

}
