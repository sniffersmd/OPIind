#include "pch.h"
#include <iostream>
#include <vector>
#include "input.h"


    /// <summary>
    /// Функция для ввода количества институтов, количества команд и количества аудиторий.
    /// </summary>
    /// <param name="n">Ссылка на переменную типа int, в которую будет сохранено количество институтов</param>
    /// <param name="a">Ссылка на вектор типа int, в который будут сохранены количества команд</param>
    /// <param name="k">Ссылка на переменную типа int, в которую будет сохранено количество аудиторий</param>
void getInput(int& n, std::vector<int>& a, int& k) {
    double input;

    // Ввод количества институтов
    std::cout << "Введите количество институтов: ";
    std::cin >> input;
    if (std::cin.fail() || input < 1 || input > 1000 || input != static_cast<int>(input)) {
        std::cout << "Некорректный ввод. Введите целое число от 1 до 1000.\n";
        throw std::invalid_argument("Неверное количество институтов");
    }
    n = static_cast<int>(input);

    // Ввод количества команд для каждого института
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Введите количество команд в " << i + 1 << " институте: ";
        std::cin >> input;
        if (std::cin.fail() || input < 1 || input > 1000 || input != static_cast<int>(input)) {
            std::cout << "Некорректный ввод. Введите целое число от 1 до 1000.\n";
            throw std::invalid_argument("Неверное количество команд");
        }
        a[i] = static_cast<int>(input);
    }

    // Ввод количества аудиторий
    std::cout << "Введите количество доступных аудиторий: ";
    std::cin >> input;
    if (std::cin.fail() || input < 1 || input > 1000 || input != static_cast<int>(input)) {
        std::cout << "Некорректный ввод. Введите целое число от 1 до 1000.\n";
        throw std::invalid_argument("Неверное количество аудиторий");
    }
    k = static_cast<int>(input);
}