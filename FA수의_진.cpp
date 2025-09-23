#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int curr_time{};
    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        int cycle = c + d;
        int wait_time{};
        int through_over_pass{b + curr_time};
        int curr_cycle = curr_time % cycle;
        if (curr_cycle >= c)
            wait_time = cycle - curr_cycle;

        int through_over_road{wait_time + curr_time + a};

        curr_time = min(through_over_pass, through_over_road);
    }
    printf("%d", curr_time);
}