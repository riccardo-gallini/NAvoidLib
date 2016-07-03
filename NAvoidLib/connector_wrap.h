#pragma once

#include "libavoid/router.h"
#include "libavoid/shape.h"
#include "libavoid/connector.h"

#include "router_enums.h"
#include "point_wrap.h"
#include "checkpoint_wrap.h"


namespace NAvoid {

	ref class Router;

	public ref class Connector
	{

		public:
				
			bool NeedsRepaint();
			void PaintComplete();
		
			void SetRoutingType(RoutingTypes routingType);
			RoutingTypes GetRoutingType();

			System::String^ Name();

			System::Collections::Generic::IList<Point^>^ DisplayRoute();

			void AddCheckPoint(double x, double y, Direction arrival_direction, Direction departure_direction);
			void AddCheckPoint(double x, double y);
			void ClearCheckPoints();

			
		
			void SetFixedExistingRoute();

			bool HasFixedRoute();
			void ClearFixedRoute();
		
		private:
			System::String^ _name;

		internal:

			Avoid::ConnRef *_connRef;

			Connector(System::String^ name, Router^ router, Shape^ from_shape, System::String^ from_pin, Shape^ to_shape, System::String^ to_pin);
			virtual ~Connector();

			void setRoutingCheckPoints();

			NAvoid::Router^ internal_router;

			System::Collections::Generic::IList<NAvoid::CheckPoint^>^ _pendingCheckPoints;

	};
	
}
