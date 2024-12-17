#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct DynamicArray{
    int capacity;
    int lastIndex;
    int *ptr;
};
struct DynamicArray* createDynamicArray(int cap)
{
    struct DynamicArray* darr;
    darr=(struct DynamicArray*)malloc(sizeof(struct DynamicArray));
    darr->capacity=cap;
    darr->lastIndex=-1;
    darr->ptr=(int*)malloc(sizeof(int)*cap);
    return darr;

}
void insertValue(struct DynamicArray* darr,int value)
{
    // if(darr->lastIndex>darr->capacity-1)
    // {
    //     printf("memmory full");
    // }
    // else{
        darr->lastIndex++;
        darr->ptr[darr->lastIndex]=value;
    // }

}
void updateSize(struct DynamicArray* darr,int size)
{ 
    struct DynamicArray* temp;
      temp=(struct DynamicArray*)malloc(sizeof(struct DynamicArray));
      temp->ptr=(int*)malloc(sizeof(int)*size);
      darr->capacity=size;
      for(int i=0;i<=darr->lastIndex;i++)
      {
        temp->ptr[i]=darr->ptr[i];
      }
      free(temp);
}
int main(int argc, char const *argv[])
{
    struct DynamicArray* darr;
    darr=createDynamicArray(3);
    insertValue(darr,45);
    insertValue(darr,46);
    int arr[2];
    insertValue(darr,345);
    insertValue(darr,88);
    insertValue(darr,85); 


   
    updateSize(darr,5);

    printf("size: %d\n",darr->capacity);
    for(int i=0;i<=darr->lastIndex;i++)
    {
      printf("%d ", darr->ptr[i]);
    }
   
    return 0;
}
