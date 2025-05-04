// #include <stdio.h>
// #include "header.h"
// int linear(int arr[],int n,int target){
//     int index=-1;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(arr[j]==target){
//                 index=j;
//                 break;
//             }
//         }
//     }
//     return index;
// }

// int binary(int arr[],int n,int target){
//     int index=-1;
//     int low=0;
//     int high=n-1;
//     while(high>=low){
//         int mid=(high+low)/2;
//         if(target==arr[mid]){
//             index=mid;
//             break;
//         }
//         else if(target>arr[mid]){
//             low=mid+1;
//         }else{
//             high=mid-1;
//         }
//     }
//     return index;
// }
// int main() {
//     puts("The number of elements");
//     int no;
//     scanf("%d",&no);
//     int arr[no];
//    for(int i=0;i<no;i++){
//        scanf("%d",&arr[i]);
//    }
//    selection(arr,no);
//    int target;
//    puts("Eter the target");
//    scanf("%d",&target);
//    int c=1;
//    while(c){
//    puts("Enter the search 1)Binary 2)Linear3)Exit");
//     int n;
//     scanf("%d",&n);
//    if(n==1){
//        printf("%d \n",binary(arr,no,target));
//    }
//    else if(n==2){
//        printf("%d \n",linear(arr,no,target));
//    }
//    else if(n==3){
//        printf("Exit");
//        break;
//    }
//    else{
//     printf("Error");
//    }
//    }
    
//     return 0;
// }
