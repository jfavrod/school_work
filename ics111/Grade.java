import java.util.Scanner;

public class Grade
{
    public static void main(String[] args)
    {
		Scanner keyboard = new Scanner(System.in);
        int iGradePoints = 0;
        String sLetterGrade = "";
                
        System.out.print("Enter in the grade points you earned to ");
        System.out.println("convert them to a letter grade");
        iGradePoints = keyboard.nextInt();
        
        switch (iGradePoints/10) 
        {
            case 10: 
            case 9:     
                sLetterGrade = "A";
                
                break;
            case 8:
                sLetterGrade = "B";  
            break;
            case 7:     
                sLetterGrade = "C";  
            break;
            case 6:     
                sLetterGrade = "D";  
            break;
            case 5: case 4: case 3: case 2: case 1:     
                sLetterGrade = "F";
            break;
            default:
				System.out.println("Sorry your input was not valid");
			break;
        }   
         System.out.println("You got a(n) " + sLetterGrade);
      }
}
