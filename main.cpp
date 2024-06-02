#include <iostream>
#include <vector>
#include "calc.h"
#include "input.h"
#include "output.h"

int main() {
    setlocale(LC_ALL, "RU");
    int n, k;
    std::vector<int> a;

    try {
        getInput(n, a, k);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    // Здесь можно использовать функцию calcing и другие, которые были включены в calc.h и output.h
    // Пример:
    // int total_teams = calcing(n, a, k);
    // std::cout << "Общее количество команд: " << total_teams << std::endl;

    return 0;
}
