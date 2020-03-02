#include "ros/ros.h"                          // ROS Default Header File
#include "betabot_msgs/GetClosest.h"
#include "betabot_msgs/GetClosestResponse.h"
#include "betabot_msgs/GetDistance.h"
#include "betabot_msgs/GetDistanceRequest.h"
#include <iostream>


int main(int argc, char **argv)                // Node Main Function
{
  ros::init(argc, argv, "landmark_client");   // Initializes Node Name
  ros::NodeHandle nh;                          // Node handle declaration

  // Hook our service clients to the master
  ros::ServiceClient get_closest = nh.serviceClient<betabot_msgs::GetClosest>("get_closest");
  ros::ServiceClient get_distance = nh.serviceClient<betabot_msgs::GetDistance>("get_distance");

  // // When using simulated Clock time, now() returns time 0 until first message
  // // has been received on /clock, so 0 means essentially that the client does 
  // // not know clock time yet. A value of 0 should therefore be treated differently,
  // // such as looping over now() until non-zero is returned.
  // // for simulation only we spin until ROS has setup a simulated Clock for nodes
  // while (ros::Time::now().is_zero())
  // {
  //   ros::spinOnce();
  // }

  // // checking the get_closest server existence 
  // if(!get_closest.waitForExistence(ros::Duration(5))){
  //     ROS_ERROR("get_closest server did not come up in 5 seconds!");
  //     return 1; // to exit if no server is running
  // };
  // // checking the get_distance server existence 
  // if(!get_distance.waitForExistence(ros::Duration(5))){
  //     ROS_ERROR("get_distance server did not come up in 5 seconds!");
  //     return 1; // to exit if no server is running
  // };

  // create request and response from GetClosest.srv
  betabot_msgs::GetClosestRequest clo_req;
  betabot_msgs::GetClosestResponse clo_res;
  
  // Call the service aliased by this handle (nh) with the specified request/response messages
  get_closest.call(clo_req,clo_res);

  // print to terminal the closest landmark name
  std::cout <<" Closest Landmark is the " << clo_res.name << std::endl;  

  // The landmark names listed from turtlebot playground 
  std::vector<std::string> landmarks =  {"Cube",
                                         "Cylinder",
                                         "Barrier",
                                         "Bookshelf",
                                         "Dumpster"};

  // Loop over all landmarks and get their distances from get_distance server
  for (const std::string &landmark_name :landmarks)
  {     
        // create the request from GetDistance.srv 
        betabot_msgs::GetDistanceRequest dist_req;

        // assgin the current landmark name to our request
        dist_req.name = landmark_name;
        
        // create the response from GetDistance.srv 
        betabot_msgs::GetDistanceResponse dist_res;
        
        // Call the service aliased by this handle (nh) with the specified request/response messages
        get_distance.call(dist_req,dist_res);

        // print to terminal the closest landmark distance
        std::cout << "-------------- \n" << landmark_name << ":" << dist_res << std::endl;          

  }

  return 0;
}