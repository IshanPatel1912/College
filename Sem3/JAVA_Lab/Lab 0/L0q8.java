// 8. Create a class which ask the user to enter a sentence, and it should display count of each vowel type in the sentence. 
//    The program should continue till user enters a word “quit”. Display the total count of each vowel for all sentences.

import java.io.*;
import java.util.*;

public class L0q8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("=========================================");
        System.out.println("Name: Patel Ishan");
        System.out.println("Roll Number: 25BCP113");
        System.out.println("=========================================");
        System.out.println("This program counts how many of each vowel are used. Type 'quit' at the end to stop.\n");
        System.out.println("-----------------------------------------");

        int countA = 0, countE = 0, countI = 0, countO = 0, countU = 0;
        
        System.out.print("Please enter a sentence (end with 'quit'): ");

        while (true) {
            String s1 = sc.next();
            String s2 = s1.toLowerCase();
            
            if (s2.equals("quit")) {
                break;
            }

            for (int i = 0; i < s2.length(); i++) {
                char x = s2.charAt(i);
                
                switch (x) {
                    case 'a': countA++; break;
                    case 'e': countE++; break;
                    case 'i': countI++; break;
                    case 'o': countO++; break;
                    case 'u': countU++; break;
                }
            }
        }

        System.out.println("\n--- Final Vowel Counts ---");
        System.out.println("A: " + countA);
        System.out.println("E: " + countE);
        System.out.println("I: " + countI);
        System.out.println("O: " + countO);
        System.out.println("U: " + countU);
        
        System.out.println("-----------------------------------------");
        sc.close();
    }
}