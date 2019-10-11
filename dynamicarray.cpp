#include "dynamicarray.h"

template <class Data_Type>
DynamicArray <Data_Type>::DynamicArray()
{
    pointer = NULL ;
    n=0;
}
template <class Data_Type>
DynamicArray <Data_Type>::DynamicArray (int value_n )
{
    n = value_n;
    pointer = new Data_Type[n];
}
template <class Data_Type>
DynamicArray <Data_Type> :: ~DynamicArray ()
{
    delete[] pointer;
}
template <class Data_Type>
DynamicArray <Data_Type>::DynamicArray (const DynamicArray <Data_Type>& Copy)
{
    n = Copy.n;
    pointer = new Data_Type[n];
    *this = Copy;
}

template <class Data_Type>
DynamicArray <Data_Type>& DynamicArray <Data_Type> :: operator = (const DynamicArray <Data_Type>& Copy)
{
    for (int i = 0; i < n; i++)
    {
        pointer[i] = Copy.pointer[i];
    }
    return *this;
}
template <class Data_Type>
void DynamicArray <Data_Type>::Add_Last(Data_Type new_value)
{
    Data_Type* temp = new Data_Type[n + 1];
    // check if there is enough space

    // copy all the 2 arrays exept the last element
    for (int i = 0; i < n; i++)
        temp[i] = pointer[i];
    // put the new_value at the last element
    temp[n] = new_value;

    // free the space of the original pointer
    delete[] pointer;
    // make the pointer points at the new array you have made
    pointer = temp;
    n++;
}
template <class Data_Type>
void DynamicArray <Data_Type> :: Add_First(Data_Type new_value)
{
    Data_Type* temp = new Data_Type[n + 1];

    // check if there is enough space


    // copy all the 2 arrays exept the first element
    for (int i = 1; i <= n ; i++)
        temp[i] = pointer[i-1];
    // put the new_value at the first element
    temp[0] = new_value;

    // free the space of the original pointer
    delete[] pointer;
    // make the pointer point at the new array you have made
    pointer = temp;
    n++;
}
template <class Data_Type>
int DynamicArray <Data_Type>::search(Data_Type value)
{
    for (int i = 0; i < n; i++)
    {
        // return the position of the value that you want to search
        if (pointer[i] == value)
        {
            return i;
        }
    }
    return -1;
}
template <class Data_Type>
void DynamicArray <Data_Type>::Delete(Data_Type value)
{
    // new array that has less space (n-1 ) as we delete 1 element
    Data_Type* temp = new Data_Type[n-1];


    // get the position of the value that you want to delete
    int position = search(value);



    for (int i = 0 , j =0 ; j< n-1 && i < n;  i++)
    {
        // copy all the 2 arrays exept the value that you want to delete
        if (i == position)
        {
            continue;
        }
        temp[j] = pointer[i];
        j++;
    }

    n--;
    delete[] pointer;
    pointer = temp;

}
template <class Data_Type>
void DynamicArray <Data_Type>::Insert(Data_Type value, int pos)
{
    // resize the array and add 1 more space
    n++;
    Data_Type* temp = new Data_Type[n];
    // check if there is enough space


    // variable that tell me that we inserted the value
    int variable_inserted = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == pos)
        {
            temp[pos] = value;
            variable_inserted = 1;
            continue;
        }
        // if we inserted the value .. we have to copy pointer [i-1] as we skiped this pos when we inserted the value
        if (variable_inserted == 1)
        {
            temp[i] = pointer[i - 1];
        }
        // if we didn't insert the value yet .. so we copy the elements normally from pointer to temp
        else if (variable_inserted == 0)
        {
            temp[i] = pointer[i];
        }
    }

    delete[] pointer;
    pointer = temp;
}
template <class Data_Type>
int DynamicArray <Data_Type>::size()
{
    return n;
}
template <class Data_Type>
int DynamicArray <Data_Type>::max()
{
    Data_Type max = pointer[0];
    for (int i = 1; i < n; i++)
    {
        // if the element is > than max .. make it max
        if (pointer[i] > max)
        {
            max = pointer[i];
        }
    }
    return max;
}
template <class Data_Type>
int DynamicArray <Data_Type>::min()
{
    Data_Type min = pointer[0];
    for (int i = 1; i < n; i++)
    {
        // if the element is less that the min .. make it min
        if (pointer[i] < min)
        {
            min = pointer[i];
        }
    }
    return min;
}
template <class Data_Type>
Data_Type& DynamicArray <Data_Type> :: operator [] (int pos)
{
    if (pos >= 0 && pos < n)
    {
        return pointer[pos];
    }

    // to support arr[-1] index from end ... like python ... arr = { 1, 2 ,3 }  .. arr[-1] = 3
    else if (pos < 0 && n + pos >= 0)
    {
        return pointer[n + pos];
    }


}
template <class Data_Type>
void DynamicArray <Data_Type> :: operator = (Data_Type initial_value)
{
    for (int i = 0; i < n; i++)
    {
        pointer[i] = initial_value;
    }
}
template <class Data_Type>
DynamicArray <Data_Type>& DynamicArray <Data_Type> :: operator += (Data_Type value)
{
    Add_Last(value);
    return *this;
}
template <class Data_Type>
DynamicArray <Data_Type>& DynamicArray <Data_Type> :: operator += (DynamicArray <Data_Type>& added_array)
{
    int temp_n = n;
    n += added_array.n;
    Data_Type* temp = new Data_Type[n];


    for (int i = 0; i < temp_n; i++)
    {
        temp[i] = pointer[i];
    }

    for (int i = temp_n , j = 0; j <added_array.n && i < n; j++ , i++)
    {
        temp[i] = added_array.pointer[j];
    }

    delete[] pointer;
    pointer = temp;

    return *this;
}
template <class Data_Type>
DynamicArray <Data_Type> operator + (DynamicArray <Data_Type> First_array , DynamicArray <Data_Type> added_array)
{
    First_array += added_array;
    return First_array;
}
template <class Data_Type>
void DynamicArray <Data_Type>::Swap(int pos1, int pos2)
{
    Data_Type Temp = pointer[pos1];
    pointer[pos1] = pointer[pos2];
    pointer[pos2] = Temp;
}
template <class Data_Type>
void DynamicArray <Data_Type>::Sort()
{
    // Buble Sort Algorithm
    // iner loop is to Move the Bigest Element at Last
    // Outer loop is to repeat that operation until all thing is sorted
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - j - 1; i++)
        {
            Data_Type Temp;
            if (pointer[i] > pointer[i + 1])
            {
                Swap(i, i + 1);
            }
        }
    }
}

