#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<int> absences = {10, 5, 25, 30, 15, 40};

    auto is_suspect = [](int minutes) {
        return minutes > 20;
    };

    int suspects_count = count_if(absences.begin(), absences.end(), is_suspect);

    int absence_suspects = accumulate(absences.begin(), absences.end(), 0, [is_suspect](int sum, int minutes) {
            return is_suspect(minutes) ? sum + minutes : sum;
        });

    cout << "Количество подозреваемых на списывание: " << suspects_count << endl;
    cout << "Суммарное время их отсутствия: " << absence_suspects << " минут" << endl;

    return 0;
}