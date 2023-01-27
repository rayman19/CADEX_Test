#include "vector"
#include "algorithm"

#include "curves.h"


void fillCurves(std::vector<std::shared_ptr<Curve>> &curves, int count);
void printPointsAndDerive1FromCurves(std::vector<std::shared_ptr<Curve>>& curves);

void fillCurves(std::vector<std::shared_ptr<Circle>>& circles, int count);
void printPointsAndDerive1FromCurves(std::vector<std::shared_ptr<Circle>>& circles);

void copyCurvesOnlyCircle(std::vector<std::shared_ptr<Curve>>& curves, std::vector<std::shared_ptr<Circle>>& circles);