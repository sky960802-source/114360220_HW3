#include<stdio.h>

//函式change用於單一字元的字母大小寫切換。
char change(char n)
	{
		if (isupper(n)) //檢查是否為大寫字母
		{
    	    return tolower(n);//若為大寫，則轉換為對應的小寫字母
    	} 
		else if (islower(n))  //檢查是否為小寫字母
		{
        	return toupper(n);//若為小寫，則轉換為對應的大寫字母
    	}
		else
		{
        	return n;// 若輸入不為字母，直接回傳原始字元
		}
	}

int main()
{
	char a;
	printf("輸入英文字母: ");
	scanf("%c",&a); //接收輸入的單一字元
	printf("%c",change(a));//呼叫change函式進行轉換
  }  
