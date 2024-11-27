#include <iostream>
#include <string>
#include <vector>
#include <limits>

class BankAccount {
    private:
        std::string name;
        double balance;
    public:
        BankAccount(std::string accountName, double initialDeposit) : name(accountName), balance(initialDeposit){}
        void deposit (double value) {
            if (value > 0) {
                balance += value;
                std::cout << "Deposit made succesfully!" << std::endl;
            } else {
                std::cout << "Error: cannot add 0 or negative numbers to account." << std::endl; 
            }
        }
        void withdraw (double value) {
            if (value <= balance) {
                balance -= value;
                std::cout << "Withdraw made succesfully!" << std::endl;
            } else {
                std::cout << "Error: Insuficient funds." << std::endl;
            }
        }
        void display () {
            std::cout << "Account: " << name << "\nBalance: $" << balance << std::endl;
        }
};

class Menu {
    public:
        void clearScreen() {
        #ifdef _WIN32
            system("cls"); // For Windows
        #else
            system("clear"); // For Linux and macOS
        #endif
    }

    void waitInput() {
        std::cin.ignore();
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

};


int main () {
    std::string name;
    double initialDeposit;
    
    std::cout << "Enter your name: ";
    getline(std::cin, name);
    std::cout << "Enter your initial deposit: ";
    std::cin >> initialDeposit;

    BankAccount account = BankAccount(name, initialDeposit);
    Menu menu = Menu();

    int choice;
    double amount;

    do
    {
        menu.clearScreen();
        std::cout << "\n1. Deposit" << std::endl;
        std::cout << "2. Withdraw" << std::endl;
        std::cout << "3. Display Account Info" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            account.display();
            break;
        case 4:
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
        }
        menu.waitInput();
    } while (choice != 4);
}