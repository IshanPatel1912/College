import java.util.Scanner;

interface Payment {
    void makePayment(double amount);
    void generateReceipt();
    void displayPaymentDetails();
}

class PaymentHelper {

    public static boolean validateAndProcess(String type, double amount, double limit) {
        if (amount > limit) {
            System.out.println("\n[Transaction Failed] Amount exceeds " + type + " limit of ₹" + limit);
            return false;
        }
        System.out.println("\n[Processing] Successfully authorized ₹" + amount + " via " + type + ".");
        return true;
    }

    public static void printSummary(String type, String holder, String identifier, double amount, boolean status) {
        System.out.println("[Details] Type: " + type + " | User: " + holder + 
                           " | ID: " + identifier + " | Amount: ₹" + amount + 
                           " | Status: " + (status ? "SUCCESS" : "FAILED"));
        System.out.println("--------------------------------------------------------------------------------");
    }
}

class CreditCardPayment implements Payment {
    private double amount;
    private String holderName;
    private String cardNumber;
    private boolean isSuccess = false;
    private final double LIMIT = 800000.00; 

    public CreditCardPayment(String holderName, String cardNumber) {
        this.holderName = holderName;
        this.cardNumber = cardNumber;
    }

    @Override
    public void makePayment(double amount) {
        this.amount = amount;
        this.isSuccess = PaymentHelper.validateAndProcess("Credit Card", amount, LIMIT);
    }

    @Override
    public void generateReceipt() {
        if (!isSuccess) {
            System.out.println("[Receipt] No receipt generated due to failed payment.");
            return;
        }
        System.out.println("[Receipt] Generated for Card ending in " + cardNumber.substring(cardNumber.length() - 4));
    }

    @Override
    public void displayPaymentDetails() {
        PaymentHelper.printSummary("Credit Card", holderName, cardNumber, amount, isSuccess);
    }
}

class UPIPayment implements Payment {
    private double amount;
    private String userName;
    private String upiId;
    private boolean isSuccess = false;
    private final double LIMIT = 100000.00; 

    public UPIPayment(String userName, String upiId) {
        this.userName = userName;
        this.upiId = upiId;
    }

    @Override
    public void makePayment(double amount) {
        this.amount = amount;
        this.isSuccess = PaymentHelper.validateAndProcess("UPI", amount, LIMIT);
    }

    @Override
    public void generateReceipt() {
        if (!isSuccess) {
            System.out.println("[Receipt] No receipt generated due to failed payment.");
            return;
        }
        System.out.println("[Receipt] Generated for UPI Transaction ID: TXN" + (int)(Math.random() * 100000));
    }

    @Override
    public void displayPaymentDetails() {
        PaymentHelper.printSummary("UPI", userName, upiId, amount, isSuccess);
    }
}

class NetBankingPayment implements Payment {
    private double amount;
    private String accountHolder;
    private String accountNumber;
    private String bankName;

    public NetBankingPayment(String accountHolder, String accountNumber, String bankName) {
        this.accountHolder = accountHolder;
        this.accountNumber = accountNumber;
        this.bankName = bankName;
    }

    @Override
    public void makePayment(double amount) {
        this.amount = amount;
        PaymentHelper.validateAndProcess("NetBanking (" + bankName + ")", amount, Double.MAX_VALUE);
    }

    @Override
    public void generateReceipt() {
        System.out.println("[Receipt] Generated for NetBanking Account: " + accountNumber.replaceAll(".(?=.{4})", "*"));
    }

    @Override
    public void displayPaymentDetails() {
        PaymentHelper.printSummary("NetBanking", accountHolder, bankName + " (" + accountNumber + ")", amount, true);
    }
}

public class L4q1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Payment p = null; 

        System.out.println("=== WELCOME TO THE PAYMENT GATEWAY ===");
        System.out.print("Enter payment amount: ₹");
        double amount = scanner.nextDouble();
        scanner.nextLine(); 

        System.out.println("\nSelect Payment Method:");
        System.out.println("1. Credit Card (Limit: ₹8 Lakh)");
        System.out.println("2. UPI (Limit: ₹1 Lakh)");
        System.out.println("3. NetBanking");
        System.out.print("Enter choice (1-3): ");
        int choice = scanner.nextInt();
        scanner.nextLine(); 

        switch (choice) {
            case 1:
                System.out.print("Enter Cardholder Name: ");
                String cardName = scanner.nextLine();
                System.out.print("Enter 16-digit Card Number: ");
                String cardNum = scanner.nextLine();
                p = new CreditCardPayment(cardName, cardNum);
                break;

            case 2:
                System.out.print("Enter Your Name: ");
                String upiName = scanner.nextLine();
                System.out.print("Enter UPI ID (e.g., user@bank): ");
                String upiId = scanner.nextLine();
                p = new UPIPayment(upiName, upiId);
                break;

            case 3:
                System.out.print("Enter Account Holder Name: ");
                String accName = scanner.nextLine();
                System.out.print("Enter Account Number: ");
                String accNum = scanner.nextLine();
                System.out.print("Enter Bank Name: ");
                String bankName = scanner.nextLine();
                p = new NetBankingPayment(accName, accNum, bankName);
                break;

            default:
                System.out.println("Invalid selection. Terminating process.");
                break;
        }

        if (p != null) {
            p.makePayment(amount);
            p.generateReceipt();
            p.displayPaymentDetails();
        }

        scanner.close();
    }
}