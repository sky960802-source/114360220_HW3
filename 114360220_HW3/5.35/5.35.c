#include <stdio.h>
#include <limits.h>

unsigned int fibonacci(unsigned int n) 
	{
        if (n == 0) 
		{
        	return 0; // F(0) = 0
    	}
    	if (n == 1) 
		{
        	return 1; // F(1) = 1
    	}

    	unsigned int previous = 0; // F(i-2)
    	unsigned int current = 1;  // F(i-1)
    	unsigned int next = 0;     // F(i)
    	
		// 從 i=2 開始，迭代計算至 F(n)
        for (unsigned int i = 2; i <= n; i++) 
		{
        next = previous + current;  
        previous = current;// 更新狀態
        current = next;
    	}
    return current;// 回傳最終結果 F(n)
	}

int main() 
	{
    unsigned int previous = 0;
    unsigned int current = 1;
    unsigned int next = 0;
    unsigned int n = 1;
    
    // 輸出標題和系統限制，強調數據類型約束
    printf("--- Non-Recursive Fibonacci using unsigned int ---\n");
    printf("Max value for unsigned int (UINT_MAX): %u\n\n", UINT_MAX);

    // 輸出 F(0) 和 F(1) 的初始值
    printf("F(%u) = %u\n", 0, previous);
    printf("F(%u) = %u\n", 1, current);

    while (1) 
	{
		// 核心溢位檢查：避免 F(i-1) + F(i-2) 超過 UINT_MAX
        // 檢查條件：UINT_MAX - previous < current
        if (UINT_MAX - previous < current) {
            printf("\n--- Overflow Detected ---\n");// 報告在溢位前能安全儲存的最大值
            printf("The largest Fibonacci number that can be safely stored (F(n)): \n");
            printf("F(%u) = %u\n", n, current);
            
            next = previous + current; // 執行溢位加法，印出錯誤的結果以示警
            printf("F(%u) causes overflow and returns (incorrectly): %u\n", n + 1, next);
            break;// 偵測到溢位，立即終止程式
        }

        n++;// 費波氏數列索引遞增
        next = previous + current;// 正常計算 F(n)
        printf("F(%u) = %u\n", n, next);

		// 滾動更新狀態變數
        previous = current;
        current = next;
    }
    
    return 0;
	}
