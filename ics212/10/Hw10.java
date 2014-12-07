import java.util.*;


public class Hw10
{
    static {
        System.loadLibrary("tconv");
    }


    /*****************************************************************
     *
     *  Method name:    main
     *
     *  DESCRIPTION:    Runs the Hw10 temp converter.
     *
     *  Parameters:     args (String[]) : cmdline args.
     *
     *  Return values:  void
     *
     ****************************************************************/

    public static void main(String[] args)
    {
        int max_temp = -1;

        while (max_temp <= 0) {
            max_temp = get_user_input();
        }
        
        printConvTable(max_temp);
    }


    /*****************************************************************
     *
     *  Method name:    get_user_input
     *
     *  DESCRIPTION:    Asks the user for an int (temp) and returns
     *                  their response.
     *
     *  Parameters:     void
     *
     *  Return values:  positive int: The user input.
     *                  negitive int: Error.
     *                  
     *
     ****************************************************************/

    public static int get_user_input()
    {
        int input = -1;
        Scanner kb = new Scanner(System.in);

        try {
            System.out.println("To print a conversion table");
            System.out.println("Enter a max temperature [integer > 0]");
            input = kb.nextInt();
        }
        catch (InputMismatchException ime) {
            System.err.println("\nInvalid Input");
        }
        catch (IllegalStateException ise) {
            System.err.println("Input/output error.");
            System.exit(1);
        }

        if (input <= 0) {
            printMaxTempSpec();
            input = -1;
        }

        return input;
    }


    /*****************************************************************
     *
     *  Method name:    printMaxTempSpec
     *
     *  DESCRIPTION:    Prints out the temp spec for the user.
     *
     *  Parameters:     void
     *
     *  Return values:  void
     *
     ****************************************************************/

    public static void printMaxTempSpec()
    {
        System.out.println("Max temperature must be a positive integer " +
                "( < 2147483648 )\n");
    }


    /*****************************************************************
     *
     *  Method name:    round_up
     *
     *  DESCRIPTION:    A native rounding up by 5 function.
     *
     *  Parameters:     temp (int): A temp to round up by 5.
     *
     *  Return values:  int: The given int rounded by 5.
     *
     ****************************************************************/

    public static native int round_up(int temp);


    /*****************************************************************
     *
     *  Method name:    convertFtoC
     *
     *  DESCRIPTION:    A native convert from Fahrenheit to Celcius
     *                  function.
     *
     *  Parameters:     temp (int): A given temperature to convert.
     *
     *  Return values:  The conversion from F to C.
     *
     ****************************************************************/

    public static native float convertFtoC(int temp);



    /*****************************************************************
     *
     *  Method name:    printConvTable
     *
     *  DESCRIPTION:    Prints the conversion table.
     *
     *  Parameters:     max_temp (int): The top value of the conversion
     *                  table.
     *
     *  Return values:  void
     *
     ****************************************************************/

    public static void printConvTable(int max_temp)
    {
        int i = 0;
        Hw10 hw10 = new Hw10();
        max_temp = hw10.round_up(max_temp);

        System.out.printf("%10s %10s", "Fahrenheit", "Celcius");
        System.out.println();

        while (i <= max_temp) {
            System.out.printf("%5d  %14.2f", i, hw10.convertFtoC(i));
            System.out.println();
            i += 5;
        }
    }
}
