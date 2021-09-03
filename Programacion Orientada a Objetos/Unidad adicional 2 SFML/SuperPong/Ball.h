#ifndef BALL_H
#define BALL_H
#include "Object.h"

class Ball : public Object {
public:
	Ball();
	void Update();
	void Bounce();
private:
	Vector2f m_speed = {6,3};
};

#endif

