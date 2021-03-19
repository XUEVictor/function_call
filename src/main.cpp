#include <iostream>
// call by address
void swap_CBA(int *a, int *b)
{
    printf("In funtion Value_1_Addr = %p , Value_2_Addr = %p \n", a, b);

    int temp = *b;
    *b = *a;
    *a = temp;
}
void swap_CBF(int &a, int &b)
{
    printf("In funtion Value_1_Addr = %p , Value_2_Addr = %p \n", &a, &b);
    int temp = b;
    b = a;
    a = temp;
}

std::pair<int, int> swap_CBV(int a, int b)
{
    printf("In funtion Value_1_Addr = %p , Value_2_Addr = %p \n", &a, &b);

    int temp = b;
    b = a;
    a = temp;
    return std::make_pair(a, b);
}

void callbyAddress()
{
    printf("----------callbyAddress-----------------\n");
    int value_1 = 10;
    int value_2 = 20;
    printf("Value_1_Addr = %p , Value_2_Addr = %p \n", &value_1, &value_2);
    printf("Input : %d \t %d \n", value_1, value_2);
    swap_CBA(&value_1, &value_2);
    printf("Output : %d \t %d \n", value_1, value_2);

    printf("Function 內參數會與外部給的參數的地址一至\n");
    printf("因此外部與內部變數都是完全相同的\n");
    printf("當內部變數被修改時，外部的會一起變\n");
    printf("----------callbyAddress end -----------------\n");
}

void callbyReference()
{
    printf("----------callbyReference-----------------\n");
    int value_1 = 10;
    int value_2 = 20;
    printf("Value_1_Addr = %p , Value_2_Addr = %p \n", &value_1, &value_2);
    printf("Input : %d \t %d \n", value_1, value_2);
    swap_CBF(value_1, value_2);
    printf("Output : %d \t %d \n", value_1, value_2);
    printf("與call by address 一樣，改相同地址的值，只是更簡潔而已\n");
    printf("個人見解 ： 當外部傳入內部時，內部是直接取外部的值的地址\n");
    printf("----------callbyReference end-----------------\n");
}

void callbyValue()
{
    printf("----------callbyValue-----------------\n");
    int value_1 = 10;
    int value_2 = 20;
    printf("Value_1_Addr = %p , Value_2_Addr = %p \n", &value_1, &value_2);
    printf("Input : %d \t %d \n", value_1, value_2);
    std::pair<int, int> result = swap_CBV(value_1, value_2);
    printf("Output : %d \t %d \n", result.first, result.second);
    printf("這邊會發現外部地址與內部地址不一樣，因此裡面修改，是對外部不影響的\n");
    printf("內部運算完成後，需要回傳或者使用call by addr or call by ref 方打把資料丟回外部\n");
    printf("----------callbyValue end-----------------\n");
}

// excute swap function
//input 10 ,20
// output 20,10
int main()
{
    callbyValue();
}