#pragma once

struct Point {
	Point(float x, float y)
		: x(x), y(y), z(0.0f) {};

	Point(float x, float y, float z)
		: x(x), y(y), z(z) {};

	float x, y, z;
};

struct Vector {
	Vector(float x, float y)
		: x(x), y(y), z(0.0f) {};

	Vector(float x, float y, float z)
		: x(x), y(y), z(z) {};

	float x, y, z;
};


class Curve {
public:
	Curve();
	virtual Point getPoint(float t) const = 0;
	virtual Vector getDerive1(float t) const = 0;
	virtual char getName() const = 0;
	virtual ~Curve();
};


class Circle : public Curve {
public:
	Circle(float _r);
	float getRadius() const;
	Point getPoint(float t) const override;
	Vector getDerive1(float t) const override;
	char getName() const override { return 'c'; }
private:
	float _r;
};


class Ellipse : public Curve {
public:
	Ellipse(float _a, float _b);
	float getAxesX() const;
	float getAxesY() const;
	Point getPoint(float t) const override;
	Vector getDerive1(float t) const override;
	char getName() const override { return 'e'; }
private:
	float _a, _b;
};


class Helix : public Curve {
public:
	Helix(float r, float step);
	float getRadius() const;
	float getStep() const;
	Point getPoint(float t) const override;
	Vector getDerive1(float t) const override;
	char getName() const override { return 'h'; }
private:
	float _r, _step;
};