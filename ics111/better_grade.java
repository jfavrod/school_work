import java.util.Scanner;
public class better_grade
{
    public static void main(String[] args)
    {
        int iNumberGrade;//number grade
        String sLetterGrade = "";//letter grade
        boolean error = false;
        

        System.out.println("enter grade"); 
        Scanner in = new Scanner(System.in);
        iNumberGrade = in.nextInt();
        switch ((iNumberGrade-iNumberGrade/100+10)/10)
        {
            case 10:
                sLetterGrade = "an A";
                break;
            case 9:
                sLetterGrade = "a B";
                break;
            case 8:
                sLetterGrade = "a C";
                break;
            case 7:
                sLetterGrade = "a D";
                break;
            case 6: case 5: case 4: 
            case 3: case 2: case 1:
                sLetterGrade = "an F";
                break;
            default:
                System.out.println("Error: grade must be between 0-100");
                error = true;
                sLetterGrade = "";
        }
        if(!error)
        {
            System.out.println("You got " + sLetterGrade);
        }
    }
}
 

