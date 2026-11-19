#include <iostream>
#include <fstream>
#include <string>

class Logger {
public:
    virtual ~Logger() {}
    virtual void write(const std::string& message) = 0;
};

class ConsoleLogger : public Logger {
public:
    void write(const std::string& message) override {
        std::cout << "[Console] " << message << '\n';
    }
};

class FileLogger : public Logger {
    std::ofstream outFile;
public:
    FileLogger(const std::string& filename) {
        outFile.open(filename, std::ios::app);
    }
    ~FileLogger() override {
        if (outFile.is_open()) {
            outFile.close();
        }
    }
    void write(const std::string& message) override {
        if (outFile.is_open()) {
            outFile << "[File] " << message << '\n';
        }
    }
};

int main() {
    Logger* logger = nullptr;
    int choice;

    std::cout << "Select logger (1 = Console, 2 = File): ";
    std::cin >> choice;

    // Switch implementation at runtime
    if (choice == 1) {
        logger = new ConsoleLogger();
    } else {
        logger = new FileLogger("app.log");
    }

    logger->write("System initialized successfully.");

    delete logger;
    return 0;
}