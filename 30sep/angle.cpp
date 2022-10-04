#include <iostream>
#include <cmath>

const float ANGLE_PER_MIN = 6.0;
const float ANGLE_PER_HOUR = 30.0;

const float HOURS_IN_CLOCK = 12.0;
const float MINUTES_IN_CLOCK = 60.0;

int main()
{
  float hours, minutes;

  std::cin >> hours >> minutes;

  hours = (int)hours % (int)HOURS_IN_CLOCK;

  minutes = (int)minutes % (int)MINUTES_IN_CLOCK;

  hours += minutes / MINUTES_IN_CLOCK;

  float minute_angle = minutes * ANGLE_PER_MIN;

  float hour_angle = hours * ANGLE_PER_HOUR;

  float m = minute_angle - hour_angle;

  float d = (180.0 - fabs(180.0 - m));

  std::cout << d;
}