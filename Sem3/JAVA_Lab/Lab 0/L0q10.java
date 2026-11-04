//10.   Write an interactive program to print a diamond shape. For example, if user enters the number 3, the diamond will be as follows:
//      *
//     * *
//    * * *
//     * *
//      *

import java.io.*;
import java.util.*;

public class L0q10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("=========================================");
        System.out.println("Name: Patel Ishan");
        System.out.println("Roll Number: 25BCP113");
        System.out.println("=========================================");

        System.out.println("This program prints a diamond shape of stars based on the number you enter.\n");
        System.out.println("-----------------------------------------");
        
        System.out.print("Please enter the maximum number of stars for the middle row: ");
        int n = sc.nextInt();
        
        System.out.println();
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i; j++) {
                System.out.print(" ");
            }
            for (int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println(); 
        }
        
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 1; j <= n - i; j++) {
                System.out.print(" ");
            }
            for (int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println(); 
        }
        System.out.println("-----------------------------------------");
        sc.close();
    }
}