#include <iostream>

class Account {
protected:
    double balance;
public:
    Account(double initialBalance) : balance(initialBalance) {}
    virtual ~Account() {} // Virtual destructor for safe polymorphic deletion

    // Pure virtual function
    virtual double calculateInterest() const = 0;
};

class Savings : public Account {
    double interestRate = 0.04; // 4% rate
public:
    Savings(double initialBalance) : Account(initialBalance) {}
    double calculateInterest() const override {
        return balance * interestRate;
    }
};

class Current : public Account {
    double interestRate = 0.01; // 1% rate
public:
    Current(double initialBalance) : Account(initialBalance) {}
    double calculateInterest() const override {
        return balance * interestRate;
    }
};

int main() {
    const int SIZE = 2;
    Account* accounts[SIZE];

    accounts[0] = new Savings(1000.0);
    accounts[1] = new Current(2500.0);

    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Account " << i + 1 
                  << " Interest: $" << accounts[i]->calculateInterest() << '\n';
    }

    // Clean up memory
    for (int i = 0; i < SIZE; ++i) {
        delete accounts[i];
    }

    return 0;
}