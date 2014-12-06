import java.util.*;


public class Hw10
{

    public static void main(String[] args)
    {
        int max_temp = -1;
        
        while (max_temp < 0) {
            max_temp = get_user_input();
        }
        
        System.out.println("Got " + max_temp);
    }

    public static int get_user_input()
    {
        int input = -1;
        Scanner kb = new Scanner(System.in);

        
        try {
            System.out.println("Give me an int");
            input = kb.nextInt();
        }
        catch (InputMismatchException ime) {
            System.err.println("Invalid Input " + ime.getMessage());
        }

        return input;
    }
}
