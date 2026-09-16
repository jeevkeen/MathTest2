#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows

struct Task {
    int num_1;
    int num_2;
    char operation;
    double answer;

    Task();

    Task(int min, int max, char op = '\0');

    void print() const;

private:
    void calculate_answer();
};

class MathTest;


