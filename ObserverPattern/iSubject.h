#pragma once

class iObserver;

class iSubject
{
public:
  virtual void registerObserver( iObserver* o ) = 0;
  virtual void removeObserver( iObserver* o ) = 0;
  virtual void notifyObservers() = 0;
};