package DMOJ;
import java.util.Scanner;

public class The_Return_Of_A_Plus_B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < N; i++) {
			String a = in.next();
			String b = in.next();
			
			System.out.println(parseInt(a) + parseInt(b));
		}
	}
	
	private static int parseInt(String s) {
	    switch (s) {
        case "1": case "one": case "un": case "一":
            return 1;
	    case "2": case "two": case "deux": case "二":
            return 2;
        case "3": case "three": case "trois": case "三":
            return 3;
        case "4": case "four": case "quatre": case "四":
            return 4;
        case "5": case "five": case "cinq": case "五":
            return 5;
        case "6": case "six": case "六":
            return 6;
        case "7": case "seven": case "sept": case "七":
            return 7;
        case "8": case "eight": case "huit": case "八":
            return 8;
        case "9": case "nine": case "neuf": case "九":
            return 9;
        case "10": case "ten": case "dix": case "十":
            return 10;
        default:
            return 5;
	    }
	}

}
