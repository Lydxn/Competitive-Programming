package DMOJ;
import java.util.Scanner;

public class A_Plus_B_Hard {
	
	static boolean smaller;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		in.nextLine();
		
		for (int i = 0; i < N; i++) {
			String[] nums = in.nextLine().split(" ");
			String A = nums[0];
			String B = nums[1];
			
			boolean aNeg = false;
			boolean bNeg = false;
			
			if (A.charAt(0) == '-') {
				A = A.substring(1);
				aNeg = true;
			}
			
			if (B.charAt(0) == '-') {
				B = B.substring(1);
				bNeg = true;
			}
			
			smaller = isSmaller(A, B);
			String res = aNeg ? (bNeg ? "-" + sum(A, B) : (smaller ? "" : "-") + diff(A, B)) :
								 bNeg ? (smaller ? "-" : "") + diff(A, B) : sum(A, B);
			System.out.println(res.equals("-0") ? 0 : res);
		}
	}
	
	private static String sum(String A, String B) {
		if (!smaller) {
			String temp = A;
			A = B;
			B = temp;
		}
		
		int lenA = A.length();
		int lenB = B.length();

		StringBuilder res = new StringBuilder();
		int carry = 0;

		for (int i = lenA - 1; i >= 0; i--) {
			int sum = (A.charAt(i) - '0') + (B.charAt(i + lenB - lenA) - '0') + carry;
			res.append((char) (sum % 10 + '0'));
			carry = sum / 10;
		}
		
		for (int i = lenB - lenA - 1; i >= 0; i--) {
			int sum = (B.charAt(i) - '0') + carry;
			res.append((char) (sum % 10 + '0'));
			carry = sum / 10;
		}
		
		if (carry > 0) {
			res.append((char) (carry + '0'));
		}
		return res.reverse().toString();
	}
	
	private static String diff(String A, String B) {
		if (smaller) {
			String temp = A;
			A = B;
			B = temp;
		}
		
		StringBuilder res = new StringBuilder();
		int carry = 0;
		
		int lenA = A.length();
		int lenB = B.length();
		
		for (int i = lenB - 1; i >= 0; i--) {
			int diff = (A.charAt(i + lenA - lenB) - '0') - (B.charAt(i) - '0') - carry;
			if (diff < 0) {
				diff += 10;
				carry = 1;
			} else {
				carry = 0;
			}
			res.append(diff);
		}
		
		for (int i = lenA - lenB - 1; i >= 0; i--) {
			if (A.charAt(i) == '0' && carry > 0) {
				res.append('9');
				continue;
			}
			
			int diff = (A.charAt(i) - '0') - carry;
			if (i > 0 || diff > 0) {
				res.append(diff);
			}
			carry = 0;
		}
		
		res = res.reverse();
		while (res.charAt(0) == '0' && res.length() != 1) {
			res.deleteCharAt(0);
		}
		return res.toString();
	}
	
	private static boolean isSmaller(String A, String B) {
		int lenA = A.length();
		int lenB = B.length();
		
		if (lenA < lenB) {
			return true;
		} else if (lenA > lenB) {
			return false;
		}
		
		for (int i = 0; i < lenA; i++) {
			if (A.charAt(i) < B.charAt(i)) {
				return true;
			} else if (A.charAt(i) > B.charAt(i)) {
				return false;
			}
		}
		return false;
	}

}