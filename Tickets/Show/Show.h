#pragma once

#include <iostream>
class Show{
private:
  char *name;
public:
  Show();
  ~Show();
  
  void setName(const char* name);

  char* getName() const;
};