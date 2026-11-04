//3.	Write a program to enter two numbers and perform mathematical operations on them.

import java.io.*;
import java.util.*;

public class L0q3 {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
        
      System.out.println("=========================================");
      System.out.println("Roll Number: 25BCP113");
      System.out.println("Name: Patel Ishan");
      System.out.println("=========================================");
        
      System.out.println("Program: Perform basic mathematical operations on two numbers.");
      System.out.println("-----------------------------------------");
        
      System.out.print("Please enter the first number: ");
      double a = sc.nextDouble();
        
      System.out.print("Please enter the second number: ");
      double b = sc.nextDouble();
        
      System.out.println("\nCalculation Results:");
      System.out.println("-----------------------------------------");
        
      System.out.println("The Sum of the numbers is: " + (a + b));
      System.out.println("The Difference (First - Second) is: " + (a - b));
      System.out.println("The Product (Multiplication) is: " + (a * b));
        
      if (b != 0) {
         System.out.println("The Quotient (First / Second) is: " + (a / b));
      } else {
         System.out.println("The Quotient (First / Second) is: Undefined (Cannot divide by zero)");
      }
        
      System.out.println("-----------------------------------------");
      sc.close();
    }
}
