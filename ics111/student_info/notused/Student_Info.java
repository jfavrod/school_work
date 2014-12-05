public class Student_Info
{
    private String name;
    private String major;
    private double gpa;
    private String[] cources = new String[10];
    
    public void setStudentName(String name) {
        name = this.name;
    }
    public void setStudentMajor(String major) {
        major = this.major;
    }
    
    public String getStudentName() {
        return this.name;
    }
    public String getStudentMajor() {
        return this.major;
    }
}
