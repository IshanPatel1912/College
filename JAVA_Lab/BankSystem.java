import java.io.*;
import java.util.*;

public class BankSystem {

	static class Customer {
    		int accNo;
    		String name;
    		double balance;
    		Customer next;
	}

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        Customer head = null;
        int choice;

        do {
            System.out.println("\n===== BANK SYSTEM =====");
            System.out.println("1. Add Customer");
            System.out.println("2. Display Customers");
            System.out.println("3. Deposit");
            System.out.println("4. Withdraw");
            System.out.println("5. Check Balance");
            System.out.println("6. Edit Customer");
            System.out.println("7. Exit");

            System.out.print("Enter Choice: ");
            choice = sc.nextInt();

            if (choice == 1) {

                Customer newCustomer = new Customer();

                System.out.print("Enter Account Number: ");
                newCustomer.accNo = sc.nextInt();

                sc.nextLine();

                System.out.print("Enter Name: ");
                newCustomer.name = sc.nextLine();

                System.out.print("Enter Balance: ");
                newCustomer.balance = sc.nextDouble();

                newCustomer.next = null;

                if (head == null) {
                    head = newCustomer;
                } else {
                    Customer temp = head;
                    while (temp.next != null) {
                        temp = temp.next;
                    }
                    temp.next = newCustomer;
                }

                System.out.println("Customer Added.");

            } else if (choice == 2) {

                if (head == null) {
                    System.out.println("No Customer Found.");
                } else {
                    Customer temp = head;

                    while (temp != null) {
                        System.out.println("--------------------");
                        System.out.println("Account No : " + temp.accNo);
                        System.out.println("Name       : " + temp.name);
                        System.out.println("Balance    : " + temp.balance);
                        temp = temp.next;
                    }
                }

            } else if (choice == 3) {

                int acc;
                double amount;

                System.out.print("Enter Account Number: ");
                acc = sc.nextInt();

                Customer temp = head;

                while (temp != null) {

                    if (temp.accNo == acc) {
                        System.out.print("Enter Deposit Amount: ");
                        amount = sc.nextDouble();

                        temp.balance = temp.balance + amount;

                        System.out.println("Deposit Successful.");
                        break;
                    }

                    temp = temp.next;
                }

                if (temp == null) {
                    System.out.println("Account Not Found.");
                }

            } else if (choice == 4) {

                int acc;
                double amount;

                System.out.print("Enter Account Number: ");
                acc = sc.nextInt();

                Customer temp = head;

                while (temp != null) {

                    if (temp.accNo == acc) {

                        System.out.print("Enter Withdraw Amount: ");
                        amount = sc.nextDouble();

                        if (amount <= temp.balance) {
                            temp.balance = temp.balance - amount;
                            System.out.println("Withdrawal Successful.");
                        } else {
                            System.out.println("Insufficient Balance.");
                        }

                        break;
                    }

                    temp = temp.next;
                }

                if (temp == null) {
                    System.out.println("Account Not Found.");
                }

            } else if (choice == 5) {

                int acc;

                System.out.print("Enter Account Number: ");
                acc = sc.nextInt();

                Customer temp = head;

                while (temp != null) {

                    if (temp.accNo == acc) {
                        System.out.println("Customer Name : " + temp.name);
                        System.out.println("Balance : " + temp.balance);
                        break;
                    }

                    temp = temp.next;
                }

                if (temp == null) {
                    System.out.println("Account Not Found.");
                }

            } else if (choice == 6) {

                int acc;

                System.out.print("Enter Account Number: ");
                acc = sc.nextInt();

                sc.nextLine();

                Customer temp = head;

                while (temp != null) {

                    if (temp.accNo == acc) {

                        System.out.print("Enter New Name: ");
                        temp.name = sc.nextLine();

                        System.out.print("Enter New Balance: ");
                        temp.balance = sc.nextDouble();

                        System.out.println("Record Updated.");

                        break;
                    }

                    temp = temp.next;
                }

                if (temp == null) {
                    System.out.println("Account Not Found.");
                }

            }

        } while (choice != 7);

        System.out.println("Thank You!");
    }
}