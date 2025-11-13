#include <stdio.h>

int lcm(int a, int b) {
    int max = (a > b) ? a : b;  //從較大的開始找

    while (1) {
        if (max % a == 0 && max % b == 0) {
            return max;  //找到最小公倍數
        }
        max++;
    }
}

int main() {
    int x, y;
    printf("輸入兩個整數: ");
    scanf("%d %d", &x, &y);//接收輸入的單一字元

    printf("LCM = %d\n", lcm(x, y));//印出呼叫lcm函式後產生的結果 

    return 0;
}

