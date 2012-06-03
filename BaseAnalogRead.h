//
//  BaseAnalogRead.h
//  Sun Tracker
//
//  Created by 治永夢守 on 12/06/03.
//  Copyright 2012 James Knowles. All rights reserved.
//
// This work is licensed under a Creative Commons 
// Attribution-ShareAlike 3.0 Unported License.
//
// https://creativecommons.org/licenses/by-sa/3.0/
//
//
//

#ifndef BASE_ANALOG_READ_H
#define BASE_ANALOG_READ_H

#include "Arduino.h"

//
// SUMMARY
//
// This class simply reads a sensor and holds the value. 
//
// PURPOSE
//
// It is intended to be the base class for more sophisticated
// types of input handling. 
//
// USE
//
// Set the pin number in the constructor, or with the setPinNumber() method.
// Call the Read() method.
//
// The last value is held in Reading.
// 
// EXAMPLE
//
//


class BaseAnalogRead 
{
  public:
    BaseAnalogRead(const byte aPinNumber=0);
    virtual ~BaseAnalogRead();

    //
    // Contains the latest reading from the sensor. 
    //
    int Reading;


    //
    // Returns the analogue pin number this instance reads.
    //
    byte PinNumber();

    //
    // Obtain the current sensor reading. 
    //
    virtual int Read();

    //
    // Sets the analogue pin number this instance reads.
    //
    void setPinNumber(const byte aPinNumber);

  protected:
    // Analogue pin number to read.
    byte _Pin;

};

#endif // BASE_ANALOG_READ_H

