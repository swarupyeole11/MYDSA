#include<bits/stdc++.h>
#include <thread>
using namespace std;

void threadFunc()
{
  cout << "Welcome to Multithreading" << endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main()
{
  
  thread th1(threadFunc());
  th1.join();
}