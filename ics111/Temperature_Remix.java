/*
 * TemperatureConvert.java
 * 
 * Copyleft 2013 Jason Favrod <lakona808@gmail.com> 
 * 
 * A program that takes user input of either Celsius or Fahrenheit and
 * converts into the other.
 * 
 * Degrees_C = 5(Degrees_F− 32)/9
 * Degrees_F = (9(Degrees_C)/5) + 32)
 * 
 */

import java.util.Scanner;

public class Temperature_Remix 
{
	
	public static void main (String args[])
	{
		
		Scanner keyboard = new Scanner(System.in);
	  String quit;
    double dTemp = Double.NaN;

		
		do 
		{
			while (Double.isNaN(dTemp))
			{
        try
        {
          System.out.println("Enter in the temperature and press enter.");
          dTemp = keyboard.nextDouble();
          keyboard.nextLine();
        }catch(Exception e )
          {
            System.out.println("ERROR! Your Input was invalid!");
            keyboard.nextLine();
          }
			}
		 
			
			System.out.println("Enter the base unit. C for Celsius; F for Fahrenheit and press enter");
			String unit = keyboard.nextLine();
			 
			if (unit.equalsIgnoreCase("c"))
			{
				//the converted Celsius to Fahrenheit
				double dCtoF = (9* dTemp /5) +32;
				System.out.printf("%.0f", dTemp);
				System.out.print("\u00b0 Celsius is equal to ");
				System.out.printf("%.2f", dCtoF);
				System.out.println("\u00b0 Fahrenheit.");
				System.out.println("\nPress enter to do another?, or q to quit");
				quit = keyboard.nextLine();
				dTemp = Double.NaN;
			}
			else if (unit.equalsIgnoreCase("f"))
			{
				//the converted Celsius to Fahrenheit
				double dFtoC = 5*(dTemp - 32)/9;
				System.out.printf("%.0f", dTemp);
				System.out.print("\u00b0 Fahrenheit is equal to ");
				System.out.printf("%.2f", dFtoC);
				System.out.println("\u00b0 Celsius.");
				System.out.println("\nPress enter to do another, or q to quit");
				quit = keyboard.nextLine();
				dTemp = Double.NaN;
			}
			else
			{
				System.out.println("Your Input was invalid, press enter try again or q to quit");
				quit = keyboard.nextLine();
			}
      
      if( quit.equalsIgnoreCase("q") ){System.out.println("Good Bye");}
      
		} while (!quit.equalsIgnoreCase("q"));
	  	
	}
}
