#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;

    void insert(int val)
    {

        int index = size;
        arr[index] = val;

        int parent = (index - 1) / 2;

        while (index > 0 && arr[parent] < arr[index])
        {
            swap(arr[index], arr[parent]);
            index = parent;
            parent = index / 2;
        }
        size++;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
int main()
{
    heap h;
    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(10);
    h.insert(55);

    h.print();
    return 0;
}