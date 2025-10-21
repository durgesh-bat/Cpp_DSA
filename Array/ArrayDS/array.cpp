#include<iostream>
#include <stdexcept> 

using namespace std;

class ArrayDS{
    private:
        int capecity;
        int *arr;
        int lastIndex;
    
    protected:
        bool isFull();
        bool isEmpty();

    public:
        ArrayDS(int);
        void append(int);   
        void showArray();
        void insertAt(int,int);
};
void ArrayDS::insertAt(int data,int index){
    if(index<0 || index>lastIndex+1)
        throw out_of_range("Index is out of range! ");
    if(isFull())
        throw overflow_error("Array is full! ");
        
    for(int i=lastIndex;i>=index;i--)
        arr[i+1] = arr[i];
    
    arr[index] = data;
    lastIndex++;
}
bool ArrayDS::isEmpty(){
    return lastIndex == -1;
}
bool ArrayDS::isFull(){
    return lastIndex == capecity -1;
}
void ArrayDS::showArray(){
    for(int i =0; i<=lastIndex;i++)
        cout<<arr[i]<<endl;
}
void ArrayDS::append(int data){
    if(isFull() == false){
        lastIndex++;
        arr[lastIndex] = data;
    }
    else
        throw overflow_error("Array is full! ");
}
ArrayDS::ArrayDS(int size){
    capecity = size;
    arr = new int[capecity]();
    lastIndex = -1;
}





int main(){
    ArrayDS a(5);
    a.append(10);
    a.append(20);
    a.append(30);
    a.append(40);
    a.append(50);
    a.append(60);

    a.showArray();
return 0;
}


