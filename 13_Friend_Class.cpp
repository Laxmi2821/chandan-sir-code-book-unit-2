#include <iostream>

class Account {
private:
    double balance;

public:
    explicit Account(double amount)
        : balance(amount) {}

    friend class Auditor;
};

class Auditor {
public:
    void checkBalance(const Account& account) const {
        std::cout << "Account Balance: " << account.balance << '\n';
    }
};

int main() {
    Account account(5000);

    Auditor auditor;
    auditor.checkBalance(account);

    return 0;
}