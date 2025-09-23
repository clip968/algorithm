#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    vector<int> v(1002, 0);
    for (int i{}; i < n; ++i)
    {
        int k;
        scanf("%d", &k);
        for (int j{}; j < k; ++j)
        {
            int s, e;
            scanf("%d %d", &s, &e);
            for (int l{s}; l < e; ++l)
            {
                v[l]++;
            }
        }
    }

    if (t == 0)
    {
        printf("0 0\n");
        return 0;
    }

    long long cnt_time{};
    for (int i{}; i < t; ++i)
    {
        cnt_time += v[i];
    }

    long long max_time{cnt_time};
    int start_time{};
    for (int i{1}; i <= 1001 - t; ++i)
    {
        cnt_time = cnt_time - v[i - 1] + v[i + t - 1];
        if (max_time < cnt_time)
        {
            max_time = cnt_time;
            start_time = i;
        }
    }

    printf("%d %d\n", start_time, start_time + t);
}