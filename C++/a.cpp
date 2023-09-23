#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  const d = {
    "kind": { "table": true },
    "rows": [
        { "userId": 1, "country": "us", "amount": 2 },
        { "userId": 2, "amount": 1 },
        { "userId": 2, "country": "de", "amount": 1 },
        { "userId": 1, "country": "us" }
    ]
  }
}