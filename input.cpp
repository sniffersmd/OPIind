#include "pch.h"
#include <iostream>
#include <vector>
#include "input.h"


    /// <summary>
    /// ������� ��� ����� ���������� ����������, ���������� ������ � ���������� ���������.
    /// </summary>
    /// <param name="n">������ �� ���������� ���� int, � ������� ����� ��������� ���������� ����������</param>
    /// <param name="a">������ �� ������ ���� int, � ������� ����� ��������� ���������� ������</param>
    /// <param name="k">������ �� ���������� ���� int, � ������� ����� ��������� ���������� ���������</param>
void getInput(int& n, std::vector<int>& a, int& k) {
    double input;

    // ���� ���������� ����������
    std::cout << "������� ���������� ����������: ";
    std::cin >> input;
    if (std::cin.fail() || input < 1 || input > 1000 || input != static_cast<int>(input)) {
        std::cout << "������������ ����. ������� ����� ����� �� 1 �� 1000.\n";
        throw std::invalid_argument("�������� ���������� ����������");
    }
    n = static_cast<int>(input);

    // ���� ���������� ������ ��� ������� ���������
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "������� ���������� ������ � " << i + 1 << " ���������: ";
        std::cin >> input;
        if (std::cin.fail() || input < 1 || input > 1000 || input != static_cast<int>(input)) {
            std::cout << "������������ ����. ������� ����� ����� �� 1 �� 1000.\n";
            throw std::invalid_argument("�������� ���������� ������");
        }
        a[i] = static_cast<int>(input);
    }

    // ���� ���������� ���������
    std::cout << "������� ���������� ��������� ���������: ";
    std::cin >> input;
    if (std::cin.fail() || input < 1 || input > 1000 || input != static_cast<int>(input)) {
        std::cout << "������������ ����. ������� ����� ����� �� 1 �� 1000.\n";
        throw std::invalid_argument("�������� ���������� ���������");
    }
    k = static_cast<int>(input);
}