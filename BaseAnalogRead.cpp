/*
 *  BaseAnalogRead.cpp
 *
 *  Created by 治永夢守 on 12/05/27.
 *  Copyright 2012 James Knowles. All rights reserved.
 *
 * This work is licensed under a Creative Commons 
 * Attribution-ShareAlike 3.0 Unported License.
 *
 * https://creativecommons.org/licenses/by-sa/3.0/
 *
 * This code is strictly "as is". Use at your own risk. 
 *
 *
 */

#include "BaseAnalogRead.h"

BaseAnalogRead::BaseAnalogRead(const byte aPinNumber) 
{ 
  _Pin = aPinNumber; 
  IsEnabled = true;
  IsTesting = 0;
}

int BaseAnalogRead::Read()
{
  if(IsEnabled)
    Value = IsTesting ? TestValue : analogRead(_Pin);

  return Value;
}

int BaseAnalogRead::Read(const int aValue)
{
  IsTesting++;

  TestValue = aValue;
  Read();

  IsTesting--;
    
  return Value;
}

