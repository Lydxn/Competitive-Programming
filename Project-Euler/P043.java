package euler100;

public class P043 {

	public static void main(String[] args) {
		String[] left = {"14", "41"};
		String[] right = {"06357289", "60357289", "30952867"};
		
		long sum = 0;
		for (String l : left) {
			for (String r : right) {
				sum += Long.parseLong(l + r);
			}
		}
		System.out.println(sum);
	}	

}
