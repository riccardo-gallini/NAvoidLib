
#include "point_wrap.h"

namespace NAvoid {

	Point::Point(double x, double y) {
		_X = x;
		_Y = y;
	}

	double Point::X() {
		return _X;
	}

	double Point::Y() {
		return _Y;
	}

	bool Point::Equals(Point^ other) {
		return ((this->_X == other->_X) && (this->_Y == other->_Y));
	}
	
}

