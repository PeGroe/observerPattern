#pragma once

#include "iDisplay.h"
#include "../ObserverPattern/iObserver.h"

class iSubject;

class CurrentConditionDisplay : public iDisplay, iObserver
{
public:
  CurrentConditionDisplay(iSubject* weatherData);
  virtual ~CurrentConditionDisplay();

  void update( float temperature, float humidity, float pressure );
  void display();

private:
  float temperature;
  float humidity;
  iSubject* weatherData;
};