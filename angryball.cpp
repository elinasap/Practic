#include <iostream>
#include <math.h>

using namespace std;

const float g = 9.8;

struct Ball
{
	float h, v, a, t;
	Ball* next;
};

void init(Ball* head)
{
	head->h = 0;
	head->v = 0;
	head->a = 0;
	head->t = 0;
	head->next = NULL;
}

void WriteBall(Ball* tem, float h, float v, float a, float t) 
{
	Ball* c = tem;
	while (c->next != NULL)
	c = c->next;
	c->a = a;
	c->t = t;
	c->h = h;
	c->v = v;
	c->next = new Ball;
	init(c->next);
};

Ball* move(float h, float v, float dt) 
{
	Ball* output = new Ball;
	init(output);

	float a = g;
	float up, down, max_h;
	if (v > 0) // vverh
	{ 
		up = v / a;
		float dh = v * v / (2 * a);
		max_h = h + dh;
		down = sqrt(2 * max_h / a);

		WriteBall (output, h, v, -g, 0);
	}
	else // vniz
	{ 
		down = (-abs(v) + sqrt(v * v + 2 * a * h)) / a;
		max_h = h;
		up = 0;
		
		WriteBall(output, h, v, g, 0);
	}

	double vt = dt; // vverh za dt
	while (vt <= up) 
	{
		h = h+ v * dt - a * dt * dt / 2;
		v = v- a * dt;
		WriteBall(output, h, v, -g, vt);
		vt += dt;
	} 
	v = a * (vt - up);
	h = max_h - a * (vt - up) * (vt - up) / 2;
	WriteBall(output, h, -v, -g, vt);
	vt = vt+dt; // vniz za dt
	while (vt < up + down) 
	{
		h = h - v * dt + a * dt * dt / 2;
		v = v + a * dt;
		WriteBall(output, h, -v, -g, vt);
		vt = vt + dt;
	}
	WriteBall(output, 0, 0, 0, vt);
	return output;
};

void print(Ball* ball) 
{
	cout << "t =  /  h =  /  v =  / a =" << endl;

	Ball* cur = ball;
	while (cur->next != NULL ) 
	{
		cout << (float)cur->t << "\t" << cur->h << "\t" << cur->v << "\t" << cur->a << endl;
		cur = cur->next;
	}
};

void test() 
{
	Ball* a = new Ball;
	init(a);
	a->next = new Ball;
	init(a->next);
	if (a->next == 0 && a->next != NULL)
	if (a->next == 0 && a->next->next == NULL)
	return;
};

void testWriteBall() 
{
	Ball* a = new Ball;
	init(a);

	WriteBall(a, 1.2345, 1, 1, 0.000001);
	WriteBall(a->next, -1, 1000, -1.09876, 1);

	if (a->h == 1.2345 && a->t == 0.000001)
		if (a->next->a == -1.09876 && a->next->v == 1000)
			return;

	return;
};
int testMove()
{
	WriteBall* out = move(g, 2 * g, 1.0);

	if (out->h - g < 0.001 && out->a == -g && out->v == 2 * g && out->t == 0)	
	{
		out = out->next;
		if (out->h - 2.5 * g < 0.001 && out->a == -g && out->v == g && out->t == 1)	
		{
		out = out->next;
		if (out->h - 3.0 * g < 0.001 && out->a == -g && out->v == 0 && out->t == 2)	
		{
		out = out->next;
		if (out->h - 2.5 * g < 0.001 && out->a == -g && out->v == -g && out->t == 3)	
		{
		out = out->next;
		if (out->h - g < 0.001 && out->a == -g && out->v == -2 * g && out->t == 4)	
		{
		out = out->next;
		if (out->h == 0 && out->a == 0 && out->v == 0 && out->t == 5)	
		{
		return 1;
		}	}	}	}	}	}

	return 0;
}

void runTest(int (*testFunction)(), const string& testName) {
	if (testFunction() == true)
		std::cout << "Test " << testName << " - OK" << std::endl;
	else
		std::cout << "Test " << testName << " - FAIL" << std::endl;
}

int main() {
	runTest(test, "testInit");
	runTest(testWriteBall, "testPushData");
	runTest(testMove, "testMove");
}




