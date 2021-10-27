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
                continue;
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
    return -1;
}

std::string correctNumber(std::string text) {
    std::string output = "";

    int n;

    if (isNumberPositive(text) && fractionalNumber(text) != 0) n = 0;
    else {
        n = 1;
        output += text[0];
    }

    for (int i = n; i < text.length(); i++) {
        if (text[n] == '0') {
            bool stop = false;
            if (text[i] == '0' && text[i + 1] != '.' && !stop) continue;
            else {
                stop = true;
                output += text[i];
            }
        }
        else {
            return text;
        }
    }

    return output;
}

std::string numberCompression(std::string text1, std::string text2) {

    text1 = correctNumber(text1);
    text2 = correctNumber(text2);

    //Надо добавить функцию, которая бы считывала остаток, если у числа одного нету остатка, а у другого есть, то их надо уровнять по длине и докинуть сверху остаток

    if (fractionalNumber(text1) == -1 && fractionalNumber(text2) != -1) {
        text1 += '.';
    }
    else if (fractionalNumber(text2) == -1 && fractionalNumber(text2) != -1) {
        text2 += '.';
    }

    if (text1.length() < text2.length()) {
        for (int i = 0; i < text2.length() - text1.length(); i++) text1 += '0';
    }
    else if (text2.length() < text1.length()) {
        for (int i = 0; i < text1.length() - text2.length(); i++) text2 += '0';
    }

    if ((isNumberPositive(text1) && isNumberPositive(text2)) || (!isNumberPositive(text1) && !isNumberPositive(text2))) {
        if (fractionalNumber(text1) == fractionalNumber(text2)) {
            if (fractionalNumber(text1) == -1) {
                for (int i = 0; i < text1.length(); i++) {
                    if ((text1[i] > text2[i]) && isNumberPositive(text1)) return "More";
                    else if ((text1[i] < text2[i]) && isNumberPositive(text1)) return "Less";
                    else if ((text1[i] > text2[i]) && !isNumberPositive(text1)) return "Less";
                    else if ((text1[i] < text2[i]) && !isNumberPositive(text1)) return "More";
                }
                return "Equal";
            }
            else {
                for (int i = 0; i < fractionalNumber(text1); i++) {
                    if ((text1[i] > text2[i]) && isNumberPositive(text1)) return "More";
                    else if ((text1[i] < text2[i]) && isNumberPositive(text1)) return "Less";
                    else if ((text1[i] > text2[i]) && !isNumberPositive(text1)) return "Less";
                    else if ((text1[i] < text2[i]) && !isNumberPositive(text1)) return "More";
                }
                for (int i = fractionalNumber(text1) + 1; i < text1.length(); i++) {
                    if ((text1[i] > text2[i]) && isNumberPositive(text1)) return "More";
                    else if ((text1[i] < text2[i]) && isNumberPositive(text1)) return "Less";
                    else if ((text1[i] > text2[i]) && !isNumberPositive(text1)) return "Less";
                    else if ((text1[i] < text2[i]) && !isNumberPositive(text1)) return "More";
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