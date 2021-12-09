# CMakeList.txt: проект CMake для 25_1_1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("Surgion_Simuliator" VERSION 1.1)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (25_1_1 "main.cpp" "Commands.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
