#include "router_enums.h"
#include "checkpoint_wrap.h"

namespace NAvoid {

	CheckPoint::CheckPoint(double x, double y, Direction arrival_direction, Direction departure_direction) {
		_X = x;
		_Y = y;
		_arrivalDirection = arrival_direction;
		_departureDirection = departure_direction;
	}

	double CheckPoint::X() {
		return _X;
	}

	double CheckPoint::Y() {
		return _Y;
	}

	Direction CheckPoint::ArrivalDirection() {
		return _arrivalDirection;
	}

	Direction CheckPoint::DepartureDirection() {
		return _departureDirection;
	}

	bool CheckPoint::Equals(CheckPoint^ other) {
		return ((this->_X == other->_X) && 
				(this->_Y == other->_Y) &&
			    (this->_arrivalDirection == other->_arrivalDirection) && 
			    (this->_departureDirection == other->_departureDirection));
	}

	
}