template <typename Data_Typ > ostream& operator << (ostream& our_cout, DynamicArray<Data_Typ> printed_array)
{
    // very important
    // we send printed_array object by value but it didn't clear the original memory of the parameter and it works fine !!
    // Because Copy Constructor is called when we send the object by value and get a copy of it (not pointing at the same chunk of memory )
    // so we can now pass any object by value because of copy constructor
    for (int i = 0; i < printed_array.n; i++)
    {
        our_cout << printed_array.pointer[i];
        our_cout << "  ";
    }
    cout << "\n";
    return our_cout;
}

template <typename Data_Typ > istream& operator >> (istream& our_cin, DynamicArray<Data_Typ>& Get_array)
{
    for (int i = 0; i < Get_array.n; i++)
    {
        our_cin >> Get_array.pointer[i] ;
    }
    return our_cin;
}


// int main()
// {
// 	DynamicArray <Data_Type> <Data_Type> Num(3);
// 	DynamicArray <Data_Type> <Data_Type> NEW2(3);
// 	DynamicArray <Data_Type> s(6);
// 	cin >> Num;
// 	cin >> NEW2;
// 	s = Num + NEW2;
// 	cout << Num;
// 	cout << NEW2;
// 	cout << s;


// 	Num.Add_Last(100);
// 	Num.Add_First(300);

// 	cout << "add  last :" << Num;
// 	Num.Insert(22, 2);
// 	cout << "insert " << Num;
// 	int find = Num.search(22);
// 	cout << "find 22 :" << find << "\n";
// 	Num.Delete(3);
// 	cout << Num;
// 	int n = Num.size();
// 	cout << "size  " << n << "\n ";
// 	n = Num.max();
// 	cout << "max " << n << "\n ";

// 	return 0;
// }
