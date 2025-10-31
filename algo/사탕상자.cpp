#include<bits/stdc++.h>
using namespace std;
#define bottom 1048576
vector<long long> tree(bottom * 2, 0);

void func(int candy, int num) {
    int leaf = bottom + candy - 1;

    tree[leaf] += num;

    while(leaf > 1) {
        leaf /= 2;
        tree[leaf] += num;
    }
}

void find_candy(int k){
    int node = 1;

    while(node < bottom) { // 바닥까지 내려가서 캔디 어디있는지 구하기
        if(tree[node*2] >= k) {
            node *= 2;
        }
        else { // 왼쪽 서브트리에 없으면 오른쪽 서브트리로 이동
            k -= tree[node*2]; // 대신에 왼쪽 서브트리의 부모 노드만큼 빼줘야함
            node = node*2 + 1; 
        }
    }

    int candy = node - bottom + 1; // 구한 캔디 인덱스


    while(node > 1) { // 노드 올라가면서 하나씩 빼주기
        tree[node] -= 1;
        node /= 2;
    }

    printf("%d\n", candy);
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i{};i<n;i++){
        int first;
        scanf("%d", &first);
        if (first == 2) {
            int candy, m;
            scanf("%d %d", &candy, &m);
            func(candy, m); // 맨 밑바닥 부터 캔디 채우기(루트까지)
        }

        else if(first == 1) { // 캔디 꺼내기
            int second;
            scanf("%d", &second);
            find_candy(second);
        }
    }
}