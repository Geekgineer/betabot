# Betabot Moving in Square

- [Betabot Moving in Square](#betabot-moving-in-square)
  - [Project Description](#project-description)
  - [GUIDE](#guide)
  - [After you implement the pkg state your reflection below](#after-you-implement-the-pkg-state-your-reflection-below)
    - [How did you plan the task?](#how-did-you-plan-the-task)
    - [What ROS REPs did you used?](#what-ros-reps-did-you-used)
    - [How we could increase the overall performance?](#how-we-could-increase-the-overall-performance)
    - [List the most time consuming problems you faced](#list-the-most-time-consuming-problems-you-faced)
  - [Demo](#demo)
  - [Screenshot](#screenshot)
      - [NAME:](#name)
      - [ID:](#id)

## Project Description 

Create a ROS package with custom service/action c++/python to move the betabot in gazebo, the movement
triggered will have to be a square, like in the image below:
Betabot movement Use the data passed to this topic /move_betabot_in_square_custom to change the way
betabot moves. Depending on the side value, the service must move the robot in a square
movement based on the side given. Also, the robot must repeat the shape as many times as
indicated in the repetitions variable of the message. Finally, it must return True if everything
went OK in the success variable.


## GUIDE

1. Create a new launch file, called start_betabot_move_custom_service_server.launch,
that launches the new betabot_move_custom_service_server.py file.
2. Test that when calling this new /move_betabot_in_square_custom service, betabot
moves accordingly. This means, the square is performed taking into account the side
and repetitions variables.
3. Create a new service client that calls the service /move_betabot_in_square_custom,
and makes betabot moves in a small square twice and in a bigger square once.
It will be called betabot_move_custom_service_client.py. The launch that starts it will
be called call_betabot_move_in_square_custom_service_server.launch.
4. Refer to this tutorial for more help.
The BetabotCustomServiceMessage.srv will be something like this:

```sh
float64 side # The distance of each side of the square
int32 repetitions # The number of times the betabot robot has to execute the square
movement when the service is called
---
bool success # Did it achieve it?
```

>NOTE: The side variable doesn’t represent the real distance along each size of the square.It’s just a variable that will be used to change the size of the square. The bigger the size variable is, the bigger the square performed by the robot will be. You can use any robot pkg.

>To make you project standout try another shape and to use filtered `odemtry` data.

---
## I have shown you the code to the TA a lot of times but I lost it and couldn't replicate it again.

## After you implement the pkg state your reflection below

### How did you plan the task?

That assignment was rather interesting for me, I made a service that moves in any *polygon* with a certain side length; the service takes the number of sides of that polygon with a lower bound of 3 sides and in the ideal world, there are no upper bound.
</br>I also made a domain specific language for moving the robot with a very primitive lexer and parser and very simple grammer ```<command> <expression>``` and two commands which are ```move``` and ```rotate``` and expressions are supplied with the proper values and format. 


### What ROS REPs did you used?

I referred to REP 128/144, they are about naming convention


### How we could increase the overall performance?

The errors emanate from the IMU readings that decides when to stop and when to rotate and how much rotation in needed. It could be improved if we fused the sensor with kalman filter.

### List the most time consuming problems you faced

This task really wasn't very hard per se, but it was a very good first assignment. The most time consuming problems were that I was getting accustomed to the ROS framework.

---

## Demo
Add unlisted youtube/drive video

[Demo](yourlinkhere)

## Screenshot

[image](yourscreenshot)

---

#### NAME: Omar Khaled
#### ID: 201600454

---
