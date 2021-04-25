package ccc_2008;
import java.util.Scanner;

public class S1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int coldest = Integer.MAX_VALUE;
		String coldestCity = "";
		
		while (true) {
			in.nextLine();
			String city = in.next();
			int temp = in.nextInt();
			
			if (city.equals("Waterloo")) {
				break;
			}
			
			if (coldest > temp) {
				coldest = temp;
				coldestCity = city;
			}
		}
		System.out.println(coldestCity);
	}

}
