#include <stdio.h>
#include <limits.h>
#include "safeint.h"

SafeResult safeAdd(int num1, int num2){
    SafeResult result;
    result.value = num1 + num2;
    if (num2 >= 0 && num1 > INT_MAX - num2)
        result.errorFlag = 1;
    else if (num2 < 0 && num1 > INT_MIN - num2)
        result.errorFlag = 1;
    return result;
}

SafeResult safeSubtract(int num1, int num2){
    SafeResult result;
    result.value = num1 - num2;
     if (num2 >= 0 && num1 < INT_MIN + num2)
        result.errorFlag = 1;
    else if (num2 < 0 && num1 > INT_MAX + num2)
        result.errorFlag = 1;
    return result;
}

SafeResult safeMultiply(int num1, int num2){
    SafeResult result;
    result.value = num1 * num2;
     if (num2 > 0 && num1 > 0 && num1 > INT_MAX / num2)
        result.errorFlag = 1;
    else if (num2 < 0 && num1 < 0 && num1 < INT_MAX / num2)
        result.errorFlag = 1;
    else if (num2 > 0 && num1 < 0 && num1 < INT_MIN / num2)
        result.errorFlag = 1;
    else if (num2 < 0 && num1 > 0 && num2 != -1 && num1 > INT_MIN / num2)
        result.errorFlag = 1;
    return result;
}

SafeResult safeDivide(int num1, int num2){
    SafeResult result;
    result.value = num1 / num2; 
    if (num1 == INT_MIN && num2 == -1)
        result.errorFlag = 1;
    return result;
}

SafeResult safeStrToInt(char *str){
    SafeResult result, tmp;
    result.value = 0;

    int isNegative = 0;
    if(str[0] == '-') isNegative = 1;

    for(int i = isNegative; str[i] != '\0' && result.errorFlag == 0; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            int digit = str[i] - '0';
        

        tmp = safeMultiply(result.value, 10);

        if(tmp.errorFlag) result.errorFlag = 1;
        else result.value = tmp.value;

        tmp = safeAdd(tmp.value, digit);

        if(tmp.errorFlag) result.errorFlag = 1;
        else result.value = tmp.value;
        }
        
        else{
            result.errorFlag = 1;
        }
    }

    if(isNegative){
        result.value *= -1;
    }
    
    return result;
}