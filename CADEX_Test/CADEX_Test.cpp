#include <iostream>
#include <vector>
#include <algorithm>

#include <omp.h>
#include "curves.h"
#include "tasks.h"


int main()
{
	// Fill Container1
	std::vector<std::shared_ptr<Curve>> curves;
	fillCurves(curves, 10);
	// Print Points and Derive1 in Curves from Container1
	printPointsAndDerive1FromCurves(curves);

	// Copy from Container1 in Container2 only Circle
	std::vector<std::shared_ptr<Circle>> circles;
	copyCurvesOnlyCircle(curves, circles);
	printPointsAndDerive1FromCurves(circles);

	// Sort Container2
	std::sort(std::begin(circles), std::end(circles),
		[](const auto& left, const auto& right)
		{ return left->getRadius() < right->getRadius(); });
	// Print Sorted Container2
	printPointsAndDerive1FromCurves(circles);

	// Summer Container2 on Radius for support OpenMP
	float sumCirclesByRadius = 0.0f;

	# pragma omp parallel shared(circles) reduction (+: sumCirclesByRadius) num_threads(6)
	{
		# pragma omp for
		for (int i = 0; i < circles.size(); i++)
		{
			sumCirclesByRadius += circles[i].get()->getRadius();
		}
	}
	
	std::cout << sumCirclesByRadius << std::endl;
}