#include "StatisticsDisplay.h"
#include "../ObserverPattern/iSubject.h"
#include <iostream>
#include <iomanip>

StatisticsDsiplay::StatisticsDsiplay(iSubject * weatherData)
{
  this->weatherData = weatherData;
  weatherData->registerObserver(this);

  minTemp = 200.0f;
}

StatisticsDsiplay::~StatisticsDsiplay()
{
}

void StatisticsDsiplay::update(float temperature, float humidity, float pressure)
{
  tempSum += temperature;
  numReadings++;

  if (temperature > maxTemp)
  {
    maxTemp = temperature;
  }
  
  if (temperature < minTemp)
  {
    minTemp = temperature;
  }

  display();
}

void StatisticsDsiplay::display()
{
  std::cout << std::fixed << std::setprecision(1) << "Avg/Max/Min temperature = " << (tempSum / numReadings) << "/" << maxTemp << "/" << minTemp << std::endl;
}
