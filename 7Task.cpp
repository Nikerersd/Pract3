#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int calculateTotalCost(const vector<int>& cost) {
    return accumulate(cost.begin(), cost.end(), 0);
}

int main() {
    vector<int> transportation_costs = {500, 200, 300, 700};
    vector<int> accommodation_costs = {1200, 800, 1000, 1500};
    vector<int> food_costs = {300, 400, 200, 500};

    vector<int> total_costs;

    for (const auto& transportation : transportation_costs) {
        for (const auto& accommodation : accommodation_costs) {
            for (const auto& food : food_costs) {
                int total_cost = calculateTotalCost({transportation, accommodation, food});
                total_costs.push_back(total_cost);
            }
        }
    }

    sort(total_costs.begin(), total_costs.end());

    cout << "Три самых выгодных варианта по стоимости поездки:" << endl;
    for (size_t i = 0; i < 3 && i < total_costs.size(); ++i) {
        cout << total_costs[i] << endl;
    }

    return 0;
}