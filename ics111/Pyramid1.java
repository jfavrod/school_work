import java.util.Scanner;

public class Pyramid1 {	
	public static void main (String args[]) {

    Scanner keyboard = new Scanner(System.in);
    String quit = "";

    while(!quit.equalsIgnoreCase("q")){
    int pyramid_height = 0, count = 0;
    
    System.out.println("How high do you want to build your pyramid?");
    pyramid_height = keyboard.nextInt();
    int offset = pyramid_height - 1;

      for ( int i = 0; i < pyramid_height; i++ )
      {
        int blocks = ( i + i + 1 );
        int loop = 0;
        
        while (loop < offset)
        {
          System.out.print(" ");
          loop++;
        }
        offset--;
        
        do
        {
          System.out.print("*");
          count++;
        }while(count < blocks);
        
        System.out.println();
        count = 0;
        }
    System.out.println("Wanna go again? Enter or Q");
    keyboard.nextLine();
    quit = keyboard.nextLine();
    }
	}
}
