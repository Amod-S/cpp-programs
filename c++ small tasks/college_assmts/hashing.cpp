/*
PROBLEM STATEMENT:
Load Balancing:
For example, imagine you have a set of servers that handle requests for a
web application. The key to load balancing is using the hash value of a client's IP
address or a request ID to determine which server should handle the request.
The hash function is typically designed so that the data is evenly distributed
across the servers, ensuring that no single server is overloaded. Write a program
 of a load balancing system
*/
/*
Expected Output of Assignment No. 3:
Sample Output:
Enter number of servers: 3
Enter number of incoming requests: 5
Enter request IDs:
Request 1: 192.168.1.1
Request 2: 10.0.0.5
Request 3: 123.456.789.0
Request 4: 172.16.0.1
Request 5: 192.168.1.2

Request '192.168.1.1' is handled by Server 0
Request '10.0.0.5' is handled by Server 1
Request '123.456.789.0' is handled by Server 2
Request '172.16.0.1' is handled by Server 2
Request '192.168.1.2' is handled by Server 1

Server Load Summary:
Server 0 handled 1 requests: 192.168.1.1
Server 1 handled  requests: 10.0.0.5
Server 2 handled  requests: 123.456.789.0
*/

#include <iostream>
using namespace std;

int main()
{
    int size;
    return 0;
}