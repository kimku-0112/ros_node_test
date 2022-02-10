#include <iostream>
#include <chrono>
#include <signal.h>
#include "ros/ros.h"

void shutdownHandler(int sig){
  printf("\nprogram exit()\n------------------------------------------------------\n");
  //system("rosnode kill /test_node");
  ros::shutdown();
  exit(0);
}

int main(int argc, char **argv){ 

  ros::init(argc, argv, "test_node");
  ros::NodeHandle nh;

  signal(SIGINT, shutdownHandler);  
  
  long oldtime =static_cast<long>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()); // 현재 ms
  long timetick; // 현재 ms
  //exit(0);  
  //while(ros::ok()){
  while(ros::master::check()){
    ros::spinOnce();
    if(timetick > 1000){
      printf("waiting ctrl + c\n"); 
      oldtime =static_cast<long>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    }
    timetick = static_cast<long>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()) - oldtime;
  };
   
  //ros::spin(); 
  
  return 0;
}
