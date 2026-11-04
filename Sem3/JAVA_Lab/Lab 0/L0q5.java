// 5. Write a program in Java to find maximum of three numbers using conditional operator.

import java.io.*;
import java.util.*;

public class L0q5 {
    public static void main(String[] args) {
        System.out.println("=========================================");
        System.out.println("Name: Patel Ishan");
        System.out.println("Roll Number: 25BCP113");
        System.out.println("=========================================");

		System.out.println("This program finds the maximum of three numbers using the conditional operator.\n");
		System.out.println("-----------------------------------------");

        Scanner sc = new Scanner(System.in);
        
        System.out.println("Let's find the maximum of three numbers.");

        System.out.print("Please enter the first number: ");
        int a = sc.nextInt();

        System.out.print("Please enter the second number: ");
        int b = sc.nextInt();

        System.out.print("Please enter the third number: ");
        int c = sc.nextInt();

        int max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

        System.out.println("\nThe maximum number among " + a + ", " + b + ", and " + c + " is: " + max);
		System.out.println("-----------------------------------------");
        
        sc.close(); 
    }
}