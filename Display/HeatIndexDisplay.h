#pragma once

#include "iDisplay.h"
#include "../ObserverPattern/iObserver.h"

class iSubject;

class HeatIndexDisplay : public iDisplay, iObserver
{
public:
  HeatIndexDisplay(iSubject* weatherData);
  virtual ~HeatIndexDisplay();

  void update(float temperature, float humidity, float pressure);
  void display();

private:
  double heatIndex;
  iSubject* weatherData;
};