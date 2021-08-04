//旋转编码器上拉接法
#ifndef __ENCODER_H__
#define __ENCODER_H__

#include <arduino.h>

class ENCODER
{
	public:
		void Init(int a, int b, int button);
		int turnSettle(void);
		int pressed(void);
	private:
		int _a;
		int _b;
		int _button;
		static int oldA;
		static int oldB;
		int newA;
		int newB;
		int result;
};

#endif