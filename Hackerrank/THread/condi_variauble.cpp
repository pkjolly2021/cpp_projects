//use conditional variabl to print even and odd number in separeate thread from global array

          


/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <thread>
#include  <condition_variable>
#include  <mutex>

using namespace std;

std::array<int, 10> glob_arr {1,2,3,4,5,6,7,8,9,10};
int i = 0;
std::thread th1, th2;
std::mutex mu;
std::condition_variable cv;


void print_even(void)
{
    std::cout<<"print even"<<std::endl;
  while(i <= 9)
  {
     std::unique_lock<std::mutex> lock(mu);
     if(glob_arr[i]%2)
     {
         std::cout<<"print wait CV"<<std::endl;
        cv.wait(lock);
        
     }
     std::cout<<"Even number is: "<<glob_arr[i++]<<std::endl;
     lock.unlock();
  }
}

void print_odd(void)
{
    std::cout<<"print odd"<<std::endl;
   while(i <= 9)
   {
      std::unique_lock<std::mutex> lock(mu);
      if( glob_arr[i] % 2)
      {
        std::cout<<"Odd number is: "<<glob_arr[i++]<<std::endl;
      }
      lock.unlock();
      cv.notify_one();
   }
}

int main()
{
    th1 = std::thread(print_even);
    th2 = std::thread(print_odd);

    th1.join();
    th2.join(); 
}
