import java.util.*;

public class Demo
{

    public static void main (String args[]) 
    {
        Scanner keyboard = new Scanner(System.in);
        Student studentA = new Student();
        Student studentB = new Student();
        
        System.out.println("What's the first Student's name?");            
        String name = keyboard.nextLine();
        studentA.setStudentName(name);
        
        System.out.println("What's the second Student's name?");            
        name = keyboard.nextLine();
        studentB.setStudentName(name);
        
        System.out.println("What's the first student's major?");
        String major = keyboard.nextLine();
        studentA.setStudentMajor(major);
        
        System.out.println("What's the second student's major?");
        major = keyboard.nextLine();
        studentB.setStudentMajor(major);
        
        String option = "";
        do {
            System.out.println("Do you want to add Courses and Grades for a Student?");
            System.out.println("Enter 'y' for yes and 'n' to quit");
            option = keyboard.nextLine();
        
            if (option.equalsIgnoreCase("y"))
            {
                System.out.println("Which student?");
                System.out.print("For ");
                System.out.print(studentA.getStudentName());
                System.out.println(" enter 1");
                System.out.print("For ");
                System.out.print(studentB.getStudentName());
                System.out.println(" enter 2");
                int choice = keyboard.nextInt();
                
                if (choice == 1)
                {
                    String selection = "";
                    keyboard.nextLine();
                    while (!selection.equalsIgnoreCase("n")) {
                        //check the course array for empty slots
                        //return true for empty, false if not
                        boolean check = studentA.checkCourseArray();
                        if (check == true) {
                            System.out.println("Enter in the course.");
                            String newCourse = keyboard.nextLine();
                            studentA.setNewCourse(newCourse);
                            System.out.println("What grade did the student earn (0-4)?");
                            double newPoints = keyboard.nextDouble();
                            studentA.updateStudentGpa(newPoints);
                            System.out.println("Record updated: " + studentA.toString());
                        }
                        else { System.out.println(studentA.toString()); }            

                        System.out.println();
                        System.out.println("Press enter to add another course or 'n' to move on.");
                        keyboard.nextLine();
                        selection = keyboard.nextLine();
                    }
                }
                else if (choice == 2) 
                {
                    String selection = "";
                    keyboard.nextLine();
                    while (!selection.equalsIgnoreCase("n")) {
                        //check the course array for empty slots
                        //return true for empty, false if not
                        boolean check = studentB.checkCourseArray();
                        if (check == true) {
                            System.out.println("Enter in the course.");
                            String newCourse = keyboard.nextLine();
                            studentB.setNewCourse(newCourse);
                            System.out.println("What grade did the student earn (0-4)?");
                            double newPoints = keyboard.nextDouble();
                            studentB.updateStudentGpa(newPoints);
                            System.out.println("Record updated: " + studentB.toString());
                        }
                        else { System.out.println(studentB.toString()); }            

                        System.out.println();
                        System.out.println("Press enter to add another course or 'n' to move on.");
                        keyboard.nextLine();
                        selection = keyboard.nextLine();
                    }
                }
            }

        } while (!option.equalsIgnoreCase("n"));
        
        if (studentA.getStudentGpa() != 0.0){
            System.out.println("The current records for "+ studentA.getStudentName() +" are: ");
            System.out.println(studentA.toString());

        }
        if (studentB.getStudentGpa() != 0.0) {
            System.out.println("The current records for "+ studentB.getStudentName() +" are: ");
            System.out.println(studentB.toString());
        }
        
        System.out.println("Thanks your using the program, Aloha");
    }
}
