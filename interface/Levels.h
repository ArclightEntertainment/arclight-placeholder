#ifndef LEVELS_H
#define LEVELS_H

enum ThreeScale
{
  LOW = 0,
  MEDIUM = 1,
  HIGH = 2,
  UNDFTS = -1
};

enum FiveScale
{
  VERYLOW = 0,
  MIDLOW = 1,
  MID = 2,
  MIDHIGH = 3,
  VERYHIGH = 4,
  UNDFFS = -1
};

inline ThreeScale toThreeScale(int i)
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
    default : ts = ThreeScale::UNDFTS;
              break;
  }

  return ts;
};

inline FiveScale toFiveScale(int i)
{
  FiveScale fs;

  switch(i)
  {
    case 0 :  fs = FiveScale::VERYLOW;
              break;
    case 1 :  fs = FiveScale::MIDLOW;
              break;
    case 2 :  fs = FiveScale::MID;
              break;
    case 3 :  fs = FiveScale::MIDHIGH;
              break;
    case 4 :  fs = FiveScale::VERYHIGH;
              break;
    default : fs = FiveScale::UNDFFS;
              break;
  }

  return fs;
};

#endif
