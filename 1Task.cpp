#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> Magic = {"Fire", "Water", "Earth", "Air", "Fire", "Fire", "Water", "Air", "Air", "Air", "Air"};
    cout << "Магов со стихией огня: " << count(Magic.begin(), Magic.end(), "Fire") << endl;
    cout << "Магов со стихией воды: " << count(Magic.begin(), Magic.end(), "Water") << endl;
    cout << "Магов со стихией земли: " << count(Magic.begin(), Magic.end(), "Earth") << endl;
    cout << "Магов со стихией воздуха: " << count(Magic.begin(), Magic.end(), "Air") << endl;
    return 0;
}