// 6. Write a program to accept a line and check how many consonants and vowels are there in line.

import java.io.*;
import java.util.*;

public class L0q6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("=========================================");
        System.out.println("Name: Patel Ishan");
        System.out.println("Roll Number: 25BCP113");
        System.out.println("=========================================");

        System.out.println("This program counts the number of vowels and consonants in a given line of text.\n");
        System.out.println("-----------------------------------------");
        
        System.out.print("Please enter a sentence or line of text: ");
        String line = scanner.nextLine();
        
        int vowelsCount = 0;
        int consonantsCount = 0;
        
        String lowerCaseLine = line.toLowerCase();
        
        for (int i = 0; i < lowerCaseLine.length(); i++) {
            char ch = lowerCaseLine.charAt(i);
            
            if (Character.isLetter(ch)) {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowelsCount++;
                } else {
                    consonantsCount++;
                }
            }
        }
  
        System.out.println("\n--- Results ---");
        System.out.println("Total Vowels found: " + vowelsCount);
        System.out.println("Total Consonants found: " + consonantsCount);
        System.out.println("-----------------------------------------");
        
        scanner.close(); 
    }
}