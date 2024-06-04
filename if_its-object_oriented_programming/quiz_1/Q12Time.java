// File: Q12Time.java
public class Q12Time {
	// Getters
	public static double getMinHandDev(double min) {
		// Get the minute hand deviation from 12:00/00:00 position
		
		/**
		 * One hour spans 360 degrees of rotation in the minute handle,
		 * and because one hour spans 60 minutes, we multiply the minute count
		 * with 6 (60 * 6 = 360) to find the degrees deviation in the minute hand
		 */
		double result = min * 6;
		
		return result;
	}
	public static double getHourHandDev(double hour, double min) {
		// Get the hour hand deviation from 12:00/00:00 position.
		
		/** 
		 * Get the deviation of the hour if the given minute is nonexistent.
		 * Here we first find the remainder of the hour count by 12,
		 * (18:00 == 6:00, 15:00 == 3:00) because we only want the position of the hand.
		 * 
		 * Because there are 12 hours in one cycle, and because there is 360 degrees
		 * of rotation in one cycle, one hour is (360 / 12) = 30 degrees. Multiply
		 * the hour count by 30 will result in the degree deviation.
		 */
		double result = (hour % 12) * 30;
		
		/**
		 * Add the minutes into the calculation of the deviation.
		 * 
		 * One hour spans 30 degrees of rotation, from 0 degrees in hour with minute 0,
		 * up until 30 degrees in hour with minute 60. As there are 60 minutes in an hour,
		 * and 30 degrees of rotation in an hour, so we divide the number of minutes by 2
		 * (60 / 2 = 30) to find the addition in deviation of the hour handle.
		 */
		result += min / 2;
		
		return result;
	}
	public static double getDegBetweenHands(double hour, double min) {
		// Get the degree between the hour and minute hand
		double hourHandDev = getHourHandDev(hour, min);
		double minHandDev = getMinHandDev(min);
		
		double result;
		if (hourHandDev < minHandDev) {
			/**
			 * Hour hand is after min hand in CCW direction, so add 360
			 * and subtract difference to get the degree
			 */
			result = 360 - Math.abs(hourHandDev - minHandDev);
		} else {
			/**
			 * Hour hand us before min hand in CCW direction, just 
			 * subtract the deviations to get the degree
			 */
			result = Math.abs(hourHandDev - minHandDev);
		}
		
		return result;
	}
}