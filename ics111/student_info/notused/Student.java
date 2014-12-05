public class Student
{
    private String name;
    private String major;
    private int points_earned;
    private double gpa = 0.0;
    private double[] grade_points = new double[10];
    private String[] courses = new String[10];

    public void setStudentName(String newName) {
        name = newName;
    }
    public void setStudentMajor(String newMajor) {
        major = newMajor;
    }
    
    //check to see if there is an empty spot
    //in the grade_points array
    public boolean checkPointsArray() {
        int i = 0, limit = grade_points.length;
        while (i <= limit-1) {
            if (grade_points[i] == 0.0) {
                return true;
            }
            else { i++; }
        }
        System.out.println("Can not add more grade points.");
        return false;
    }
    //add a grade point to the first empty slot
    public void setGradePoint(double newPoint) {
        int count = 0, l = grade_points.length;
        while (count <= l-1) {
            if (grade_points[count] == 0.0) {
                grade_points[count] = newPoint;
                gpa = gpa + newPoint;
                points_earned = points_earned +1;
                break;
            }
            count++;
        } 
    }
    //logic for updating the gpa
    public void updateStudentGpa() {
        gpa = gpa/points_earned;
    }
    
    //the logic for adding to the courses array
    //first check for empty slot in the array
    public boolean checkCourseArray() {
        int i = 0, limit = courses.length;
        while (i <= limit-1) {
            if (courses[i] == null) {
                System.out.println("Courses left after this entry: " + (courses.length - (i+1)));
                return true;
            }
            else { i++; }
        }
        System.out.println("Sorry can't add more courses.");
        return false;
    }
    //entries go in the first empty slot in the array
    public void setNewCourse(String newCourse) {
        int count = 0, l = courses.length;
        while (count <= l-1) {
            if (courses[count] == null) {
                courses[count] = newCourse;
                break;
            }
            count++;
        }
    }
    
    public String getStudentName() {
        return name;
    }
    public String getStudentMajor() {
        return major;
    }
    public int getCourseArrayLength() {
        return courses.length;
    }
    public double getStudentGpa() {
        return gpa;
    }
    public String[] getStudentCourses() {
        return courses;
    }
}
