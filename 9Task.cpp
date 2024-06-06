#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int calculateArea(int width, int length) {
    return width * length;
}

int main() {
    map<int, pair<int, int>> plots = {{1, {10, 20}}, {2, {15, 25}}, {3, {8, 12}}, {4, {30, 40}}};

    vector<int> areas;

    transform(plots.begin(), plots.end(), back_inserter(areas), [](const pair<int, pair<int, int>>& plot) {
        return calculateArea(plot.second.first, plot.second.second);
    });

    auto minAreaIt = min_element(areas.begin(), areas.end());

    if (minAreaIt != areas.end()) {
        int minAreaIndex = distance(areas.begin(), minAreaIt);
        int minPlotNumber = next(plots.begin(), minAreaIndex)->first;
        int minCost = *minAreaIt / 10 * 7500;

        cout << "Наименьший участок: " << minPlotNumber << endl;
        cout << "Площадь: " << *minAreaIt << " м^2" << endl;
        cout << "Затраты на засадку газона: " << minCost << " рублей" << endl;
    }

    return 0;
}