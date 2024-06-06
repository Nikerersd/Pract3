#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

void sortLives(vector<pair<int, int>>& sortedPlayers) {
    sort(sortedPlayers.begin(), sortedPlayers.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
}

void printLives(vector<pair<int, int>>& sortedPlayers) {
    for (pair<int, int> player : sortedPlayers) {
        cout << "Игрок " << player.first << ": " << player.second << " жизней" << endl;
    }
}

int main() {
    map<int, int> players = {{1, 10}, {2, 8}, {3, 6}, {4, 12}};
    int currentPlayer = 1;
    int totalPlayers = players.size();

    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<> dis(0, 6);

    while (players.size() > 1) {
        vector<pair<int, int>> sortedPlayers(players.begin(), players.end());
        sortLives(sortedPlayers);
        printLives(sortedPlayers);
        cout << endl;
        int damage = dis(gen);
        cout << "Игроку " << currentPlayer << " выпало урона: " << damage << endl;

        auto killIt = find_if(players.begin(), players.end(), [damage](const auto& player) {
            return player.second <= damage && player.second > 0;
        });

        if (killIt != players.end() && killIt->first != currentPlayer) {
            cout << "Игрок " << currentPlayer << " нанёс " << damage << " урона игроку " << killIt->first << endl;
            killIt->second -= damage;
            if (killIt->second <= 0) {
                cout << "Игрок " << killIt->first << " выбыл" << endl;
                players.erase(killIt);
            }
        } 
        else {
            auto maxIt = max_element(players.begin(), players.end(), [](const auto& a, const auto& b) {
                return a.second < b.second;
            });

            if (maxIt->first != currentPlayer) {
                cout << "Игрок " << currentPlayer << " нанёс " << damage << " урона игроку " << maxIt->first << endl;
                maxIt->second -= damage;
                if (maxIt->second <= 0) {
                    cout << "Игрок " << maxIt->first << " выбыл" << endl;
                    players.erase(maxIt);
                }
            }
        }

        do {
            currentPlayer = (currentPlayer % totalPlayers) + 1;
        } while (players.find(currentPlayer) == players.end());
    }

    cout << "Победил игрок " << players.begin()->first << " с остатком в " << players.begin()->second << " здоровья!" << endl;

    return 0;
}
