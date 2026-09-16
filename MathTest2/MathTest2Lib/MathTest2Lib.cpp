// MathTest2Lib.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include <iostream>
#include <random>
#include <stdexcept>

Task::Task(int min, int max, char op) {

    if (op != '+' && op != '-' && op != '*' && op != '/') {
        throw std::invalid_argument("Ошибка: операция не задана или указан неверный знак!");
    }

    operation = op;

    if (min > max) {
        int temp = min;
        min = max;
        max = temp;
    }

    //генератор случайных чисел
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> num_dist(min, max);

    num_1 = num_dist(gen);
    num_2 = num_dist(gen);

    if (operation == '/' && num_2 == 0) {
        while (num_2 == 0) {
            num_2 = num_dist(gen);
        }
    }

    calculate_answer();
}


Task::Task() : Task(1, 100, '+') {
}

// Расчет правильного ответа
void Task::calculate_answer() {
    switch (operation) {
    case '+':
        answer = num_1 + num_2;
        break;
    case '-':
        answer = num_1 - num_2;
        break;
    case '*':
        answer = num_1 * num_2;
        break;
    case '/':
        if (num_2 == 0) {
            num_2 = 1;
        }
        answer = (double)num_1 / num_2;
        break;
    default:
        throw std::invalid_argument("Неизвестная операция при вычислении ответа!");
    }
}


void Task::calculate_answer() {
    switch (operation) {
    case '+':
        answer = num_1 + num_2;
        break;
    case '-':
        answer = num_1 - num_2;
        break;
    case '*':
        answer = num_1 * num_2;
        break;
    case '/':
        if (num_2 == 0) {
            num_2 = 1;
        }
        answer = (double)num_1 / num_2;
        break;
    default:
        operation = '+';
        answer = num_1 + num_2;
        break;
    }
}

void Task::print() const {
    std::cout << num_1 << " " << operation << " " << num_2
        << " = ? (Ответ: " << answer << ")\n";
}

