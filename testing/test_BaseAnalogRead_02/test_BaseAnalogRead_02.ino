#include <ArduinoUnit.h>
#include <BaseAnalogRead.h>

TestSuite suite;

BaseAnalogRead tester;

test(read)
{
  tester.IsEnabled = true;

  for(int i=0; i<1024; i++)
  {
    int val = tester.Read(i);
    assertEquals(i, val);
    assertEquals(i, tester.Value);
  }
}

test(is_enabled)
{
  tester.IsEnabled = true;
  tester.Read(0);
  tester.IsEnabled = false;

  for(int i=0; i<1024; i++)
  {
    int val = tester.Read(i);
    assertEquals(0, val);
    assertEquals(0, tester.Value);
  }
}

void setup()
{
}

void loop()
{
  suite.run();
}
