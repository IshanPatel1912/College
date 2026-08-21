// 4. Write a program that calculates percentage marks of the student if marks of 6 subjects are given.

import java.io.*; 
import java.util.*; 

public class L0q4 { 
    public static class Student { 
        public int rNo; 
        public String name; 
        public int marks[] = new int[6]; 
        
        public void getData() { 
            Scanner sc = new Scanner(System.in); 
            
            System.out.print("Enter the student's Roll Number: "); 
            rNo = sc.nextInt(); 
            
            sc.nextLine(); 
            
            System.out.print("Enter the student's Name: "); 
            name = sc.nextLine(); 
            
            System.out.println("\nPlease enter the marks for 6 subjects:");
            for(int i = 0; i < marks.length; i++) {
                System.out.print("Enter the marks for Subject " + (i + 1) + ": "); 
                marks[i] = sc.nextInt();
            }
        } 
        
        public void disp() { 
            System.out.println("\n--- Student Details ---");
            System.out.println("Roll Number: " + rNo); 
            System.out.println("Student Name: " + name); 
            
            int sum = 0;
            for(int i = 0; i < marks.length; i++) { 
                sum = sum + marks[i];
            } 
            
            float percentage = (float) sum / marks.length; 
            
            System.out.println("Total Marks: " + sum);
            System.out.println("Percentage: " + percentage + "%");
        } 
    } 

    public static void main(String[] args) { 

        System.out.println("=========================================");
        System.out.println("Roll Number: 25BCP113");
        System.out.println("Name: Patel Ishan");
        System.out.println("=========================================");

        System.out.println("This program calculates a student's total marks and percentage based on 6 subjects.\n");
        System.out.println("-----------------------------------------");
        Student s1 = new Student(); 
        s1.getData(); 
        s1.disp();
    } 
}