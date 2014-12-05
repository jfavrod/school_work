/*
 * SwitchStatement.java
 * 
 * Jason Favrod
 * 
 * An example of the Java Switch statement.
 * 
 */

import java.util.Scanner;

public class SwitchStatement {
	
	public static void main (String args[]) {
		int day = 0;
    
    Scanner keyboard = new Scanner(System.in);
    
    System.out.println("Please enter the day of the week 1-7 and press enter");
    day = keyboard.nextInt();
    
    switch (day)
    {
      case 1: System.out.println("Sunday");
        break;
      case 2: System.out.println("Monday");
        break;
      case 3: System.out.println("Tuesday");
        break;
      case 4: System.out.println("Wednesday");
        break;
      case 5: System.out.println("Thursday");
        break;
      case 6: System.out.println("Friday");
        break;
      case 7: System.out.println("Saturday");
        break;
      default: System.out.println("You did not give a valid day of the week");
        break;
    }
	}
}

