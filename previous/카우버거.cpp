#include <bits/stdc++.h>
using namespace std;

int main() {
    int b, c, d;
    scanf("%d%d%d", &b, &c, &d);

    vector<int> burger(b), side(c), drink(d);
    int total_result = 0;

    for (int i = 0; i < b; i++) {
        scanf("%d", &burger[i]);
        total_result += burger[i];
    }
    for (int i = 0; i < c; i++) {
        scanf("%d", &side[i]);
        total_result += side[i];
    }
    for (int i = 0; i < d; i++) {
        scanf("%d", &drink[i]);
        total_result += drink[i];
    }

    sort(burger.begin(), burger.end(), greater<int>());
    sort(side.begin(), side.end(), greater<int>());
    sort(drink.begin(), drink.end(), greater<int>());

    int result = 0;
    int min_index = min({b, c, d});

    for (int i = 0; i < min_index; i++) {
        result += round((burger[i] + side[i] + drink[i]) * 0.9);
    }

    for (int i = min_index; i < burger.size(); i++) {
        result += burger[i];
    }
    for (int i = min_index; i < side.size(); i++) {
        result += side[i];
    }
    for (int i = min_index; i < drink.size(); i++) {
        result += drink[i];
    }

    printf("%d\n%d", total_result, result);
    return 0;
}