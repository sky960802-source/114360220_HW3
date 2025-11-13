#include <stdio.h>

//函式：power
// 目的：使用遞迴計算 base^exponent。
double power(double base, int exponent) 
	{

	// 遞迴的基底條件 (Base Case): 當 exponent 減到 1 時終止。
    // x^1 = x
    if (exponent == 1) 
	{
        return base;
    }
	
    return base * power(base, exponent - 1);// 每次呼叫都會將 exponent 減 1，直到達到基底條件。
	}

int main() 
{
    double base;
    int exponent;

    printf("Enter the base number: ");

	// 輸入驗證：確保成功讀取 double 類型的base。
    if (scanf("%lf", &base) != 1) 
	{
        printf("base輸入無效\n");
        return 1; // 結束程式，回傳錯誤碼
    }

    printf("Enter the exponent(an integer >= 1): ");

	// 輸入驗證：確保成功讀取 int 類型exponent。
    if (scanf("%d", &exponent) != 1) 
	{
        printf("exponent輸入無效\n");
        return 1; 
    }
    
	//檢查指數是否符合函式 power 的前提條件（>= 1）。
    if (exponent < 1) 
	{
        printf("指數必須大於或等於1\n");
        return 1;
    }

    double result = power(base, exponent);// 呼叫遞迴函式計算結果
	// 輸出結果，格式化為小數點後兩位
    printf("%.2lf的%d 次方是: %.2lf\n", base, exponent, result);
    
    return 0;
}
