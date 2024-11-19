#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


void toRoman(int num) {
    vector<pair<int, string>> romanNumerals = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
    {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string resultNum;
    for (auto pair : romanNumerals) {
        while (num >= pair.first) {
            resultNum += pair.second;
            num -= pair.first;
        }
    }
    cout << "число в римской системе: " << resultNum;
}


void toArabic(string num) {
    map<char, int> romanNumerals = {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int resultNum = 0;
    int prevValue = 0;

    for (int i = num.size() - 1; i >= 0; --i) {
        int currentValue = romanNumerals[num[i]];
        if (currentValue < prevValue) {
            resultNum -= currentValue;
        }
        else {
            resultNum += currentValue;
        }
        prevValue = currentValue;
    }
    cout << "число в арабской системе: " << resultNum;
}



int main() {
    int var;
    setlocale(LC_ALL, "Russian");
    cout << "1: От арабской к римской" << endl << "2: От римской к арабской" << endl << "Выберите вариант: ";
    cin >> var;
    cout << "range: 1-3999" << endl;
    if (var == 1) {
        int num;
        cout << "Введите число: ";
        cin >> num;
        toRoman(num);
    }
    else {
        string num;
        cout << "Введите число: ";
        cin >> num;
        toArabic(num);
    }
}