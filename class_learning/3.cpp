#include <stdio.h>
#include <chrono>

#define MAXN 100000

// 返回三个整数中的最大值
int Max3(int A, int B, int C) {
    return A > B ? (A > C ? A : C) : (B > C ? B : C);
}

// 分治法求解List[left]到List[right]的最大子列和
int DivideAndConquer(int List[], int left, int right) {
    // 存放左边最大子列和、右边最大子列和以及跨越左右边界的最大子列和
    int MaxLeftSum, MaxRightSum, MaxLeftBorderSum, MaxRightBorderSum;
    // 存放左右边界的子列和
    int LeftBorderSum, RightBorderSum;
    // 计算中间索引
    int center, i;

    // 基本情况：只有一个元素时直接返回该元素
    if (left == right) {
        if (List[left] > 0)  // 如果这个元素是正数，返回该元素
            return List[left];
        else
            return 0;  // 如果是负数，返回0（空子列和为0）
    }

    // 递归计算左边和右边的最大子列和
    center = (left + right) / 2;  // 计算中间点
    MaxLeftSum = DivideAndConquer(List, left, center);  // 递归左半部分
    MaxRightSum = DivideAndConquer(List, center + 1, right);  // 递归右半部分

    // 计算左边界最大子列和（即从中间向左扫描的最大子列和）
    MaxLeftBorderSum = 0;  // 初始化左边界子列和为0
    LeftBorderSum = 0;
    for (i = center; i >= left; i--) {  // 从中间向左扫描
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum)  // 更新左边界最大子列和
            MaxLeftBorderSum = LeftBorderSum;
    }

    // 计算右边界最大子列和（即从中间向右扫描的最大子列和）
    MaxRightBorderSum = 0;  // 初始化右边界子列和为0
    RightBorderSum = 0;
    for (i = center + 1; i <= right; i++) {  // 从中间向右扫描
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum)  // 更新右边界最大子列和
            MaxRightBorderSum = RightBorderSum;
    }

    // 返回左边、右边和跨越中间的最大子列和中的最大值
    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

// 调用分治算法的接口函数
int MaxSubseqSum3(int List[], int N) {
    // 从List[0]到List[N-1]递归求解
    return DivideAndConquer(List, 0, N - 1);
}

int main() {
    int List[] = { 4, -3, 5, -2, -1, 5, 6, -2 };
    int N = sizeof(List) / sizeof(List[0]);
    int MaxSum;
    
    // 记录开始时间
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < MAXN; i++) {
        // 调用最大子列和函数
         MaxSum = MaxSubseqSum3(List, N);
    }


    // 记录结束时间
    auto end = std::chrono::high_resolution_clock::now();

    // 计算运行时间
    std::chrono::duration<double> elapsed = end - start;

    // 打印结果和运行时间
    printf("最大子列和: %d\n", MaxSum);
    printf("运行时间: %f 秒\n", elapsed.count());

    return 0;
}