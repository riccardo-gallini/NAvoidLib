#pragma once

#include "libavoid/router.h"
#include "libavoid/shape.h"

#include "router_wrap.h"

namespace NAvoid {

	ref class Router;
	ref class Connector;

	public ref class Shape
	{
			
		public:
						
			void AddPin(System::String ^name, double offset_x, double offset_y, Direction direction, bool exclusive, bool exclusive_by_orientation);
			System::Collections::Generic::Dictionary<System::String^, int>^ Pins;

			System::String^ Name();

		internal:
			Shape(NAvoid::Router^ router, System::String^ name, System::Collections::Generic::IList<NAvoid::Point^>^ poly);
			~Shape();

			Avoid::ShapeRef* _shapeRef;

		private:
			int _connectionPins_LastID;
			System::String^ _name;

	};
		
}

