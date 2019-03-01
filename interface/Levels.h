#ifndef LEVELS_H
#define LEVELS_H

enum ThreeScale
{
  LOW = 0,
  MEDIUM = 1,
  HIGH = 2,
  UNDF = -1
};

enum FiveScale
{
  VERYLOW = 0,
  LOW = 1,
  MEDIUM = 2,
  HIGH = 3,
  VERY HIGH = 4,
  UNDF = -1
};

inline ThreeScale toThreeScale(int i) const
{
  ThreeScale ts;

  switch(i)
  {
    case 0 :  ts = ThreeScale::LOW;
              break;
    case 1 :  ts = ThreeScale::MEDIUM;
              break;
    case 2 :  ts = ThreeScale::HIGH;
              break;
    default : ts = ThreeScale::UNDF;
              break;
  }

  return ts;
};

inline FiveScale toFiveScale(int i) const
{
  FiveScale fs;

  switch(i)
  {
    case 0 :  fs = FiveScale::VERYLOW;
              break;
    case 1 :  fs = FiveScale::LOW;
              break;
    case 2 :  fs = FiveScale::MEDIUM;
              break;
    case 3 :  fs = FiveScale::HIGH;
              break;
    case 4 :  fs = FiveScale::VERYHIGH;
              break;
    default : fs = FiveScale::UNDF;
              break;
  }

  return fs;
};

#endif
