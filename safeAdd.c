#include <stdio.h>
#include "safeint.h"

int main(int argc, char **argv){
    if(argc != 3){
        printf("invalid input");
    }

    else{
        SafeResult num1, num2, result;
        num1 = safeStrToInt(argv[1]);
        num2 = safeStrToInt(argv[2]);
        result = safeAdd(num1.value, num2.value);

        if(num1.errorFlag == 0 && num2.errorFlag == 0){
            printf("The result of adding %d and %d is: %d", num1.value, num2.value, result.value);
        }
        else{
            printf("Invalid input");
        }
    }
    return 0;
}