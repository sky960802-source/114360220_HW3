#include <stdio.h>
#include <math.h> // 用於計算總移動次數


void towersOfHanoi(int n, char source, char auxiliary, char destination) 
{
    // 1. 終止條件 :只有一個盤子時，直接從源柱移到目標柱。
    if (n == 1) 
	{
        printf("將盤子 1 從 %c 柱 移到 %c 柱\n", source, destination);
        return;
    }

    // 2. 遞迴步驟 1: 將 n-1個盤子從起始柱移到輔助柱 
    //    此時將目標柱作為臨時輔助。
    towersOfHanoi(n - 1, source, destination, auxiliary);

    // 3. 移動最大的盤子(n)從起始柱移到目標柱。
    printf("將盤子 %d 從 %c 柱 移到 %c 柱\n", n, source, destination);

    // 4. 遞迴步驟 2:將 n-1個盤子從輔助柱移到目標柱
    //    此時將起始柱作為臨時輔助。
    towersOfHanoi(n - 1, auxiliary, source, destination);
}

// 主函數用於演示
int main() 
{
    int num_disks;
    
    printf("--- 漢諾塔問題求解器 ---\n");
    printf("請輸入盤子的數量 (例如，3): ");
    
    // 獲取使用者輸入
    if (scanf("%d", &num_disks) != 1 || num_disks < 1) 
	{
        printf("輸入無效。請輸入一個正整數。\n");
        return 1;
    }

    // 64 盤子的處理
    if (num_disks == 64) 
	{
        // 計算總移動次數: 2^64 - 1
        double total_moves = pow(2.0, 64.0) - 1;
        printf("完成此任務需要 %.0f 次移動。\n", total_moves);
        printf("如果每秒移動一個盤子，大約需要 5850億年才能完成。\n");
        // 對於 64 個盤子，我們不印出具體的移動步驟
        return 0;
    }

    // 求解較小的盤子數
    printf("\n--- %d 個盤子的移動步驟 ---\n", num_disks);
    // 初始呼叫: 從 'A' 柱移動到 'C' 柱，使用 'B' 柱作為輔助。
    towersOfHanoi(num_disks, 'A', 'B', 'C');
    
    // 計算並顯示總移動次數
    // 對於n<=63的情況，unsigned long long變數不會溢位 
    unsigned long long total_moves_calc = (unsigned long long)pow(2.0, (double)num_disks) - 1;
    printf("\n總共需要的移動次數: %llu\n", total_moves_calc);

    return 0;
}
