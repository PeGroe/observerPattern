#include "CurrentConditionDisplay.h"
#include "../ObserverPattern/iSubject.h"
#include <iostream>
#include <iomanip>

CurrentConditionDisplay::CurrentConditionDisplay(iSubject * weatherData)
{
  this->weatherData = weatherData;
  weatherData->registerObserver(this);
}

CurrentConditionDisplay::~CurrentConditionDisplay()
{
}

void CurrentConditionDisplay::update(float temperature, float humidity, float pressure)
{
  this->temperature = temperature;
  this->humidity    = humidity;
  display();
}

void CurrentConditionDisplay::display()
{
  std::cout << std::fixed << std::setprecision(1) << "Current conditions: " << temperature << "F degrees and " << humidity << "% humidity" << std::endl;
}
