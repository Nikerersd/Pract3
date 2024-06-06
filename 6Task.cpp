#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& nums) {
    for (auto i : nums) {
        os << i << " ";
    }
    return os;
}

int main() {
    vector<double> results = { 28.1, 27.5, 29.3, 26.8, 30.0, 27.0, 28.7, 29.8, 26.5, 30.5 };

    sort(results.begin(), results.end());

    auto fastslow = minmax_element(results.begin(), results.end());

    cout << "Отсортированные результаты заплывов (в секундах):" << endl;
    cout << results << endl;

    cout << "Самый быстрый пловец: " << *fastslow.first << " секунд\n";
    cout << "Самый медленный пловец: " << *fastslow.second << " секунд\n";

    return 0;
}
