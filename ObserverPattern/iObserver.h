#pragma once

class iObserver
{
public:
  virtual void update( float temp, float humidity, float pressure ) = 0;
};