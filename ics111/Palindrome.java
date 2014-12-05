import java.util.Scanner;

 class Palindrome {
    public static void main (String [] args)
    {
        Scanner keyboard = new Scanner(System.in);
        String goAgain = "y";
        do {
            System.out.println("enter word to test for palindrome");
            String testWord = stripSpaces(keyboard.nextLine());
            System.out.println(isPal(testWord));
            System.out.println("wanna go again y|n ?");
            goAgain = keyboard.nextLine();
        } while (goAgain.equalsIgnoreCase("y"));
    }
     
    private static String isPal(String testWord) 
    {
        boolean match = true;
        char[] forward, backwards;
        forward = new char[testWord.length()];
        backwards = new char[testWord.length()];

        for (int i = 0; i < testWord.length(); i++) 
        {
            forward[i] = testWord.charAt(i);
        } 
        for (int j = testWord.length() - 1; j >= 0; j--) 
        {
            backwards[((testWord.length() -1) - j)] = testWord.charAt(j);
        }
       
        for (int k = 0; k < forward.length; k++) 
        {
            if (!Character.toString(forward[k]).equalsIgnoreCase(Character.toString(backwards[k]))) {
                match = false;
            }
        }

        if (match == true) {
            return "Is a palindrome";
        }
        else {
            return "Not a palindrome";
        }
    }
    
    private static String stripSpaces(String testWord)
    {
        String str = testWord;
        str = str.replaceAll("[\\s\\.]", "");
        return str;
    }
}
