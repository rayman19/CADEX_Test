#include "vector"
#include "algorithm"
#include <iostream>

#include "tasks.h"
#include "curves.h"


constexpr int seedRadius = 100;
constexpr int seedStep = 10;
constexpr float PI_TASK = 3.1415926535f;


void fillCurves(std::vector<std::shared_ptr<Curve>> &curves, int count)
{
	for (int i = 0; i < count; i++)
	{
		switch (rand() % 3)
		{
		case 0:
			{ curves.emplace_back(std::make_shared<Circle>(rand() % seedRadius)); }
		case 1:
			{ curves.emplace_back(std::make_shared<Ellipse>(rand() % seedRadius, rand() % seedRadius)); }
		case 2:
			{ curves.emplace_back(std::make_shared<Helix>(rand() % seedRadius, rand() % seedStep)); }
		default:
			{ curves.emplace_back(std::make_shared<Circle>(rand() % seedRadius)); }
		}
	}
}

void printPointsAndDerive1FromCurves(std::vector<std::shared_ptr<Curve>>& curves)
{
	for (auto &curve : curves)
	{
		const Point p = curve->getPoint(PI_TASK / 4);
		const Vector v = curve->getDerive1(PI_TASK / 4);
		std::cout << "P(" << p.x << ", " << p.y << ", " << p.z << ") : V'(" <<
			v.x << ", " << v.y << ", " << v.z << ") : Fig = " << curve->getName() << '\n';
	}
	std::cout << std::endl;
}


void fillCurves(std::vector<std::shared_ptr<Circle>>& circles, int count)
{
	for (int i = 0; i < count; i++)
	{
		circles.emplace_back(std::make_shared<Circle>(rand() % seedRadius));
	}
}

void printPointsAndDerive1FromCurves(std::vector<std::shared_ptr<Circle>>& circles)
{
	for (auto& circle : circles)
	{
		const Point p = circle->getPoint(PI_TASK / 4);
		const Vector v = circle->getDerive1(PI_TASK / 4);
		std::cout << "P(" << p.x << ", " << p.y << ") : V'(" <<
			v.x << ", " << v.y << ") : Fig = " << circle->getName() << '\n';
	}
	std::cout << std::endl;
}


void copyCurvesOnlyCircle(std::vector<std::shared_ptr<Curve>>& curves, std::vector<std::shared_ptr<Circle>>& circles)
{
	for (auto &curve : curves) 
	{
		if (typeid(*curve) == typeid(Circle))
		{
			circles.emplace_back(std::dynamic_pointer_cast<Circle>(curve));
		}
	}
}