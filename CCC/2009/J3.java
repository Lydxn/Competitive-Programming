package ccc_2009;
import java.util.Scanner;

public class J3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int ottawaTime = in.nextInt();
		
		System.out.println(zoneTime(ottawaTime, 0) + " in Ottawa");
		System.out.println(zoneTime(ottawaTime, -300) + " in Victoria");
		System.out.println(zoneTime(ottawaTime, -200) + " in Edmonton");
		System.out.println(zoneTime(ottawaTime, -100) + " in Winnipeg");
		System.out.println(zoneTime(ottawaTime, 0) + " in Toronto");
		System.out.println(zoneTime(ottawaTime, 100) + " in Halifax");
		System.out.println(zoneTime(ottawaTime, 130) + " in St. John's");
	}
	
	private static int zoneTime(int zone, int time) {
		int hour = (zone + time) / 100;
		int min = (zone + time) % 100;
		
		if (min >= 60) {
			hour++;
			min -= 60;
		} else if (min < 0) {
			hour--;
			min += 100;
		}
		
		if (hour >= 24) {
			hour -= 24;
		} else if (hour < 0) {
			hour += 24;
		}
		
		return hour * 100 + min; 
	}

}
