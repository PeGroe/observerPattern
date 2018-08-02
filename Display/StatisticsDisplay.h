#pragma once

#include "iDisplay.h"
#include "../ObserverPattern/iObserver.h"

class iSubject;

class StatisticsDsiplay : public iDisplay, iObserver
{
public:
  StatisticsDsiplay(iSubject* weatherData);
  virtual ~StatisticsDsiplay();

  void update(float temperature, float humidity, float pressure);
  void display();

private:
  float maxTemp;
  float minTemp;
  float tempSum;
  int numReadings;
  iSubject* weatherData;
};