#include <iostream>

class Base {
public:
    Base() { std::cout << "Base constructed\n"; }
    ~Base() { std::cout << "Base destroyed\n"; } // Missing 'virtual' causes leak!
};

class Derived : public Base {
    int* data;
public:
    Derived() {
        data = new int[100]; // Dynamically allocated memory
        std::cout << "Derived constructed (allocated memory)\n";
    }
    ~Derived() {
        delete[] data; // Never called when deleted via Base*
        std::cout << "Derived destroyed (freed memory)\n";
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr; // Undefined behavior / Memory leak!
    return 0;
}

class Base {
public:
    Base() { std::cout << "Base constructed\n"; }
    virtual ~Base() { std::cout << "Base destroyed\n"; } // Fixed!
};