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
        std::cerr << "������: " << e.what() << std::endl;
        return 1;
    }

    // ����� ����� ������������ ������� calcing � ������, ������� ���� �������� � calc.h � output.h
    // ������:
    // int total_teams = calcing(n, a, k);
    // std::cout << "����� ���������� ������: " << total_teams << std::endl;

    return 0;
}
