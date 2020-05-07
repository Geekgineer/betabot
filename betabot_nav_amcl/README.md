# Betabot Localization and Navigation

- [Betabot Localization and Navigation](#betabot-localization-and-navigation)
  - [Project Description](#project-description)
  - [GUID](#guid)
  - [Project Rubric](#project-rubric)
  - [After you implement the pkg state your reflection below](#after-you-implement-the-pkg-state-your-reflection-below)
  - [Part I: Map (map_server)](#part-i-map-mapserver)
    - [In your own words how maps are represented in ROS?](#in-your-own-words-how-maps-are-represented-in-ros)
    - [State 5 algorithm for SLAM and the ROS implementation](#state-5-algorithm-for-slam-and-the-ros-implementation)
  - [Part II: Localization (amcl)](#part-ii-localization-amcl)
    - [In your own words how amcl works?](#in-your-own-words-how-amcl-works)
    - [Is there other better approaches to localize your robot rather than amcl?](#is-there-other-better-approaches-to-localize-your-robot-rather-than-amcl)
    - [What are the amcl limitations or the fail cases?](#what-are-the-amcl-limitations-or-the-fail-cases)
    - [Is amcl used in domain rather than Robotics?](#is-amcl-used-in-domain-rather-than-robotics)
  - [Part III: Navigation (move_base)](#part-iii-navigation-movebase)
    - [How many official local planner available in ROS?](#how-many-official-local-planner-available-in-ros)
    - [which local planner did you use?](#which-local-planner-did-you-use)
    - [In your own words how the local planner you selected works?](#in-your-own-words-how-the-local-planner-you-selected-works)
    - [How many official global planner available in ROS?](#how-many-official-global-planner-available-in-ros)
    - [which global planner did you use?](#which-global-planner-did-you-use)
    - [In your own words how the global planner you selected works?](#in-your-own-words-how-the-global-planner-you-selected-works)
    - [State your suggestion increase the overall performance?](#state-your-suggestion-increase-the-overall-performance)
    - [List the most time consuming problems you faced](#list-the-most-time-consuming-problems-you-faced)
    - [Demos](#demos)
    - [Screenshots](#screenshots)
      - [NAME:](#name)
      - [ID:](#id)

## Project Description 

Create a ROS package with custom launch files to localize the robot in an environment given the map and also to autonomous navigation. 

*Use the given [map](map/map2d.yaml) for the myoffice world [here](../betabot_gazebo/worlds/myoffice.world)* 

<p float="center">
  <img src="img/myoffice.png" width="589" /> 
  <img src="img/map2d.png" width="500" />
</p>


>NOTE: For the given map and a world the betabot robot should localize it self and move from currant pose to a given goal autonomously

## GUID
Follow where am I project from Udacity Software Robotics Engineer Nanodegree.

---
## Project Rubric

![rubric](img/reviews.jpg) 

---

# The code is present in the directory for you to check and there is a video attached at the end 

---

## After you implement the pkg state your reflection below 

---
## Part I: Map (map_server)

###  In your own words how maps are represented in ROS?


###  State 5 algorithm for SLAM and the ROS implementation

| SLAM Algorithm | ROS implementation |
|:--------------:|:------------------:|
|     GMapping   |      gmapping      |
|     Laser-Slam |      tinySlam      |
|    gridmap Slam|      mrpt_rbpf_slam|
|    CRSM SLAM   |      crsm_slam     |
|    RTAB-Map    |      rtabmap_ros   |

---

## Part II: Localization (amcl)

### In your own words how amcl works?

monte carlo localization is some sort of particle filter. It calculate the distribution of likely state and the word *particle* is synonyms for likely state. It began with a normal distribution for all the states and as the robot moves the distribution becomes more inclined to a certain state/particle.

### Is there other better approaches to localize your robot rather than amcl?
apparently there is according to wikipedia, there is something called kullback-leibler divergence algorithm which is used in ROS.

### What are the amcl limitations or the fail cases?
I don't see much of limitations as it has a linear time complexity and the space is linear with number of particles.
### Is amcl used in domain rather than Robotics?
I couldn't find any source talks about that, but off the top of my head
---

## Part III: Navigation (move_base)

### How many official local planner available in ROS?

I didn't find explicit list of all the planners but I found 5 planners: base_local_planner, carrot_planner, dwa_local_planner, global_planner.

### which local planner did you use?

base_local_planner

### In your own words how the local planner you selected works?

given a plan to follow and a costmap, the controller produces velocity commands to send to a mobile base.

### How many official global planner available in ROS?
-
### which global planner did you use?
-
### In your own words how the global planner you selected works?
-

---

### State your suggestion increase the overall performance?
Increase the number of particles for sure, and increase the radius of laser scanning would provide us with better navigation.

### List the most time consuming problems you faced

setting up the libraries and packages.

---

### Demos
Add unlisted youtube/drive videos

# Watch here

[Demo](https://drive.google.com/file/d/1g6Cwmpl8VdmW3gKw7_6sB1sZ50o7HlBf/view?usp=sharing)

### Screenshots
1. rviz with all navigation launchers from turtulbot
2. gazebo

![image](yourscreenshot)

---

#### NAME:
#### ID:

---
