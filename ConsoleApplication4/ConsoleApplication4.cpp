#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    system("chcp 65001");
    char link[50];
    cout << "Введіть шлях до файлу: ";
    cin >> link;
    ifstream file(link);
    if (!file.is_open())
    {
        cout << "Помилка! Файл не вдалося відкрити." << endl;
    }
    char symbol;
    int open = 0;
    int close = 0;
    while (file.get(symbol))
    {
        if (symbol == '<')
        {
            open++;
        }
        if (symbol == '>')
        {
            close++;
            if (close > open)
            {
                cout << "HTML-файл невалідний!" << endl;
                cout << "Знайдено символ '>' без відповідного '<'." << endl;
                file.close();
            }
        }
    }
    file.close();
    cout << endl;
    cout << "Перевірка завершена." << endl;
    cout << "Кількість '<': " << open << endl;
    cout << "Кількість '>': " << close << endl;
    if (open == close)
    {
        cout << "Результат: HTML-файл валідний!" << endl;
    }
    else
    {
        cout << "Результат: HTML-файл невалідний!" << endl;
        cout << "Не всі відкриті теги мають закриття." << endl;
    }
}