package ccc_2006;
import java.util.Scanner;

public class J1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Welcome to Chip's Fast Food Emporium");
		System.out.print("Please enter a burger choice: ");
		int burger = in.nextInt();
		System.out.print("Please enter a side order choice: ");
		int side = in.nextInt();
		System.out.print("Please enter a drink choice: ");
		int drink = in.nextInt();
		System.out.print("Please enter a dessert choice: ");
		int dessert = in.nextInt();
		
		int[][] menu = {{461, 431, 420, 0}, {100, 57, 70, 0}, {130, 160, 118, 0}, {167, 266, 75, 0}};
		
		int calories = menu[0][burger - 1] + menu[1][side - 1] + menu[2][drink - 1] + menu[3][dessert - 1];
		System.out.println("Your total Calorie count is " + calories + ".");
 	}

}
