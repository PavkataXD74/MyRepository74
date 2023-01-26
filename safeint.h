#ifndef SAFEINT_H
#define SAFEINT_H

typedef struct SafeResult{
    int value = 0;
    char errorFlag = '0';
}SafeResult;


SafeResult safeAdd(int num1, int num2);
SafeResult safeSubtract(int num1, int num2);
SafeResult safeMultiply(int num1, int num2);
SafeResult safeDivide(int num1, int num2);
SafeResult safeStrToInt(char *str);

#endif