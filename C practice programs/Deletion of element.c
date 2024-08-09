#include<stdio.h>
int main(){
int a[50],size,pos;
printf("Enter size of array");
scanf("%d",&size);
printf("Enter elements of the arrray");
for(int i=0;i<size;i++){
    scanf("%d",&a[i]);

}
printf("Enter the position from which you want to delete the element");
scanf("%d",&pos);
if(pos>size || pos<0){
    printf("Invalid position");}

else{
for(int i=pos-1;i<size-1;i++){
    a[i]= a[i+1];    }
    size--;
}
printf("Updated array is");
for(int i=0;i<size;i++){
    printf("%d",a[i]);
}

}
