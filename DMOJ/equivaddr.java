package DMOJ;
import java.util.Scanner;

public class Equivalent_Addresses {
	
	static final int A20 = 0xFFFF;

	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);
		String address = in.nextLine();
		
		int segment = Integer.parseInt(address.substring(0, 4), 16);
		int offset = Integer.parseInt(address.substring(5), 16);
		
		int target = (segment << 4) + offset;
		for (int i = offset & 15; i < (offset & 15) + A20; i += 16) {
			segment = ((target - i) >> 4) & A20;
			System.out.println(String.format("%1$04X:%2$04X", segment, i & A20));
		}
	}

}
