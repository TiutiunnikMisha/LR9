#pragma once
#include <string>
#include <vector>

// Оголошення функції, яка замінює підрядок у рядку
std::string replaceSubstring(const char* input, size_t position, size_t length, const char* insert, size_t count);

// Оголошення функції, яка підраховує кількість слів у рядку
int countWords(const std::string& text);

// Оголошення функції меню
void showMenu();
