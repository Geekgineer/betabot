# Betabot Obstacle avoider

- [Betabot Obstacle avoider](#betabot-obstacle-avoider)
  - [Project Description](#project-description)
  - [After you implement the pkg state your reflection below](#after-you-implement-the-pkg-state-your-reflection-below)
    - [How did you plan the task?](#how-did-you-plan-the-task)
    - [what is your logic?](#what-is-your-logic)
    - [What ROS REPs did you used?](#what-ros-reps-did-you-used)
    - [How we could increase the overall performance?](#how-we-could-increase-the-overall-performance)
    - [List the most time consuming problems you faced](#list-the-most-time-consuming-problems-you-faced)
    - [Demo](#demo)
    - [Screenshot](#screenshot)
      - [NAME:](#name)
      - [ID:](#id)

## Project Description 

Create a ROS package with custom nodes c++/python to move the
betabot randomly in gazebo, the movement should be triggered then the robot
moves randomly while avoid objects based on laser scans reading based on the laser
scans.


>NOTE: DON'T process one ray of the laser scans array or it will be considered ultrasonic/IR sensor.try to come up with approach thats use the laser full potential. 

>To make you project standout try not to visit any place twice.

---
## I have shown the code to the TA a lot of times but I lost it and couldn't replicate it again.


## After you implement the pkg state your reflection below

### How did you plan the task?
### what is your logic?
I intended to make the robot move in straight line and when the laser array values cross a certain threshold. I made the robot rotates for 90 degrees and read the laser 
array once again, if all the values above that threshold, *which is 2 meters*, the robot moves in a straight line. 



### What ROS REPs did you used?

I referred to REP 128/144, they are about naming convention. I didn't use anything else

### How we could increase the overall performance?

We could increase performance by getting a better laser reading, but I guess there is nothing to tune here to have a better readings.

### List the most time consuming problems you faced

The task seemed weird for me at first, and I took a bit of time to get the algorithm rolling, but other than that the assignment was adequate.

---

### Demo
Add unlisted youtube/drive video

[Demo](yourlinkhere)

### Screenshot

[image](yourscreenshot)

---

#### NAME: Omar Khaled
#### ID: 201600454

---
