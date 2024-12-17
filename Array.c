#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct Array
{
    int capacity;
    int lastIndex;
    int *ptr;
};
struct Array* createArray(int cap)
{
    struct Array *arr;
    arr=(struct Array*)malloc(sizeof(struct Array*));
    arr->capacity=cap;
    arr->ptr=(int*)malloc(sizeof(int)*cap);
    arr->lastIndex=-1;
    return arr;
    
}
void insertValue(struct Array* arr,int value)
{
    if(arr->capacity-1==arr->lastIndex)
    {
        printf("array is full you can't enter more values inside ");
    }
    else{
        arr->lastIndex++;
        arr->ptr[arr->lastIndex]=value;
    }
}
void insertIn(struct Array* arr,int value, int index)
{ 
    if(index>arr->lastIndex+1||index<0)
    {
        printf("invalid index");
    }
    else{
        arr->lastIndex++;
        for(int i=arr->lastIndex;i>=index;i--)
        {
            arr->ptr[i]=arr->ptr[i-1];
        }
        arr->ptr[index]=value;
        
    }
}
int getValuefrom(struct Array* arr,int index)
{
    if(arr->lastIndex<index||index<0)
    {
        printf("Invalid index");
        return -1;
    }
    else{
       return  arr->ptr[index];
    }
    return -1;
}
void changeValueIn(struct  Array* arr,int value, int index)
{
    if(index>arr->lastIndex+1||index<0)
    {
        printf("invalid index");
    }
    else{
        arr->ptr[index]=value;
    }
    

}
int main()
{
    struct Array* arryay= createArray(5);
    insertValue(arryay,34);
    insertValue(arryay,35);
    insertValue(arryay,38);
    insertIn(arryay,22,1);
    insertIn(arryay,57,2);
    insertIn(arryay,89,0);
    changeValueIn(arryay,65,1);
    for(int i=0;i<=arryay->lastIndex;i++)
    {
        printf("%d  ",arryay->ptr[i]);
    }
    /* code */
    return 0;

}


