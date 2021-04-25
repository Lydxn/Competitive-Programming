#include <stdio.h>

int count(int x){

 return ((int*)__builtin_apply_args())[6]<2?2:3;

}

int main(i){for(i=1;i%1000001;i++)printf("%d %d\n",i,count(i));return 0;}
