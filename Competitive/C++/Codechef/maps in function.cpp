#include <map>
#include <iostream>

typedef long long int in;

using namespace std;
in fibonacci(in n)
{
  static std::map<in, in> values;
  if (n==0 || n==1)
    return n;
  std::map<in,in>::iterator iter = values.find(n);
  if (iter == values.end())
  {
    return values[n] = fibonacci(n-1) + fibonacci(n-2);
  }
  else
  {
    return iter->second;
  }
}

int main () {
    std::map <int,int> val;
    std::cout << fibonacci(150);
}