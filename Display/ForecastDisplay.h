#pragma once

#include "iDisplay.h"
#include "../ObserverPattern/iObserver.h"

class iSubject;

class ForecastDisplay : public iDisplay, iObserver
{
public:
  ForecastDisplay(iSubject* weatherData);
  virtual ~ForecastDisplay();

  void update(float temperature, float humidity, float pressure);
  void display();

private:
  float currentPressure;
  float lastPressure;
  iSubject* weatherData;
};