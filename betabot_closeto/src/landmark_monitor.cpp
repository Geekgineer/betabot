#include "ros/ros.h"                          // ROS Default Header File
#include "betabot_msgs/GetClosest.h"
#include "betabot_msgs/GetDistance.h"
#include "nav_msgs/Odometry.h"
#include "math.h"


// define vars members of struct
struct Landmark {
    std::string name; // name of the landmark
    double x;         // x location of closast landmark wrt the robot
    double y;         // y location of closast landmark wrt the robot
};

// class to hold our methods
class LandMarkMonitor{
    public:
        // The locations of the objects is hard coded from turtlebot playground 
        LandMarkMonitor(): landmarks_() , x_(0),y_(0) {
            landmarks_ = { {"Cube",{"Cube",0.31,-0.99}},
                           {"Dumpster",{"Dumpster",0.11,-2.24}},
                           {"Cylinder",{"Cylinder",-0.14,-2.88}},
                           {"Barrier",{"Barrier",-2.59,-0.83}},
                           {"Bookshelf",{"Bookshelf",0.09,0.53}} };
                    };

        // callback function to get the closest landmark
        bool GetClosest(betabot_msgs::GetClosest::Request &request,
                        betabot_msgs::GetClosest::Response &response){
            ROS_INFO("GetClosest called");
            
            /* your algo start here */

            double best_distance = -1;
            std::string best_landmark("");

            // loop over the landmarks poses
            for (const auto &pair : landmarks_) 
            {
                const Landmark &landmark = pair.second;
                // calculate the absolute euclidean distance between the landmark and the robot pos
                double dx = landmark.x - x_;
                double dy = landmark.y - y_;
                double sq_dist = dx*dx + dy*dy;
                
                // check if this is smallast distance and register its name
                if (best_distance == -1 || sq_dist < best_distance){
                    best_distance = sq_dist;
                    best_landmark = pair.first;
                };
            };

            // respond with the closest landmark name
            response.name = best_landmark;

            /* End of your algo  */
            return true;
            }
        
        bool GetDistance(betabot_msgs::GetDistance::Request &request,
                         betabot_msgs::GetDistance::Response &response){
            ROS_INFO("GetDistance called for %s", request.name.c_str());
            
            /*  Put your algo here */

            // check for the landmark existence
            if (landmarks_.find(request.name) == landmarks_.end()){
                ROS_ERROR("You requested unknown landmark! \"%s\"",request.name.c_str());
                return false;
            };
            
            const Landmark &landmark = landmarks_[request.name];
            double dx = landmark.x - x_;
            double dy = landmark.y - y_;
            response.distance =sqrt(dx*dx +dy*dy); 
            
            /* End of your algo  */
            return true;
            }
    
        void OdomCallback(const nav_msgs::OdometryConstPtr &msg){
            x_ = msg->pose.pose.position.x;  // get the robot x pose from the odom topic
            y_ = msg->pose.pose.position.y;  // get the robot y pose from the odom topic
            }

    private:
        std::map<std::string, Landmark> landmarks_;
        double x_;
        double y_;
};

int main(int argc, char **argv)                // Node Main Function
{
  ros::init(argc, argv, "landmark_monitor");   // Initializes Node Name
  ros::NodeHandle nh;                          // Node handle declaration

  // Create instance form our class
  LandMarkMonitor monitor;
  
  // Hook our service Servers to the master
  ros::ServiceServer get_closest = nh.advertiseService("get_closest",&LandMarkMonitor::GetClosest,&monitor);
  ros::ServiceServer get_distance = nh.advertiseService("get_distance",&LandMarkMonitor::GetDistance,&monitor);

  // Hook our Subscriber to the master
  ros::Subscriber sub = nh.subscribe("/odom",1,&LandMarkMonitor::OdomCallback,&monitor);
  ros::spin();                                 // Wait for ever for the service request

  return 0;
}