#include <iostream>
using namespace std;

int main()
{
    int hash_t[10];
    int T[10];
    int arr[10];
    int hash_k;

    cout << "Enter values: ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << '\n';
    }

    for (int i = 0; i < 10; i++)
    {
        T[i] = 0;
    }

    for (int i = 0; i < 10; i++)
    {
        hash_k = arr[i] % 10;
        if (T[hash_k] == 0)
        {
            hash_t[hash_k] = arr[i];
            T[hash_k] = 1;
        }
        else
        {
            for (int j = 0; j < 10; j++)
            {
                int hash_k2 = (hash_k + j) % 10;
                if (T[hash_k2] == 0)
                {
                    hash_t[hash_k2] = arr[i];
                    T[hash_k2] = 1;
                    break;
                }
            }
        }
    }
    cout << "Hash Table:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << hash_t[i] << '\n';
    }
    return 0;
}