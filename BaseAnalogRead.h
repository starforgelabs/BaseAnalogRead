//
//  BaseAnalogRead.h
//
//  Created by 治永夢守 on 12/06/03.
//  Copyright 2012 James Knowles. All rights reserved.
//
// This work is licensed under a Creative Commons 
// Attribution-ShareAlike 3.0 Unported License.
//
// https://creativecommons.org/licenses/by-sa/3.0/
//
// This code is strictly "as is". Use at your own risk. 
//
//
//

#ifndef BASE_ANALOG_READ_H
#define BASE_ANALOG_READ_H

#include "Arduino.h"

/*

SUMMARY

analogRead() wrapped in a simple class

PURPOSE

This is intended to be the base class for more sophisticated
types of input handling. 

DESCRIPTION

BaseAnalogRead is designed to be the foundation for various types of "fancy" 
data input, such as moving averages or statistical treatments of incoming data.

MEMBERS

bool IsEnabled 

  The IsEnabled field will enable or disable calls to analogRead().

int Value

  The Value field holds the last read value. It may be written to, but 
  the next call to Read() will alter it if the IsEnabled field is true.
  
  Note: Descendents alter this according to their algorithms. 

byte PinNumber()

  The PinNumber method returns the Arduino analogue pin number to read. 

int Read()

  The Read method updates the Value field according to these rules.

  1) If IsEnabled is false, nothing should change. The class is disabled.
     * Descendents should honour this.

  2) The Value field will be set to the value returned by analogRead 
     (if IsTesting is false) or TestValue (if IsTesting is true).
     * Descendents should alter the Value field according to 
       their algorithms. 

  The return value is identical to the value in Value.

int Read(const int aValue)

  This Read method is used to simulate a call to Read() with a specific value. 

  It is intended for testing and other purposes that require a specific value 
  to be obtained. 

void setPinNumber(const byte aPinNumber)

  The setPinNumber method changes the pin that analogRead accesses.

USE

Typical use follows this pattern. 

1) Set the pin number in the constructor, or with the setPinNumber() method.
2) Call the Read() method.

EXAMPLE

BaseAnalogRead sensor(3);
...
int value = sensor.Read(); // reads analogue pin 3

EXAMPLE

BaseAnalogRead sensor();
...
sensor.setPinNumber(3);
sensor.Read();
int value = sensor.Value;

*/


class BaseAnalogRead 
{
  public:
    BaseAnalogRead(const byte aPinNumber=0);

    // Set this to false to disable the actual call to analogRead().
    bool IsEnabled;

    // Returns the analogue pin number this instance reads.
    byte PinNumber() { return _Pin; }

    //
    // Update the Value field with the current analogue pin reading. 
    //
    // Value is also returned for convenience.
    //
    virtual int Read();

    //
    // Fake a call to analogRead(). This allows for testing, &c.
    //
    // aValue - the value to use instead of analogRead()
    //
    int Read(const int aValue);


    // Sets the analogue pin number to read.
    void setPinNumber(const byte aPinNumber) { _Pin = aPinNumber; }

    // Contains the latest reading from the sensor. 
    int Value;

  protected:
    // Analogue pin number to read.
    byte _Pin;

  private:
    // Treat this as a boolean to indicate whether we're in testing mode,
    // i.e. we're faking a call to analogRead().
    //
    // Note that this is not strictly a counting semaphore, but I don't want to 
    // worry about this being a shared resource. 
    unsigned int IsTesting;
    int TestValue;
};

#endif // BASE_ANALOG_READ_H

