/*
 * util.cpp
 *
 *  Created on: Sep 12, 2021
 *      Author: lupat
 */
#include <random>
#include <iostream>
#include <GL/glut.h>

using namespace std;

#ifndef UTILL_H_
#define UTIL_H_

#define PI 3.14159
float RNG_REAL(float lower, float upper);
float RNG_INT(int lower, int upper);
struct point
{
	float x, y;
	point(float xin, float yin)
	{
		x = xin;
		y = yin;
	}
	point()
	{
		x = 0;
		y = 0;
	}
	point operator+ (const point& p2) const
	{
		point res;
		res.x = x + p2.x;
		res.y = y + p2.y;
		return res;
	}
	point operator- (const point& p2) const
	{
		point res;
		res.x = x - p2.x;
		res.y = y - p2.y;
		return res;
	}
	friend ostream& operator<<(ostream& os, point &p)
	{
		os << "(" << p.x << ", " << p.y << ")";
		return os;
	}
};
point translate(point p, float deltax, float deltay);
point rotate(point p, float alpha);
point rotateWProc(point p1, point p2, float alpha);
point resize(point p1, point p2, float alpha);

vector<float> rotate_polygon(vector<float> positions, float alpha);
vector<float> get_polygon(int n_sides, float size, float anchorx, float anchory, float start_angle);
void draw_polygon(vector<float> positions);

float distance(float px1, float py1, float px2, float py2);

#endif
