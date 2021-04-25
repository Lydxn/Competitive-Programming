package ccc_2008;
import java.util.Scanner;

public class J1 {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("Enter weight: ");
		float weight = in.nextFloat();
		System.out.print("Enter height: ");
		float height = in.nextFloat();
		
		float bmi = weight / (height * height);
		
		if (bmi < 18.5) {
			System.out.println("Underweight");
		} else if (bmi > 25) {
			System.out.println("Overweight");
		}	else {
			System.out.println("Normal weight");
		}
	}
	
}
