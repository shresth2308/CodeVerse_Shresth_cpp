#include<iostream>
using namespace std;
template <class T>
class vector{
    public:
    int size;
    T* arr;
    public:
    vector(int m){
        size=m;
        arr=new T[size];
    }
    T dotProduct(vector &v){
        T d=0;
        for(int i=0;i<size;i++){
            d+=this->arr[i]*v.arr[i];
        }
        return d;
    }
    ~vector(){
        delete[] arr;
    }
};

int main(){ 
    vector <float> v1(3);
    v1.arr[0]=3.6;
    v1.arr[1]=4.2;
    v1.arr[2]=1.9;
    vector <float> v2(3);
    v2.arr[0]=1.09;
    v2.arr[1]=5.1;
    v2.arr[2]=2.67;
    float a = v1.dotProduct(v2);
    cout<<"Dot Product: "<<a<<endl;
    return 0;
}