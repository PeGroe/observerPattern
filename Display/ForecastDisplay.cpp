#include "ForecastDisplay.h"
#include "../ObserverPattern/iSubject.h"
#include <iostream>

ForecastDisplay::ForecastDisplay(iSubject * weatherData)
{
  this->weatherData = weatherData;
  weatherData->registerObserver(this);

  currentPressure = 29.92f;
}

ForecastDisplay::~ForecastDisplay()
{
}

void ForecastDisplay::update(float temperature, float humidity, float pressure)
{
  lastPressure = currentPressure;
  currentPressure = pressure;

  display();
}

void ForecastDisplay::display()
{
  std::cout << "Forecast: ";
  if (currentPressure > lastPressure)
  {
    std::cout << "Improving weather on the way!" << std::endl;
  }
  else if (currentPressure == lastPressure)
  {
    std::cout << "More of the same." << std::endl;
  }
  else if (currentPressure < lastPressure)
  {
    std::cout << "Watch out for cooler, rainy weather." << std::endl;
  }
}
