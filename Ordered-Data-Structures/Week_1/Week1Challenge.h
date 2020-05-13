#include <stack>
#include <queue>

std::stack<int> reverse_stack(std::stack<int> s) {
  std::stack<int> reversed_s;
  
  // write code here that returns a stack whose elements are
  // in reverse order from those in stack s
  while(!s.empty())
  {
    reversed_s.push(s.top());
    s.pop();
  }
  
  return reversed_s;
}

std::queue<int> reverse_queue(std::queue<int> q) {
  std::queue<int> reversed_q;
  
  // write code here that returns a queue whose elements are
  // in reverse order from those in queue q
  std::stack<int> temp;
  while(!q.empty())
  {
    temp.push(q.front());
    q.pop();
  }
  
  while(!temp.empty())
  {
    reversed_q.push(temp.top());
    temp.pop();
  }
  
  
  return reversed_q;
}
