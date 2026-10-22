/*
1. Rainfall Tracking
Write a program to track rainfall data for 3 cities over 4 months. Using a 2D array,
we can store the data, calculate the average rainfall for each city, and display the
rainfall data in a tabular format.
- Discuss the applications of multidimensional arrays.
- Also discuss the advantages of sparse matrix over simple matrix.*/

#include <iostream>
using namespace std;

void getData(int arr[][4])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "Enter the rainfall in mm for city " << i + 1
                 << " and month " << j + 1 << ": ";
            cin >> arr[i][j];
        }
    }
}

void displayData(int arr[][4])
{
    cout << "    \tMonth 1\tMonth 2\tMonth 3\tMonth 4\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "City " << i + 1 << ":\t";
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
}

void calcAvg(int arr[][4], int city)
{
    float avg = 0;
    for (int i = 0; i < 4; i++)
    {
        avg += arr[city][i];
    }
    cout << "Average for city " << city + 1 << "is: " << avg / 4;
}

int main()
{

    int rain_data[3][4];
    getData(rain_data);

    int user_choice;
    cout << "Enter option number(1/2)" << endl;
    cout << "1. Display rainfall data" << endl;
    cout << "2. Calculate average rainfall for a city" << endl;

    cin >> user_choice;
    if (user_choice == 1)
    {
        displayData(rain_data);
        cout << endl;
    }
    else if (user_choice == 2)
    {
        int city_number;
        cout << "Enter city number: " << endl;
        cin >> city_number;
        calcAvg(rain_data, city_number - 1);
        cout << endl;
    }
    else
    {
        cout << "Invlaid input." << endl;
    }

    return 0;
}