#include <iostream>
#include <stack>

using namespace std;

class max_stack 
{
private:
  stack<int> st_main;
  stack<int> st_max;

public:
  int max() { return st_max.top(); }

  void push(int x) 
  {
    st_main.push(x);
    if (st_max.empty() || x >= st_max.top()) st_max.push(x);
  }

  void pop() 
  {
    if (st_main.top() == st_max.top()) st_max.pop();
    st_main.pop();
  }
};

int main() 
{
  int N, type, x;
  cin >> N;

  max_stack st;
  while (N--) 
  {
    cin >> type;
    switch (type) 
    {
    case 1:
      cin >> x;
      st.push(x);
      break;
    case 2:
      st.pop();
      break;
    case 3:
      cout << st.max() << '\n';
      break;
    }
  }
  return 0;
}
