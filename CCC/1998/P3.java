import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		for (int i = 0; i < n; i++) {
			int x = 0;
			int y = 0;
			int dir = 0;
			
			outer: while (true) {
				int act = in.nextInt();
				switch (act) {
				case 0:
					break outer;
				case 1:
					int aheadNum = in.nextInt();
					switch (dir) {
					case 0:
						x += aheadNum;
						break;
					case 90:
						y += aheadNum;
						break;
					case 180:
						x -= aheadNum;
						break;
					case 270:
						y -= aheadNum;
						break;
					}
					break;
				case 2:
					dir -= 90;
					if (dir < 0) {
						dir = 270;
					}
					break;
				default:
					dir += 90;
					if (dir == 360) {
						dir = 0;
					}
					break;
				}
			}
			System.out.println("Distance is " + (Math.abs(x) + Math.abs(y)));
			
			if (x > 0) {
				if (y > 0) {
					if (dir == 0) {
						right();
						ahead(y);
						right();
						ahead(x);
					} else if (dir == 90) {
						left();
						ahead(x);
						left();
						ahead(y);
					} else if (dir == 180) {
						ahead(x);
						left();
						ahead(y);
					} else {
						ahead(y);
						right();
						ahead(x);
					}
				} else if (y < 0) {
					if (dir == 0) {
						left();
						ahead(y);
						left();
						ahead(x);
					} else if (dir == 90) {
						ahead(y);
						left();
						ahead(x);
					} else if (dir == 180) {
						ahead(x);
						right();
						ahead(y);
					} else {
						right();
						ahead(x);
						right();
						ahead(y);
					}
				} else {
					if (dir == 0) {
						uturn();
						ahead(x);
					} else if (dir == 90) {
						left();
						ahead(x);
					} else if (dir == 180) {
						ahead(x);
					} else {
						right();
						ahead(x);
					}
				}
			} else if (x < 0) {
				if (y > 0) {
					if (dir == 0) {
						ahead(x);
						right();
						ahead(y);
					} else if (dir == 90) {
						right();
						ahead(x);
						right();
						ahead(y);
					} else if (dir == 180) {
						left();
						ahead(y);
						left();
						ahead(x);
					} else {
						ahead(y);
						left();
						ahead(x);
					}
				} else if (y < 0) {
					if (dir == 0) {
						ahead(x);
						left();
						ahead(y);
					} else if (dir == 90) {
						ahead(y);
						right();
						ahead(x);
					} else if (dir == 180) {
						right();
						ahead(y);
						right();
						ahead(x);
					} else {
						left();
						ahead(x);
						left();
						ahead(y);
					}
				} else {
					if (dir == 0) {
						ahead(x);
					} else if (dir == 90) {
						right();
						ahead(x);
					} else if (dir == 180) {
						uturn();
						ahead(x);
					} else if (dir == 270) {
						left();
						ahead(x);
					}
				}
			} else {
				if (y > 0) {
					if (dir == 0) { 
						right();
						ahead(y);
					} else if (dir == 90) {
						uturn();
						ahead(y);
					} else if (dir == 180) {
						left();
						ahead(y);
					} else {
						ahead(y);
					}
				} else if (y < 0) {
					if (dir == 0) {
						left();
						ahead(y);
					} else if (dir == 90) {
						ahead(y);
					} else if (dir == 180) {
						right();
						ahead(y);
					} else {
						uturn();
						ahead(y);
					}
				}
			}
			if (i != n - 1) System.out.println();
		}
	}
	
	private static void ahead(int n) {
		System.out.println("1\n" + Math.abs(n));
	}
	
	private static void right() {
		System.out.println("2");
	}
	
	private static void left() {
		System.out.println("3");
	}
	
	private static void uturn() {
		System.out.println("3\n3");
	}
}