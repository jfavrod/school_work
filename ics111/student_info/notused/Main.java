import java.util.*;

public class Main
{

    public static void main (String args[]) 
    {
        Scanner keyboard = new Scanner(System.in);
        String selection = "";        
        Student2 dexter = new Student2();

        System.out.println("Welcome to the student records update program.");        
        System.out.println("Please enter the name of the student?");
        String name = keyboard.nextLine();
        
        System.out.println("\nWhat's the student's major?");
        String major = keyboard.nextLine();
        
        dexter.setStudentName(name);
        dexter.setStudentMajor(major);

        System.out.println("******************************************************");
        System.out.println("\nPress enter to add a course to the student's record,");
        System.out.println("or enter 'n' to skip this step.");
        selection = keyboard.nextLine();
        
        while (!selection.equalsIgnoreCase("n")) {
            //check the course array for empty slots
            //return true for empty, false if not
            boolean check = dexter.checkCourseArray();
            if (check == true) {
                System.out.println("Enter in the course.");
                String newCourse = keyboard.nextLine();
                dexter.setNewCourse(newCourse);
            }
            else { break; }            

            System.out.println();
            System.out.println("Press enter to add another course or 'n' to move on.");
//            selection = keyboard.nextLine();
            selection = keyboard.nextLine();
        }
        
        System.out.println(dexter);
    }
}
