package system_design.lib_management;

class BankAccount {
    private String accountNumber;
    private String accountHolderName;
    private double balance;

    public BankAccount(String accountNumber, String accountHolderName, double balance) {
        this.accountNumber = accountNumber;
        this.accountHolderName = accountHolderName;
        this.balance = balance;
    }

    // public String getAccountNumber() {
    // return accountNumber;
    // }
    // public String getAccountHolderName() {
    // return accountHolderName;
    // }
    public double getBalance() {
        return balance;
    }

    public void updatebalance(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        BankAccount account = new BankAccount("123456789", "John Doe", 1000.0);
        System.out.println(account.getClass());
        account.updatebalance(1600);
        System.out.print(account.getBalance());
    }
}
