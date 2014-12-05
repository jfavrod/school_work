import java.util.Scanner;

public class ArrayAssignment
{

    public static void main (String args[]) 
    {
        Scanner keyboard = new Scanner(System.in);
        int[] number = new int[5];
        int sum = 0, product = 1, average = 0;
        
        System.out.println("Let's do some arithitic!");
        System.out.println("Enter in the first of 5 integers.");
        number[0] = keyboard.nextInt();
        System.out.println("Now enter the second integer.");
        number[1] = keyboard.nextInt();
        System.out.println("Got it, now the next one.");
        number[2] = keyboard.nextInt();
        System.out.println("One more.");
        number[3] = keyboard.nextInt();
        System.out.println("Last one.");
        number[4] = keyboard.nextInt();        
        
        System.out.print("\nYou entered " + number[0] + ", " + number[1] + ", ");
        System.out.println(number[2] + ", " + number[3] + " and " + number[4]);
        
        for (int i = 0; i < number.length; i++)
            sum = sum + number[i];
            
        for (int i = 0; i < number.length; i++)
            product = product * number[i];
            
        average = sum / number.length;
        
        System.out.println("\nThe average number in the set is " + average);
        System.out.println("When you add them together you get " + sum);
        System.out.println("When you multiply them you get " + product);
    }
}


