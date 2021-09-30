/*
 * util.cpp
 *
 *  Created on: Sep 12, 2021
 *      Author: lupat
 */

#include "util.h"


float RNG_REAL(float lower, float upper)
{
    std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distrib(lower, upper);

    return distrib(gen);
}
float RNG_INT(int lower, int upper)
{
    std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(lower, upper);

    return distrib(gen);
}

point translate(point p, float deltax, float deltay)
{
	point result(deltax, deltay);
	result = p + result;
	return result;
}
point rotateWProc(point p1, point p2, float alpha)
{
	point result = translate(p2, -p1.x, -p1.y);
	result = rotate(result, alpha);
	result = translate(result, p1.x, p1.y);
	return result;
}
point rotate(point p, float alpha)
{
	float degree = alpha * PI / 180.0;
	float newx = p.x * cos(degree) - p.y * sin(degree);
	float newy = p.x * sin(degree) + p.y * cos(degree);
	point result (newx, newy);
	return result;
}

point resize(point p1, point p2, float alpha)
{
	float newx = p1.x + alpha * (p2.x - p1.x);
	float newy = p1.y + alpha * (p2.y - p1.x);
	point result (newx, newy);
	return result;
}

vector<float> rotate_polygon(vector<float> positions, float alpha)
{
	vector<float> results;
	int it = positions.size();
	for(int i = 0; i < it; i+=2)
	{
		point p1(positions[i], positions[i+1]), p2(positions[(i+2)%it], positions[(i+3)%it]);
		point newp1 = resize(p1, p2, alpha);
		results.push_back(newp1.x);
		results.push_back(newp1.y);
	}
	return results;
}
vector<float> get_polygon(int n_sides, float size, float anchorx, float anchory, float start_angle)
{
	vector<float> positions;
	float degrees = 360 / n_sides;
	float curr_deg = start_angle;
	for(int i = 0; i<n_sides; i++)
	{
		float newx = anchorx + size * cos(curr_deg * PI / 180.0);
		float newy = anchory + size * sin(curr_deg * PI / 180.0);
		positions.push_back(newx);
		positions.push_back(newy);
		curr_deg += degrees;
	}
	return positions;
}
void draw_polygon(vector<float> positions)
{
	int lines = positions.size();
	for(int i=0; i <lines; i+=2)
	{
		glBegin(GL_LINES);
			glVertex2f(positions[i], positions[i+1]);
			glVertex2f(positions[(i+2)%lines], positions[(i+3)%lines]);
		glEnd();
	}
}
float distance(float px1, float py1, float px2, float py2)
{
	float deltax = pow(px2-px1, 2);
	float deltay = pow(py2-py1, 2);
	return sqrt(deltax+ deltay);
}

