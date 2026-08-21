// 7. Write a program to count the number of words that start with capital letters.

import java.io.*;
import java.util.*;

public class L0q7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("=========================================");
        System.out.println("Name: Patel Ishan");
        System.out.println("Roll Number: 25BCP113");
        System.out.println("=========================================");
        
        System.out.println("This program counts the number of words that start with a capital letter.\n");
		System.out.println("-----------------------------------------");

        System.out.print("Please enter a sentence: ");
        String s1 = sc.nextLine();
        
        String s2[] = s1.split("\\s+");

        int count = 0;
        
        for(int i = 0; i < s2.length; i++){
            String temp = s2[i];
            
            if(temp.length() > 0) {
                char x = temp.charAt(0);
                
                if(x >= 65 && x <= 90) {
                    count++;
                }
            }
        }
        
        System.out.println("\n--- Results ---");
        System.out.println("Number of words that start with a capital letter: " + count);
		System.out.println("-----------------------------------------");
        
        sc.close();
    }
}