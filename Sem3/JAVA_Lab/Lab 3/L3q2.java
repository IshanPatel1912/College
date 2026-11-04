
abstract class BankAccount {
    String accountNumber;
    String customerName;
    double balance;

    final String BANK_NAME = "ABC Bank";

    BankAccount(String accountNumber, String customerName, double balance) {
        this.accountNumber = accountNumber;
        this.customerName = customerName;
        this.balance = balance;
    }

    final void displayBankInformation() {
        System.out.println("\n╔══════════════════════════════════════╗");
        System.out.println("║          BANK INFORMATION            ║");
        System.out.println("╠══════════════════════════════════════╣");
        System.out.println("║ Bank Name : " + BANK_NAME);
        System.out.println("╚══════════════════════════════════════╝");
    }

    void deposit(double amount) {
        balance += amount;
        System.out.printf("✓ ₹%.2f deposited successfully.%n", amount);
    }

    void displayAccountDetails() {
        System.out.println("\n┌──────────────────────────────────────┐");
        System.out.println("│          ACCOUNT DETAILS             │");
        System.out.println("├──────────────────────────────────────┤");
        System.out.println("│ Account Number : " + accountNumber);
        System.out.println("│ Customer Name  : " + customerName);
        System.out.printf("│ Balance        : ₹%.2f%n", balance);
        System.out.println("└──────────────────────────────────────┘");
    }

    abstract double calculateInterest();
}

class SavingsAccount extends BankAccount {
    double interestRate;

    SavingsAccount(String accountNumber, String customerName, double balance, double interestRate) {
        super(accountNumber, customerName, balance);
        this.interestRate = interestRate;
    }

    @Override
    double calculateInterest() {
        return balance * interestRate / 100;
    }

    void displaySavingsAccountDetails() {
        displayAccountDetails();
        System.out.printf("│ Interest Rate  : %.2f%%%n", interestRate);
        System.out.printf("│ Interest       : ₹%.2f%n", calculateInterest());
    }
}

class PremiumSavingsAccount extends SavingsAccount {
    double cashbackPercentage;

    PremiumSavingsAccount(String accountNumber, String customerName, double balance,
                          double interestRate, double cashbackPercentage) {
        super(accountNumber, customerName, balance, interestRate);
        this.cashbackPercentage = cashbackPercentage;
    }

    @Override
    double calculateInterest() {
        return balance * (interestRate + 1) / 100;
    }

    double calculateCashback(double amount) {
        return amount * cashbackPercentage / 100;
    }
}

final class BankRules {
    void displayRules() {
        System.out.println("\nBank Rules:");
        System.out.println("1. Maintain minimum balance.");
        System.out.println("2. Interest is calculated according to account type.");
        System.out.println("3. Transactions are subject to bank policies.");
    }
}

public class L3q2 {
    public static void main(String[] args) {
        System.out.println("\n╔════════════════════════════════════════╗");
        System.out.println("║       ABC BANK ACCOUNT SYSTEM          ║");
        System.out.println("╚════════════════════════════════════════╝");

        SavingsAccount savings = new SavingsAccount(
                "SA1001", "Rahul Sharma", 50000, 6.5
        );

        System.out.println("\n▶ SAVINGS ACCOUNT");
        savings.deposit(10000);
        savings.displaySavingsAccountDetails();

        System.out.printf("Interest Earned : ₹%.2f%n", savings.calculateInterest());

        PremiumSavingsAccount premium = new PremiumSavingsAccount(
                "PA2001", "Amit Patel", 100000, 7.0, 2.0
        );

        System.out.println("\n▶ PREMIUM SAVINGS ACCOUNT");
        premium.deposit(25000);
        premium.displayAccountDetails();

        System.out.printf("Interest Earned : ₹%.2f%n", premium.calculateInterest());

        double transactionAmount = 15000;
        double cashback = premium.calculateCashback(transactionAmount);

        System.out.printf("Transaction      : ₹%.2f%n", transactionAmount);
        System.out.printf("Cashback Earned  : ₹%.2f%n", cashback);

        premium.displayBankInformation();

        BankRules rules = new BankRules();
        rules.displayRules();

        System.out.println("\n╔════════════════════════════════════════╗");
        System.out.println("║       Thank You for Banking!           ║");
        System.out.println("╚════════════════════════════════════════╝");
    }
}

