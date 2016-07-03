#pragma once

#include "router_enums.h"

namespace NAvoid {

	public ref class CheckPoint : public System::IEquatable<CheckPoint^>
	{

		private:
			double _X ;
			double _Y ;
			Direction _arrivalDirection;
			Direction _departureDirection;

		public:
		
			double X();
			double Y();
			Direction ArrivalDirection();
			Direction DepartureDirection();
			
			virtual bool Equals(CheckPoint ^other);

		internal:
		
			CheckPoint(double x, double y, Direction arrival_direction, Direction departure_direction);

	};
	
}
