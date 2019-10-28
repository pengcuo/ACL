#ifndef  __DURATION__
#define __DURATION__


#include<iostream>
#include<sys/time.h>
#include <stdlib.h>
#include<cmath>

#include <chrono>

using namespace std;

struct Duration {

public :
  Duration(double t,struct timeval s, struct timeval e): time_(0.f), start1(s), end1(e) {
  }

  void start() {
    //start_ = std::chrono::high_resolution_clock::now();
    gettimeofday(&start1,NULL);
  }

  void end() {
    //end_ = std::chrono::high_resolution_clock::now();
    gettimeofday(&end1,NULL);

  }

  double getDuration() {

    time_ = end1.tv_sec - start1.tv_sec + (end1.tv_usec - start1.tv_usec)/1000000.0;

    //time_ = std::chrono::duration<double, std::milli>(end_ - start_).count();
    return time_;
  }


private :
    double time_;
    struct timeval start1,end1;

    //std::chrono::time_point<std::chrono::high_resolution_clock> start_;
    //std::chrono::time_point<std::chrono::high_resolution_clock> end_;
};


#endif // __DURATION__
