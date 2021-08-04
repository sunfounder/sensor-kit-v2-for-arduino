#include "encoder.h"
/************************************************************
*Name: Init(int a, int b, int button)
*Function: Initialize,set the a pin as input,set the b pin as input
*Input: a,b,button
*Output: none
*************************************************************/
void ENCODER::Init(int a, int b, int button)
{
	pinMode(a, INPUT);
	pinMode(b, INPUT);
	pinMode(button, INPUT);
	digitalWrite(button, HIGH);
	_a = a;
	_b = b;
	_button = button;
}
/************************************************************
*Name: turnSettle()
*Function: Judging rotational direction of the rotary encoder,
*		   if clockwise ,return 1,if counterclockwise ,
*		   return -1
*Input: none
*Output: none
*************************************************************/
int ENCODER::turnSettle(void)
{
  static int oldA = HIGH;
  static int oldB = HIGH;
  int result = 0;
  int newA = digitalRead(_a);
  int newB = digitalRead(_b);
  if (newA != oldA || newB != oldB)
  {
    // something has changed
    if (oldA == HIGH && newA == LOW)
    {
      result = -(oldB * 2 - 1);
    }
  }
  oldA = newA;
  oldB = newB;
  return result;
}

int ENCODER::pressed(void)
{
	if(digitalRead(_button) == 0)
	{
		delay(10);
		if(digitalRead(_button) == 0)
		{
			return 1;
		}
	}
	else 
	{
		return 0;
	}
}