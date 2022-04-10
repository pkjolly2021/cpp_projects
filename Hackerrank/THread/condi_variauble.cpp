#include <iostream>
#include <memory>
#include<thread>
#include<mutex>
#include <condition_variable>
#include<vector>

//create a thread inside a class

class check
{
    private:
    int i;
      std::thread th1;
      std::thread th2;
      std::mutex mu;
      std::condition_variable cond_var;
      std::vector<int> my_vec;
    public:
    void even_thread(void);
    void odd_thread(void);
     void start_thread(void)
     {
        th1 = std::thread(&check::even_thread, this);
        th2 = std::thread(&check::odd_thread, this);
 
        th1.join();
        th2.join();         
     }
     check(std::vector<int>& dat)
     {
          std::cout<<"inside const"<<std::endl;
          my_vec = dat;
     }
     ~check()
     {}
};


void check::even_thread()
{
   for (i =0; i< my_vec.size(); i++)
   {
      std::unique_lock<std::mutex> lck(mu);  //get mutex
     cond_var.wait(lck, [this](){return (my_vec[i]%2 == 0);});  //wait for other thread to execute   
     std::cout<<"Even thread data is: "<<my_vec[i]<<std::endl;
     lck.unlock();
     cond_var.notify_all();
   }
}


void check::odd_thread()
{
   for (i =0; i< my_vec.size(); i++)
   {
      std::unique_lock<std::mutex> lck(mu);   //get mutex
      cond_var.wait(lck, [this](){std::cout<<"inside check for ODD indx is: "<<i<<std::endl; return(my_vec[i]%2 == 1);});
      std::cout<<"Odd thread data is: "<< my_vec[i]<<std::endl;
      lck.unlock();
      cond_var.notify_all();
   }   
}

int main()
{
   std::vector<int> test={1,2,3,4,5,6,8,10,12,13,14};
   std::shared_ptr<check> obj_ptr = std::make_shared<check>(test);
   obj_ptr->start_thread();
}