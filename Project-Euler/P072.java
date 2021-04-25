package euler100;

public class P072 {

	public static void main(String[] args) {
		System.out.println(farey(1000000));
	}
	
	private static long farey(int n) {
		long[] totient = new long[n + 1];
		for (int i = 0; i < totient.length; i++) {
			totient[i] = i;
		}
		
		long sum = 0;
		for (int i = 2; i < totient.length; i++) {
			if (totient[i] == i) {
				for (int j = i; j < totient.length; j += i) {
					totient[j] -= totient[j] / i;
				}
			}
			sum += totient[i];
		}
		return sum;
	}

}
