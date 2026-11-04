//9.    Write an interactive program to print a string entered in a pyramid form. For instance, the string “stream” has to be displayed as follows:
//               S
//              S t
//             S t r
//            S t r e
//           S t r e a
//          S t r e a m

import java.io.*;
import java.util.*;

public class L0q9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("=========================================");
        System.out.println("Name: Patel Ishan");
        System.out.println("Roll Number: 25BCP113");
        System.out.println("=========================================");
        
        System.out.println("This program takes a word from the user and prints it in a pyramid pattern.\n");
        System.out.println("-----------------------------------------");

        System.out.print("Please enter a word: ");
        String s = sc.next();
        int n = s.length();
        
        System.out.println();
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= (n - i); j++){
                System.out.print(" ");
            }
            for(int k = 0; k < i; k++){
                System.out.print(s.charAt(k) + " ");
            }
            System.out.println();
        }
        System.out.println("-----------------------------------------");
        sc.close();
    }
}
