/*problem statement: The hash function is typically designed so that the data
 is evenly distributed across the servers, ensuring that no single server is
  overloaded.
- Write a program of a load balancing system using hashing, where a basic hash
table for mapping incoming requests to a set of servers.
*/
/*
approach:
get ip address as a string. pass it througha hashfunction. get an index. create a visited array, set all indices to 0,
then check the index we got from has function if its 0 then store the ip in a result array, else linear probe through all
indices in the result array.
*/

#include <iostream>
using namespace std;

int hash_func(string ip, int size)
{
    int sum = 0;
    for (int i = 0; i < ip.length(); i++)
    {
        sum += ip[i];
    }
    return sum % size;
}

void display(string arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == "")
        {
            continue;
        }
        cout << arr[i] << endl;
    }
}

int main()
{
    int num_servers;
    int num_reqs;
    cout << "enter the number of servers: ";
    cin >> num_servers;
    while (true)
    {
        cout << "enter the number of requests: ";
        cin >> num_reqs;
        if (num_reqs > num_servers)
        {
            cout << "number of requests cannot be more than number of servers." << endl;
            continue;
        }
        break;
    }

    string result[num_servers];
    for (int i = 0; i < num_servers; i++)
    {
        result[i] = "";
    }
    int visited[num_servers];
    string ip_id;
    // initialize visited array to value 0
    for (int i = 0; i < num_servers; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < num_reqs; i++)
    {

        cout << "Enter ip address: ";
        cin >> ip_id;
        int hash_k = hash_func(ip_id, num_servers);
        // now to store the ip in result array
        if (visited[hash_k] == 0)
        {
            result[hash_k] = ip_id;
            visited[hash_k] = 1;
        }
        else
        {
            int i = (hash_k + 1) % num_servers;
            while (i != hash_k)
            {
                if (visited[i] == 0)
                {
                    result[i] = ip_id;
                    visited[i] = 1;
                    break;
                }
                i = (i + 1) % num_servers;
            }
            // for (int i = hash_k; i < num_servers; i = (i + 1) % num_servers)
            // {

            //     if (visited[i] == 0)
            //     {
            //         result[i] = ip_id;
            //         visited[i] = 1;
            //         break;
            //     }
            //     if (i == abs(hash_k - 1) && visited[i] != 0)
            //     {
            //         cout << "No servers available." << endl;
            //         break;
            //     }
            // }
        }
    }
    display(result, num_servers);
    return 0;
}