#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    map<int, double> temperatures = {{8, 21.5}, {10, 22.3}, {12, 21.8}, {14, 23.0}, {16, 20.5},  {18, 22.2}};

    double necessary_temperature = 22.0;
    
    auto it = find_if(temperatures.begin(), temperatures.end(), [necessary_temperature](const pair<int, double>& pair) {
        return pair.second >= necessary_temperature; 
    });

    if (it != temperatures.end()) {
        cout << "Оптимальное время для полива: " << it->first << " часов, температура " << it->second << " градусов Цельсия." << endl;
    } 
    else {
        cout << "Не удалось найти время с температурой >= " << necessary_temperature << " градусов Цельсия." << endl;
    }

    return 0;
}