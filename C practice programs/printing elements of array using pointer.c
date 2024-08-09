#include <stdio.h>
int main() {
    int array[n];
    printf("Enter size of array");
    scanf("%d",&n);


    printf("Enter elements: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", array+i  );

    printf("You entered: \n");
    for (int i = 0; i < n; ++i)
        printf("%d\n", *(array + i ));
    return 0;
}
