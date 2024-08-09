#include<stdio.h>
int a[50],size,i,num,pos;
int main(){
printf("Enter size of array\n");
scanf("%d",&size);
printf("Enter elements\n");
for(int i=0;i<size;i++){
    scanf("%d",&a[i]);
}
printf("Array is\n");
for(int i=0;i<size;i++){
    printf("%d",a[i]);
}
printf("Enter data to be inserted\n");
scanf("%d",&num);
printf("Enter position\n");
scanf("%d",&pos);
for(int i = size-1;i>=pos -1;i--){
    a[i+1]=a[i];
}
a[pos-1] = num;
size++;
printf("Updated array:\n");
for(int i = 0;i<size;i++){
    printf("%d",a[i]);
}
}
