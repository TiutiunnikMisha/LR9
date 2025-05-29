#include "string_utils.h"
#include <sstream>
#include <iostream>
#include <fstream>

// Реалізація функції, яка замінює підрядок у рядку
std::string replaceSubstring(const char* input, size_t position, size_t length, const char* insert, size_t count) {
    std::string result;
    size_t index = 0;

    // Додаємо символи до вказаної позиції
    while (index < position && input[index] != '\0') {
        result += input[index];
        index++;
    }

    // Додаємо вказану кількість символів з нового рядка
    for (size_t j = 0; j < count && insert[j] != '\0'; ++j) {
        result += insert[j];
    }

    // Пропускаємо символи, що підлягають заміні
    index = position + length;

    // Додаємо решту рядка
    while (input[index] != '\0') {
        result += input[index];
        index++;
    }

    return result;
}

// Реалізація функції, яка підраховує кількість слів у рядку
int countWords(const std::string& text) {
    std::istringstream stream(text);
    std::string word;
    int count = 0;

    // Зчитування слів, розділених пробілами
    while (stream >> word) {
        count++;
    }

    return count;
}

// Реалізація функції меню для користувача
void showMenu() {
    std::string text;
    char buffer[256];

    while (true) {
        std::cout << "\n--- MENU ---" << std::endl;
        std::cout << "1. Replace substring (Task 20)" << std::endl;
        std::cout << "2. Count words in a line (Task 41)" << std::endl;
        std::cout << "3. Process input.txt and write to output.txt" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Your choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::cout << "\nEnter string: ";
            std::cin.getline(buffer, 256);

            std::string input(buffer);
            size_t position = 3, length = 4, count = 5;
            const char* insert = "EXTRA";

            // Стандартна реалізація з використанням методу string
            std::string stdVersion = input;
            stdVersion.replace(position, length, insert, count);

            // Користувацька реалізація
            std::string customVersion = replaceSubstring(buffer, position, length, insert, count);

            std::cout << "[std::string::replace] Result: " << stdVersion << std::endl;
            std::cout << "[custom function] Result: " << customVersion << std::endl;
            break;
        }
        case 2: {
            std::cout << "\nEnter Cyrillic string: ";
            std::getline(std::cin, text);
            int count = countWords(text);
            std::cout << "Word count: " << count << std::endl;
            break;
        }
        case 3: {
            std::ifstream inputFile("input.txt");
            std::ofstream outputFile("output.txt");

            if (!inputFile || !outputFile) {
                std::cout << "Unable to open files." << std::endl;
                break;
            }

            std::string line;
            while (std::getline(inputFile, line)) {
                int wordCount = countWords(line);
                outputFile << wordCount << std::endl;
            }

            std::cout << "Processing complete. Results saved to output.txt" << std::endl;
            break;
        }
        case 0:
            return;
        default:
            std::cout << "Unknown option, try again." << std::endl;
        }
    }
}
