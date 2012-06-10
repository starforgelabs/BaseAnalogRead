#include <ArduinoUnit.h>
#include <BaseAnalogRead.h>

TestSuite suite;

BaseAnalogRead tester;

test(read)
{
  for(int i=0; i<1024; i++)
  {
    tester.Reading = i;
    int val = tester.Read();
    assertEquals(i, val);
    assertEquals(i, tester.Reading);
  }
}

void setup()
{
  tester.Enabled = false;
}

void loop()
{
  suite.run();
}
