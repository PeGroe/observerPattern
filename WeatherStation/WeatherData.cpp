#include "WeatherData.h"
#include <algorithm>
#include "../ObserverPattern/iObserver.h"

WeatherData::WeatherData()
{
}

WeatherData::~WeatherData()
{
  observers.clear();
}

void WeatherData::registerObserver(iObserver * o)
{
  if (o)
  {
    observers.push_back(o);
  }
}

void WeatherData::removeObserver(iObserver * o)
{
  if (o)
  {
    std::vector<iObserver*>::iterator it;
    it = std::find(observers.begin(), observers.end(), o);

    if ( it != observers.end() )
    {
      observers.erase(it);
    }
  }
}

void WeatherData::notifyObservers()
{
  for (auto& elem : observers)
  {
    elem->update(temperature, humidity, pressure);
  }
}

void WeatherData::measurementsChanged()
{
  notifyObservers();
}

void WeatherData::setMeasurements(float temperature, float humidity, float pressure)
{
  this->temperature = temperature;
  this->humidity    = humidity;
  this->pressure    = pressure;
  measurementsChanged();
}
