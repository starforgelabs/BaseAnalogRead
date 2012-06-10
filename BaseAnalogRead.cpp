/*
 *  BaseAnalogRead.cpp
 *  Sun Tracker
 *
 *  Created by 治永夢守 on 12/05/27.
 *  Copyright 2012 James Knowles. All rights reserved.
 *
 * This work is licensed under a Creative Commons 
 * Attribution-ShareAlike 3.0 Unported License.
 *
 * https://creativecommons.org/licenses/by-sa/3.0/
 *
 *
 */

#include "BaseAnalogRead.h"

BaseAnalogRead::BaseAnalogRead(const byte aPinNumber) 
{ 
  _Pin = aPinNumber; 
  Enabled = true;
}

int BaseAnalogRead::Read()
{
  if(Enabled)
    Reading = analogRead(_Pin);

  return Reading;
}

