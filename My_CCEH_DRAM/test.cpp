#include <iostream>
#include "Extendible_Hash.h"
#include<chrono>
#include <ctime>

using namespace std;
int main(int argc,char **argv){
        Extendible_Hash myhash(INITIAL,DEPTH);
        size_t *ss=new size_t[N];
        typedef std::chrono::steady_clock Clock;
        auto t1 = Clock::now();
        for(size_t time=0;time<N;time++){
            size_t rs=(time*2)+1;
            ss[time]=rs;
            while(myhash.insert(rs,time+1)==false){
                myhash.Expand(rs);
            }
        }
        auto t2 = Clock::now();
        std::cout<<"1个线程的"<<N<<"次写操作延迟:" <<float(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count())/1000000<<"ms"<<'\n';
        bool is_right=true;
        size_t value;
        int number=0;
        auto t3 = Clock::now();
        for(int t=0;t<N;t++){
             myhash.search(ss[t],value);
        }
        auto t4 = Clock::now();
        std::cout<<"1个线程的"<<N<<"次read操作延迟:" <<float(std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count())/1000000<<"ms"<<'\n';
        if(is_right){
            cout<<"output right."<<endl;
        }else{
            cout<<"there is "<<number<<" of wrong KVs"<<endl;
        }

        cout<<"global_depth is:"<<myhash.get_global_depth()<<endl;
 
 
   return 0;
 }