/*
 * addingThreeNumbers.java
 * 
 * Copyright 2013 Jason Favrod <lakona808@gmail.com>
 * 
 * 
 * 
 */
 
 //A simple programm that adds and multiplys three numbers.

import java.util.Scanner;

public class addingThreeNumbers {
	
	public static void main (String args[]) {
    
    int iNumb1 = 0, iNumb2 = 0, iNumb3 = 0;

    Scanner keyboard = new Scanner(System.in);
    System.out.println("Aloha, enter the first of three whole numbers");
    System.out.println("to be added and multiplied, and press enter");
    iNumb1 = iNumb1 + keyboard.nextInt();
    
    System.out.println("Got it, what's the next number?");
    iNumb2 = iNumb2 + keyboard.nextInt();
    
    System.out.println("Ok what's the last number?");    
    iNumb3 = iNumb3 + keyboard.nextInt();
    
    System.out.println("The sum of " + iNumb1 + ", " + iNumb2 + ", and " + iNumb3 + " is:");
    int sum = iNumb1 + iNumb2 + iNumb3;      
    System.out.println(sum);
    
    System.out.println("And the product of those numbers is:");
    int product = iNumb1 * iNumb2 * iNumb3;
    System.out.println(product);
	}
}

