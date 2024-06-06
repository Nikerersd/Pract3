#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int planned_profit = 450;

    map<int, pair<int, int>> data = {{1, {500, 50}}, {2, {400, 60}}, {3, {700, 250}}, {4, {300, 100}}, {5, {450, 50}}};

    vector<pair<int, int>> results;

    for (const auto& days : data) {
        int day = days.first;
        int income = days.second.first;
        int expenses = days.second.second;
        int profit = income - expenses;

        if (profit < planned_profit) {
            results.push_back({day, planned_profit - profit});
        }
    }

    sort(results.begin(), results.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    for (pair<int, int> result : results) {
        cout << "День: " << result.first << ", Прибыль меньше плановой на: " << result.second << endl;
    }

    return 0;
}