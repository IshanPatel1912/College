//2.	Write a program in Java to generate first n prime numbers.

import java.io.*;
import java.util.*;

public class L0q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("=========================================");
        System.out.println("Name: Patel Ishan");
        System.out.println("Roll Number: 25BCP113");
        System.out.println("=========================================");
        
        System.out.println("Program: Generate the first 'n' prime numbers.");
        System.out.println("-----------------------------------------");
        
        System.out.print("Please enter the total number of prime numbers you want to generate: ");
        int n = sc.nextInt();
        
        System.out.println("\nGenerating the first " + n + " prime numbers:");
        System.out.println("-----------------------------------------");

        int m = 2; 
        for(int i = 1; i <= n; i++){ 
            while(true){ 
                int count = 0; 
                for(int j = 1; j <= m; j++){ 
                    if(m % j == 0) 
                        count++; 
                } 
                if (count > 2){ 
                    m++; 
                    continue; 
                } else { 
                    // Refined output sentence
                    System.out.println("Prime Number " + i + ": " + m); 
                    m++; 
                    break; 
                } 
            } 
        }
        
        System.out.println("-----------------------------------------");
        sc.close();
    }
}
