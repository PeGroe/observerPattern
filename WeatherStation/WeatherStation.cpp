// WeatherStation.cpp : Defines the entry point for the console application.
//

#include "WeatherData.h"
#include "../Display/CurrentConditionDisplay.h"
#include "../Display/StatisticsDisplay.h"
#include "../Display/ForecastDisplay.h"
#include "../Display/HeatIndexDisplay.h"

int main()
{
  WeatherData* weatherData = new WeatherData();
  CurrentConditionDisplay* currentDisplay = new CurrentConditionDisplay(weatherData);
  StatisticsDsiplay* statisticsDisplay = new StatisticsDsiplay(weatherData);
  ForecastDisplay* forecastDisplay = new ForecastDisplay(weatherData);
  HeatIndexDisplay* heatIndexDisplay = new HeatIndexDisplay(weatherData);

  weatherData->setMeasurements(80.0f, 65.0f, 30.4f);
  weatherData->setMeasurements(82.0f, 70.0f, 29.2f);
  weatherData->setMeasurements(78.0f, 90.0f, 29.2f);

  return 0;
}