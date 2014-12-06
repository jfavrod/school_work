import java.util.*;


public class Hw10
{

    public static void main(String[] args)
    {
        int max_temp = -1;
        
        while (max_temp <= 0) {
            max_temp = get_user_input();
        }
        
        System.out.println("Got " + max_temp);
    }


    public static int get_user_input()
    {
        int input = -1;
        Scanner kb = new Scanner(System.in);

        
        try {
            System.out.println("Enter max temperature [integer > 0]");
            input = kb.nextInt();
        }
        catch (InputMismatchException ime) {
            System.err.println("\nInvalid Input");
        }
        catch (IllegalStateException ise) {
            System.err.println("Input/output failure.");
            System.exit(1);
        }

        if (input <= 0) {
            printMaxTempSpec();
            input = -1;
        }

        return input;
    }


    public static void printMaxTempSpec()
    {
            System.out.println("Max temperature must be a positive integer " +
                    "( < 2147483648 )\n");
    }
}
