#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 void reverseString(char *str){
    int i;
    int j = strlen(str) - 1;
    char temp;
    for(i=0;*(str+i)!='\0';i++){
        temp = *(str + i);
        *(str + i) = *(str + j);
        *(str + j) = temp;
        if(i==j||i==j-1){
            break;
        }
        j--;
    }
    printf("%s\n",str);
}

int main(){

    printf("string reverse : ");
    char str[] = "im coder ";
    reverseString(str);
    // output : redoc mi
  return 0;
} 
