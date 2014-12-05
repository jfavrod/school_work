public class Student
{
    private String name, major;
    private double gpa, total_points, courses_recorded;
    private String[] courses;
    private static int totalCourses = 0;

    public Student() 
    {
        name = "No Name Given";
        major = "No Major Recorded";
        gpa = 0.0;
        total_points = 0.0;
        courses_recorded = 0.0;
        courses = new String[10];
    }
    
    public Student(String newName)
    {
        name = newName;
        major = "No Major Recorded";
        gpa = 0.0;
        total_points = 0.0;
        courses_recorded = 0.0;
        courses = new String[10];
    }
    
    public Student(String newName, String newMajor)
    {
        name = newName;
        major = newMajor;
        gpa = 0.0;
        total_points = 0.0;
        courses_recorded = 0.0;
        courses = new String[10];
    }

    //setting methods
    public void setStudentName(String newName) {
        name = newName;
    }
    
    public void setStudentMajor(String newMajor) {
        major = newMajor;
    }
    
    public void updateStudentGpa(double newPoints) {
        courses_recorded = courses_recorded + 1.0;
        total_points = total_points + newPoints;
        gpa = total_points/courses_recorded;
    }
    
    //the logic for adding to the courses array
    //first check for empty slot in the array...
    public boolean checkCourseArray()
    {
        for(int i = 0; i <= courses.length - 1; i++)
        {
            if (courses[i] == null)
            {
                System.out.println("Courses left after this entry: " + (courses.length - (i+1)) );
                return true;
            }
        }
        System.out.println("Sorry can't add more courses.");
        return false;
    }
    
    //then entries go in the first empty slot in the array
    public void setNewCourse(String newCourse)
    {
        for (int i = 0; i <= courses.length - 1; i++)
        {
            if (courses[i] == null)
            {
                courses[i] = newCourse;
                totalCourses++;
                break;
            }
        }
    }
    
    //accessor methods
    public String getStudentName()
    {
        return name;
    }
    
    public String getStudentMajor()
    {
        return major;
    }
    
    public double getStudentGpa() 
    {
        return gpa;
    }
    
    public String[] getStudentCourses()
    {
        for (int i = 0; i< courses.length; i = i+2) 
        {
            System.out.printf("%30s %30s \n", courses[i], courses[i+1]);
        }
        return courses;
    }
    
    public String toString()
    {
        String val;
        val = String.format("\nName: %s\nMajor: %s\nGPA: %s\n", name, major, gpa);
        val += "The total number of courses is " + totalCourses + "\n";
        for (int i = 0; i< courses.length; i = i+2) 
        {
            if (courses[i] != null)
            {
                if (courses[i+1] == null) {
                    courses[i+1] = "";
                }
                val += String.format("%30s %30s \n", courses[i], courses[i+1]);
                if (courses[i+1] == "") {
                    courses[i+1] = null;
                }
            }
        }
        return val;
    }

}
