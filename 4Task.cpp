#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<string> menu = { "Салат с огурцами", "Суп с фасолью", "Паста с томатами", "Жареные королевские креветки с чили и мёдом",
        "Фаршированный перец", "Говядина с грибами", "Салат с креветками", "Чесночные креветки"
    };

    menu.erase(remove_if(menu.begin(), menu.end(), [](const string& dish) {
        return dish.find("креветк") != string::npos;
    }), menu.end());

    cout << "Меню после удаления блюд, которые не нравятся гостю:" << endl;
    for (const auto& dish : menu) {
        cout << "- " << dish << endl;
    }

    return 0;
}