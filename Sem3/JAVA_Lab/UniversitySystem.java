import java.io.*;
import java.util.*;

class Student{
    private int enrollmentNo;
    private String name;
    private float marks[];

    public static int totalAdmissions=0;
    public static final String UNIVERSITY_NAME ="PDEU";
    
    public Student() {
        this.enrollmentNo=0;
        this.name="Unknown";
        this.marks = new float[]{0,0,0};
        totalAdmissions++;
    }

    public Student(int enrollmentNo, String name, float marks[]) {
        this.enrollmentNo=enrollmentNo;
        this.name=name;
        this.marks = marks;
        totalAdmissions++;
    }

    public double Calper(){
        float total =0;
        for (float mark : marks) {
            total += mark;
        }
        return (total/3.00);
    }

    public void displayDetails() {
        double exactPercentage = Calper();
        int roundedPercentage = (int) exactPercentage; 
        System.out.println("University: " + UNIVERSITY_NAME);
        System.out.println("Enrollment No: " + this.enrollmentNo);
        System.out.println("Name: " + this.name);
        System.out.println("Exact Percentage: " + exactPercentage + "%");
        System.out.println("Rounded Percentage: " + roundedPercentage + "%\n");
    }
}

public class UniversitySystem{
	public static void main(String[] args) {
        Student[] batch = new Student[3];

        batch[0] = new Student(101, "Ishan", new float[]{85, 90, 88});
        batch[1] = new Student(102, "Aikya", new float[]{78, 82, 80});
        batch[2] = new Student(103, "Umang", new float[]{92, 95, 89});

        for (int i = 0; i < batch.length; i++) {
            batch[i].displayDetails();
        }

        System.out.println("Total Admissions for this session: " + Student.totalAdmissions);
    }
}