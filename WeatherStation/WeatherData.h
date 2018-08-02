#pragma once

#include "../ObserverPattern/iSubject.h"
#include <vector>

class WeatherData : public iSubject
{
public:
  WeatherData();
  virtual ~WeatherData();

  void registerObserver( iObserver* o ) override;
  void removeObserver( iObserver* o ) override;
  void notifyObservers() override;

  void measurementsChanged();
  void setMeasurements(float temperature, float humidity, float pressure);

private:
  std::vector<iObserver*> observers;
  float temperature;
  float humidity;
  float pressure;
};