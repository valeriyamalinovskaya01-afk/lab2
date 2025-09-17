#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // Инициализация генератора случайных чисел
    srand(time(0));

    // Массив с именами файлов
    const char* filenames[] = {"file1.txt", "file2.txt", "file3.txt"};
    const int num_files = 3;
    const int num_numbers = 10;

    // Создание трех файлов
    for (int i = 0; i < num_files; i++) {
        ofstream file(filenames[i]);

        if (!file.is_open()) {
            cerr << "Ошибка: не удалось создать файл " << filenames[i] << endl;
            return 1;
        }

        // Генерация и запись 10 случайных чисел
        for (int j = 0; j < num_numbers; j++) {
            int random_number = rand() % 10 + 1; // Генерация чисел от 1 до 10
            file << random_number;

            // Добавление пробела, кроме последнего числа
            if (j < num_numbers - 1) {
                file << " ";
            }
        }

        file.close();
        cout << "Файл " << filenames[i] << " успешно создан" << endl;
    }

    cout << "Все файлы успешно созданы!" << endl;
    return 0;
}
