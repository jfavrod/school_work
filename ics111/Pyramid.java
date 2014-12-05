import java.util.Scanner;

public class Pyramid {
	public static void main (String args[]) 
  {
    Scanner keyboard = new Scanner(System.in);
    String quit = "";

    while(!quit.equalsIgnoreCase("q"))
    {
      System.out.println("How high do you want to build your pyramid?");
      int pyramid_height = keyboard.nextInt();
      
      for ( int i = 0; i < pyramid_height; i++ )
      {
        int blocks = ( i + i + 1 );
        
        for ( int loop = 0; loop < (pyramid_height - i); loop++ )
          System.out.print(" ");

        for ( int loop2 = 0; loop2 < blocks; loop2++ )
          System.out.print("*");
        
        System.out.println();
      }

    System.out.println("Wanna go again? Press enter or Q to quit");
    keyboard.nextLine();
    quit = keyboard.nextLine();
    }
	}
}
