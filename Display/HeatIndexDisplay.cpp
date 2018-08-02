#include "HeatIndexDisplay.h"
#include "../ObserverPattern/iSubject.h"
#include <iostream>
#include <iomanip>

HeatIndexDisplay::HeatIndexDisplay(iSubject * weatherData)
{
  this->weatherData = weatherData;
  weatherData->registerObserver(this);
}

HeatIndexDisplay::~HeatIndexDisplay()
{
}

void HeatIndexDisplay::update(float temperature, float humidity, float pressure)
{
  this->heatIndex = (16.923 + (0.185212 * temperature)) +
                    (5.37941 * humidity) -
                    (0.100254 * temperature * humidity) +
                    (0.00941695 * (temperature * temperature)) +
                    (0.00728898 * (humidity * humidity)) +
                    (0.000345372 * (temperature * temperature * humidity)) -
                    (0.000814971 * (temperature * humidity * humidity)) +
                    (0.0000102102 * (temperature * temperature * humidity * humidity)) -
                    (0.000038646 * (temperature * temperature * temperature)) +
                    (0.0000291583 * (humidity * humidity * humidity)) +
                    (0.00000142721 * (temperature * temperature * temperature * humidity)) +
                    (0.000000197483 * (temperature * humidity * humidity * humidity)) -
                    (0.0000000218429 * (temperature * temperature * temperature * humidity * humidity)) +
                    (0.000000000843296 * (temperature * temperature * humidity * humidity * humidity)) -
                    (0.0000000000481975 * (temperature * temperature * temperature * humidity * humidity * humidity));

  display();
}

void HeatIndexDisplay::display()
{
  std::cout << std::fixed << std::setprecision(5) << "Heat index is " << heatIndex << std::endl;
}
