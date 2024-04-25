// lab8.2_Петрушев.cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

int n;
cout << "Введіть кількість елементів масиву : ";
cin >> n;

double* arr = new double[n];

cout << "Введіть елементи масиву: ";
for (int i = 0; i < n; i++) cin >> arr[i];

double max_neg = arr[0] < 0 ? arr[0] : 0;
int max_neg_index = max_neg < 0 ? 0 : -1;
for (int i = 1; i < n; i++) {
    if (arr[i] < 0 && arr[i] > max_neg) {
        max_neg = arr[i];
        max_neg_index = i;
    }
}

if (max_neg_index == -1) {
    cout << "У масиві немає від'ємних елементів" << endl;
}
else {
    cout << "Максимальний з від'ємних елементів: " << max_neg << ", index: " << max_neg_index + 1 << endl;
}

int max_abs_index = 0;
for (int i = 1; i < n; i++) {
    if (fabs(arr[i]) > fabs(arr[max_abs_index])) max_abs_index = i;
}

double product = 1;
for (int i = max_abs_index + 1; i < n; i++) product *= arr[i];
cout <<"Добуток елементів масиву, розташованих після максимального за модулем елемента : " << product << endl;

return 0;
}