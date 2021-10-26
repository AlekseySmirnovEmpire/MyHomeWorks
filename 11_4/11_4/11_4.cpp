#include <iostream>
#include <string>

/* Вы продолжаете писать калькулятор, работающий над вещественными числами повышенной точности. Вы уже научились
 * проверять корректность записи вещественных чисел в виде строк, и теперь перед вами новая цель — научиться сравнивать
 * такие вещественные числа.

    Пользователь вводит две строки, задающие вещественные числа, в том же формате, как было описано в задаче «Длинное
    вещественное число». Программа должна проверить корректность ввода (для этого можно переиспользовать код, написанный
    в задаче «Длинное вещественное число»), после чего вывести слово Less, если первое число строго меньше второго;
    слово More, если первое число строго больше второго; и слово Equal, если введённые числа равны. */

bool isCorrectNumbers(std::string text) {
    int pointCounter = 0;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] < '0' || text[i] > '9') {
            if (text[i] == '-' && i != 0) {
                return false;
            }
            else if (text[i] == '.' && pointCounter != 1) {
                pointCounter++;
            }
            else if (text.length() == 2 && text[0] == '-' && text[1] == '.') {
                return false;
            }
            else if (text[0] == '-') {
            }
            else return false;
        }
    }
    return true;
}

bool isNumberPositive(std::string text) {
    if (text[0] == '-') return false;
    else return true;
}

int fractionalNumber(std::string text) {
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '.') return i;
    }
    return 0;
}

std::string numberCompression(std::string text1, std::string text2) {
    int maxLength;

    if (text1.length() > text2.length()) maxLength = text1.length();
    else maxLength = text2.length();

    if ((isNumberPositive(text1) && isNumberPositive(text2)) || (!isNumberPositive(text1) && !isNumberPositive(text2))) {
        if (fractionalNumber(text1) == fractionalNumber(text2)) {
            if (fractionalNumber(text1) == 0) {
                for (int i = 0; i < maxLength; i++) {
                    if (text1[i] > text2[i]) return "More";
                    else if (text1[i] < text2[i]) return "Less";
                }
                return "Equal";
            }
            else {
                for (int i = 0; i < fractionalNumber(text1); i++) {
                    if (text1[i] > text2[i]) return "More";
                    else if (text1[i] < text2[i]) return "Less";
                }
                for (int i = fractionalNumber(text1) + 1; i < maxLength; i++) {
                    if (text1[i] > text2[i]) return "More";
                    else if (text1[i] < text2[i]) return "Less";
                }
                return "Equal";
            }
        }
        else if (fractionalNumber(text1) > fractionalNumber(text2)) return "More";
        else return "Less";
    }
    else if (isNumberPositive(text1) && !isNumberPositive(text2)) return "More";
    else return "Less";
}

int main() {
    std::string firstNumber;
    std::string secondNumber;
    std::cout << "Input your numbers (x y): ";
    std::cin >> firstNumber >> secondNumber;

    while (!(isCorrectNumbers(firstNumber) || isCorrectNumbers(secondNumber))) {
        std::cout << "Wrong input. Try again.\n";
        std::cout << "Input your number (x y): ";
        std::cin >> firstNumber >> secondNumber;
    }
    std::cout << numberCompression(firstNumber, secondNumber) << std::endl;
}