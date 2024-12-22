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

void delete(struct DynamicArray* darr,int index)
{
    if(index>darr->lastIndex||index>darr->capacity||index<0)
    { 
        printf("Invalid index");
       

    }
    else{
     for(int i=index;i<darr->lastIndex;i++)
        {
            darr->ptr[i]=darr->ptr[i+1];
        }
        darr->lastIndex--;
    }
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
void delteFromlast(struct DynamicArray* darr)
{
    if(darr->lastIndex<0)
    {
        printf("Array is empty not have element to delete\n");
    }
    else{
        darr->lastIndex--;
    }
}
void updateSize(struct DynamicArray* darr,int size)
{ 
    int *p=darr->ptr;
    darr->ptr=(int *)malloc(sizeof(int)*size);
    for(int i=0;p[i];i++)
    {
        darr->ptr[i]=p[i];
    }
    darr->capacity=size;
    
     
}
int main(int argc, char const *argv[])
{
    int a[3];
    a[56]=445;
    struct DynamicArray* darr;
    darr=createDynamicArray(3);
    insertValue(darr,45);
    insertValue(darr,46);
    insertValue(darr,45);
    insertValue(darr,25);
    insertValue(darr,73);
    delteFromlast(darr);
    printf("size: %d\n",darr->capacity);
    for(int i=0;i<=darr->lastIndex;i++)
    {
      printf("%d ", darr->ptr[i]);
    }
    free(darr->ptr);
    free(darr);
   
    return 0;
}
