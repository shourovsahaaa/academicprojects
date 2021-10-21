#include "Motorcycle.hpp"
#include <iostream>
#include <ctime>
#include <random>
#include <math.h>
using namespace std;

Motorcycle::Motorcycle()
{
  srand((int)time(0));
  int r = (rand() % 4); // Random Int  from [ 0, 1, 2, 3 ]

  if (r == 0) 
  {
    brand_ = bike_details::YAMAHA;
  }
  else if (r == 1) 
  {
    brand_ = bike_details::DUCATI;
  }
  else if (r == 2) 
  {
    brand_ = bike_details::HARLEY_DAVIDSON;
  }
  else 
  {
    brand_ = bike_details::KAWASAKI;
  }

    curr_acceleration_ = bike_details::NONE;
}

Motorcycle::Motorcycle(int kind_of_bike)
{
  int r = kind_of_bike;

  if (r == 0) 
  {
    brand_ = bike_details::YAMAHA;
  }
  else if (r == 1) 
  {
    brand_ = bike_details::DUCATI;
  }
  else if (r == 2) 
  {
    brand_ = bike_details::HARLEY_DAVIDSON;
  }
  else 
  {
    brand_ = bike_details::KAWASAKI;
  }

  curr_acceleration_ = bike_details::NONE;
}

float Motorcycle::ride(float duration) 
{
  if (static_cast<int>(duration) < 0)
  {
    return static_cast<int>(distance_traveled_);
  }
  distance_traveled_ += (static_cast<int>(curr_speed_) * static_cast<int>(duration));
  return static_cast<int>(static_cast<int>(curr_speed_) * static_cast<int>(duration));
}

void Motorcycle::updateSpeed() 
{
curr_speed_ = (double)(curr_acceleration_ / 8) + (brand_ * 17.64);
}

void Motorcycle::accelerate() 
{
  if (curr_acceleration_ == bike_details::NONE)
  {
    curr_acceleration_ = bike_details::LOW;
  }
  else if (curr_acceleration_ == bike_details::LOW)
  {
    curr_acceleration_ = bike_details::MEDIUM;
  }
  else if (curr_acceleration_ == bike_details::MEDIUM)
  {
    curr_acceleration_ = bike_details::HIGH;
  }

  updateSpeed();

}

void Motorcycle::brake() 
{
  if (curr_acceleration_ == bike_details::HIGH) 
  {
    curr_acceleration_ = bike_details::MEDIUM;
  }
  else if (curr_acceleration_ == bike_details::MEDIUM) 
  {
    curr_acceleration_ = bike_details::LOW;
  }
  else if (curr_acceleration_ == bike_details::LOW) 
  {
    curr_acceleration_ = bike_details::NONE;
  }

  updateSpeed();
}

void Motorcycle::turn(float degrees) 
{
  curr_direction_ += degrees;
  while (curr_direction_ > 360) 
  {
    curr_direction_ = curr_direction_ - 360;
  }
  while (curr_direction_ < 0) 
  {
    curr_direction_ = curr_direction_ + 360;
  }
}

 string Motorcycle::getDirection() 
 {
  if (static_cast<int>(curr_direction_) > 359 or static_cast<int>(curr_direction_) < 0)
  {
    return "Out of bounds";
  }
  if (static_cast<int>(curr_direction_) > 270 && static_cast<int>(curr_direction_) < 360) 
  {
    return "Southeast";
  }
  if (static_cast<int>(curr_direction_) == 270) 
  {
    return "South";
  }
  if (static_cast<int>(curr_direction_) > 180 && static_cast<int>(curr_direction_) < 270) 
  {
  return "Southwest";
  }
  if (static_cast<int>(curr_direction_)== 180) 
  {
    return "West";
  }
  if (static_cast<int>(curr_direction_) > 90 && static_cast<int>(curr_direction_) < 180) 
  {
    return "Northwest";
  }
  if (static_cast<int>(curr_direction_) == 90) 
  {
    return "North";
  }
  if (static_cast<int>(curr_direction_) > 0 && static_cast<int>(curr_direction_) < 90)
  {
    return "Northeast";
  }
  if (static_cast<int>(curr_direction_) == 0)
  {
    return "East";
  }
  else
  {
    return "Error";
  }
}


string Motorcycle::getBikeType() 
{
  if (brand_ == bike_details::YAMAHA) 
  {
    return "YAMAHA";
  }
  else if (brand_ == bike_details::DUCATI) 
  {
    return "DUCATI";
  }
  else if (brand_ == bike_details::HARLEY_DAVIDSON) 
  {
    return "HARLEY_DAVIDSON";
  }
  else if (brand_ == bike_details::KAWASAKI) 
  {
    return "KAWASAKI";
  }
  else
  {
    return "UNREGISTERED BRAND! CALL THE COPS!";
  }
}

/* Getter: curr_speed_ */
float Motorcycle::getSpeed() 
{
  if (curr_speed_ < 0.50)
  {
    return 0;
  }
  return curr_speed_;
}

/* Getter: distance_traveled_ */
float Motorcycle::getDistanceTraveled() 
{
  return static_cast<int>(distance_traveled_);
}

/* Getter: curr_acceleration_ */
int Motorcycle::getIntensity() 
{
  return curr_acceleration_;
}
