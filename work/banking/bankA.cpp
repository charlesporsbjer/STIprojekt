#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class BankAccount {
public:
    string accountHolderName;
    int accountNumber;
    double balance;

    BankAccount(string name, int number, double initialBalance) {
        accountHolderName = name;
        accountNumber = number;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " into account " << accountNumber << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << accountNumber << endl;
        } else {
            cout << "Insufficient balance in account " << accountNumber << endl;
        }
    }

    void displayBalance() {
        cout << "Account " << accountNumber << " balance: " << balance << endl;
    }

    void transfer(double amount, BankAccount& recipient) {
        if (balance >= amount) {
            balance -= amount;
            recipient.balance += amount;
            cout << "Transferred " << amount << " from account " << accountNumber << " to account " << recipient.accountNumber << endl;
        } else {
            cout << "Insufficient balance in account " << accountNumber << endl;
        }
    }
};

void saveAccountsToFile(const vector<BankAccount>& accounts, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& account : accounts) {
            file << account.accountHolderName << "," << account.accountNumber << "," << account.balance << endl;
        }
        file.close();
        cout << "Accounts saved to file." << endl;
    } else {
        cout << "Unable to save accounts to file." << endl;
    }
}

void loadAccountsFromFile(vector<BankAccount>& accounts, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string name;
            int number;
            double balance;
            getline(ss, name, ',');
            ss >> number >> balance;
            accounts.push_back(BankAccount(name, number, balance));
        }
        file.close();
        cout << "Accounts loaded from file." << endl;
    } else {
        cout << "Unable to load accounts from file." << endl;
    }
}

int main() {
    vector<BankAccount> accounts;
    string filename = "accounts.dat";

    // Try to load existing accounts from file
    loadAccountsFromFile(accounts, filename);

    int choice;
    while (true) {
        cout << "1. Create new account" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Display account balance" << endl;
        cout << "5. Transfer money" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int number;
                double initialBalance;
                cout << "Enter account holder name: ";
                cin >> name;
                cout << "Enter account number: ";
                cin >> number;
                cout << "Enter initial balance: ";
                cin >> initialBalance;
                accounts.push_back(BankAccount(name, number, initialBalance));
                break;
            }
            case 2: {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                for (auto& account : accounts) {
                    if (account.accountNumber == accountNumber) {
                        account.deposit(amount);
                        break;
                    }
                }
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                for (auto& account : accounts) {
                    if (account.accountNumber == accountNumber) {
                        account.withdraw(amount);
                        break;
                    }
                }
                break;
            }
            case 4: {
                int accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                for (auto& account : accounts) {
                    if (account.accountNumber == accountNumber) {
                        account.displayBalance();
                        break;
                    }
                }
                break;
            }
            case 5: {
                int senderAccountNumber, recipientAccountNumber;
                double amount;
                cout << "Enter sender account number: ";
                cin >> senderAccountNumber;
                cout << "Enter recipient account number: ";
                cin >> recipientAccountNumber;
                cout << "Enter amount to transfer: ";
                cin >> amount;
                for (auto& sender : accounts) {
                    if (sender.accountNumber == senderAccountNumber) {
                        for (auto& recipient : accounts) {
                            if (recipient.accountNumber == recipientAccountNumber) {
                                sender.transfer(amount, recipient);
                                // Save the updated accounts to file after each transfer
                                saveAccountsToFile(accounts, filename);
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            case 6: {
                saveAccountsToFile(accounts, filename);
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    return 0;
}