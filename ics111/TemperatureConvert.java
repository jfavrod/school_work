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

public class TemperatureConvert 
{
	
	public static void main (String args[]) 
  {
		
    Scanner keyboard = new Scanner(System.in);
    String celsius = "c", fahrenheit = "f";
    
    System.out.println("");
    System.out.println("I will convert a temerature from Fahrenheit to Celsius ");
    System.out.println("or visa-versa. Please enter the base unit; Either C for");
    System.out.println("Celsius, or or F for Fahrenheit and press enter");
    String unit = keyboard.nextLine();
    
    if (unit.equalsIgnoreCase(celsius) || unit.equalsIgnoreCase(fahrenheit))
    {
      if (unit.equalsIgnoreCase(celsius))
      {
        System.out.println("");
        System.out.println("Okay, we'll convert Celsius into Fahrenheit");
        System.out.println("Enter in the temperature and press enter.");
        double dTempC = keyboard.nextDouble();
        
        System.out.println("");
        //the converted Celsius to Fahrenheit
        double dCtoF = (9* dTempC /5) +32;
        System.out.printf("%.0f", dTempC);
        System.out.print(" degrees Celsius is equal to ");
        System.out.printf("%.2f", dCtoF);
        System.out.println(" degrees Fahrenheit.");
      }
      else if (unit.equalsIgnoreCase(fahrenheit))
      {
        System.out.println("");
        System.out.println("Alright, we'll convert Fahrenheit to Celsius");
        System.out.println("Enter in the temperature and press enter.");
        double dTempF = keyboard.nextDouble();
        
        System.out.println("");
        //the converted Fahrenheit to Celsius temperature
        double dFtoC = 5 * (dTempF -32) /9;
        System.out.printf("%.0f", dTempF);
        System.out.print(" degrees Fahrenheit is equal to ");
        System.out.printf("%.2f",dFtoC);
        System.out.println(" degrees Celsius.");
      }
    }
    else
    {
      System.out.println("");
      System.out.println("You did not enter a valid base unit.");
      System.out.println("Please run the program again.");
    }
	}
}

