#ifndef INPUT_H
#define INPUT_H

#include <vector>

/// <summary>
/// Функция для ввода количества институтов, количества команд и количества аудиторий.
/// </summary>
/// <param name="n">Ссылка на переменную типа int, в которую будет сохранено количество институтов</param>
/// <param name="a">Ссылка на вектор типа int, в который будут сохранены количества команд</param>
/// <param name="k">Ссылка на переменную типа int, в которую будет сохранено количество аудиторий</param>
void getInput(int& n, std::vector<int>& a, int& k);

#endif // INPUT_H
