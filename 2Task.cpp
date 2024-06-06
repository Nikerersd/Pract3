#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    double weight;
    double WeightLoss;
    double WeightGain;
};

int main() {
    vector<double> weights = {70.5, 80.0, 65.3, 90.2, 55.0};

    auto minmaxWeight = minmax_element(weights.begin(), weights.end());

    cout << "Самый худой человек весит: " << *minmaxWeight.first << " кг" << endl;
    cout << "Самый увесистый человек весит: " << *minmaxWeight.second << " кг" << endl;

    vector<Person> people;
    transform(weights.begin(), weights.end(), back_inserter(people), [](double weight) {
        return Person{weight, weight * 1.5, weight * 2.0};
    });

    for (Person person : people) {
        cout << "Человек весит: " << person.weight << " кг. ";
        cout << "Для похудения необходимо: "<< person.WeightLoss << " грамм белка в день. ";
        cout << "Для набора массы необходимо: "<< person.WeightGain << " грамм белка в день." << endl;
    }

    return 0;
}
