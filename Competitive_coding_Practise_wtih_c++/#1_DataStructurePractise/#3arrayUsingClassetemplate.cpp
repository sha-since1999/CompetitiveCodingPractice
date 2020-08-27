#include <iostream>
using namespace std;
 template<class T>
class array
{
private:
    T *A;
    int length;
    int size;
    void swap(T *, T *);

public:
    array()
    {
        A = new T[10];
        length = 0;
    }
    array(int size)
    {
        size = size;
        A = new T[size];
        length = 0;
    }
    ~array()
    {
        delete[] A;
    }
    T display();
    T set(T key, int index);
    T get(T key);
    // int *revese();
    array simple_class_obj_return()
    {
        array arr1(7);
       
        arr1.set(3, 0);
        arr1.set(4,1);
        arr1.set(3, 2);
        arr1.set(4,3);
        return arr1;
    }
   array *class_pointer_obj_return()
    {
        array *arr=new array(7);
        array arr1(7);
       
       
        arr->set(3,0);
        arr->set(4,1);
        arr->set(5,2);
        arr->set(2,3);
        return arr;
  }
};
template<class T>
T array<T>::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
template<class T>
T array<T>::get(T key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
            return i;
    }
    return -1;
}
template<class T>

T array<T>::set(T key, int index)
{
    
    A[index] = key;
    length++;
    return 1;
}

template <class T>
void array<T>::swap(T *x, T *y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int ch;
    int i;
    int index, key;
    array<int> arr2;
    cout << arr2.class_pointer_obj_return()->display() << endl;
    
    cout << arr2.simple_class_obj_return().display() << endl;
    

    // cout << "enter the size of array:" << endl;
    // cin >> i;
    // array *arr1;
    // arr1 = new array[1];
    // do
    // {
    //     cout << endl
    //          << "1) set " << endl;
    //     cout << "2) get " << endl;
    //     cout << "3) display " << endl;
    //     cout << "press -1 for exit" << endl;
    //     cin >> ch;
    //     switch (ch)
    //     {
    //     case 1:
    //         cout << "enter key: And index:" << endl;
    //         cin >> key >> index;
    //         arr1->set(key, index);
    //         break;
    //     case 2:
    //         cout << "enter index:" << endl;
    //         cin >> index;
    //         cout << arr1->get(index);
    //         break;
    //     case 3:
    //         arr1->display();
    //         break;
    //     default:
    //         cout << "choose correctly" << endl;
    //         break;
    //     }
    // } while (ch != -1);

    /* ---------------here your all pointer doubt should be clear ------------(to clear make variable public first)*/

    // cout << *((*arr1).A+1) ;// class treated as structure its wasy for u to understand
    // cout << arr1->A[1];
    // cout << *(arr1->A + 1);
   
    // delete[] arr1;
    return 0;
}