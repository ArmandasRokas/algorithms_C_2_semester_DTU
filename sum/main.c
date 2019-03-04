#include <stdio.h>
int sumFunction(int int1, int int2);

int main() {
    int integer1;
    int integer2;
    int sum;
    scanf("%d", &integer1);
    scanf("%d", &integer2);

    sum = sumFunction(integer1,integer2);

    printf("%d", sum );
    return 0;
}

int sumFunction(int int1, int int2){
    return int1+int2;
}