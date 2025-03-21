#include<bits/stdc++.h>
using namespace std;

int calculate(int x){
    int full_week = x / 7;
    int extra_day = x % 7;
    int total_weekend = full_week * 2 + (extra_day > 5 ? extra_day - 5 : 0);
    return total_weekend;
}

int main(){
    int n; scanf("%d", &n);
    int dead_line, time;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i{};i<n;++i){
        scanf("%d %d", &dead_line, &time);
        pq.push({dead_line, time});
    }

    int day_sum{};
    int answer{};

    while(!pq.empty()){
        int curr_dead_line = pq.top().first;
        int curr_need_times = pq.top().second;
        pq.pop();

        day_sum += curr_need_times;
        int weekend = calculate(curr_dead_line);
        int weekday = curr_dead_line - weekend;
        int total_capacity = weekday * 2 + weekend;

        if(total_capacity < day_sum) {
            printf("-1");
            return 0;
        }

        int overtime = max(0, day_sum - weekday);
        answer = max(overtime, answer);
    }
    printf("%d", answer); 

    // printf("%d %d",day_max+temp, time_sum);
}
// #include <bits/stdc++.h>
// using namespace std;

// int calcWeekend(int d) {
//     int fullWeeks = d / 7;
//     int extraDays = d % 7;
//     int extraWeekend = (extraDays > 5 ? extraDays - 5 : 0);
//     return fullWeeks * 2 + extraWeekend;
// }

// int main(){
//     int n;
//     scanf("%d", &n);
    
//     vector<pair<int,int>> tasks(n);
//     for(int i = 0; i < n; i++){
//         int deadline, requiredTime;
//         scanf("%d %d", &deadline, &requiredTime);
//         tasks[i] = {deadline, requiredTime};
//     }
    
//     sort(tasks.begin(), tasks.end());
    
//     int cumulativeTime = 0;
//     int minOvertime = 0;
    
//     for(auto &task : tasks){
//         int d = task.first;
//         int req = task.second;
//         cumulativeTime += req;
        
//         int weekendDays = calcWeekend(d);
//         int weekdays = d - weekendDays;
//         int totalCapacity = weekdays * 2 + weekendDays;
        
//         if(cumulativeTime > totalCapacity) {
//             printf("-1");
//             return 0;
//         }
        
//         int overtimeNeeded = max(0, cumulativeTime - weekdays);
//         minOvertime = max(minOvertime, overtimeNeeded);
//     }
    
//     printf("%d", minOvertime);
//     return 0;
// }
