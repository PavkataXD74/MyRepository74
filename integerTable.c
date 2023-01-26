#include <stdio.h>
#include <limits.h>
#define PRINT(NAME, FORMAT, SIZE, MAX, MIN, UNSFORM, UNSMAX)\
        printf("%-20s%-20s%-20zu%-30"FORMAT"%-30"FORMAT"%-30s%-20"UNSFORM"\n", NAME, "%" FORMAT, SIZE, MAX, MIN, "%" UNSFORM, UNSMAX)

int main(){
    printf("%-20s%-20s%-20s%-30s%-30s%-30s%-20s\n","name", "format", "size", "signedMax", "signedMin", "UnsignedForm", "UnsMax");
    PRINT("int","d", sizeof(int), INT_MAX, INT_MIN, "u", UINT_MAX);
    PRINT("char", "c", sizeof(char), CHAR_MAX, CHAR_MIN, "c", UCHAR_MAX);
    PRINT("short", "hd", sizeof(short), SHRT_MAX, SHRT_MIN, "hu", USHRT_MAX);
    PRINT("long","ld",sizeof(long),LONG_MAX,LONG_MIN,"lu",ULONG_MAX);
    PRINT("long long","lld",sizeof(long long),LLONG_MAX,LLONG_MIN,"llu",ULLONG_MAX);

    return 0;
}