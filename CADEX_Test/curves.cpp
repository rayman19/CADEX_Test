#include <cmath>

#include "curves.h"


constexpr float PI = 3.1415926535f;


// Circle
Circle::Circle(float r)
	: _r(r) {}

float Circle::getRadius() const { return _r; }

Point Circle::getPoint(float t) const
{
	return Point { getRadius() * cos(t), getRadius() * sin(t) };
}

Vector Circle::getDerive1(float t) const
{
	return Vector { -1 * getRadius() * sin(t), getRadius() * cos(t) };
}


// Ellise
Ellipse::Ellipse(float a, float b)
	: _a(a), _b(b) {}

float Ellipse::getAxesX() const { return _a; }

float Ellipse::getAxesY() const { return _b; }

Point Ellipse::getPoint(float t) const
{
	return Point { getAxesX() * cos(t), getAxesY() * sin(t) };
}

Vector Ellipse::getDerive1(float t) const
{
	return Vector{ -1 * getAxesX() * sin(t), getAxesY() * cos(t) };
}


// Helix
Helix::Helix(float r, float step)
	: _r(r), _step(step) {}

float Helix::getRadius() const { return _r; }

float Helix::getStep() const { return _step; }

Point Helix::getPoint(float t) const
{
	return Point { getRadius() * cos(t), getRadius() * sin(t), getStep() * t };
}

Vector Helix::getDerive1(float t) const
{
	return Vector { -1 * getRadius() * sin(t), getRadius() * cos(t), getStep() };
}


// Curve
Curve::Curve() = default;
Curve::~Curve() {};