#include "stdafx.h"

#include <msclr\marshal_cppstd.h>

#include "libavoid/router.h"
#include "libavoid/shape.h"

#include "router_wrap.h"
#include "shaperef_wrap.h"
#include "connector_wrap.h"


namespace NAvoid
{

	Shape::Shape(NAvoid::Router^ router, System::String^ name, System::Collections::Generic::IList<NAvoid::Point^>^ poly)
	{
		Pins = gcnew System::Collections::Generic::Dictionary<System::String^, int>;
		_connectionPins_LastID = 0;
		_name = name;

		Avoid::Polygon shapePoly(poly->Count);

		int i = 0;

		for each(NAvoid::Point^ pt in poly) {
			shapePoly.ps[i] = Avoid::Point(pt->X(), pt->Y());
			i++;
		}

		_shapeRef = new Avoid::ShapeRef(router->_router, shapePoly);

	}
	
	Shape::~Shape() 
	{
	}
		
	System::String^ Shape::Name() 
	{
		return _name;
	}

	void Shape::AddPin(System::String ^name, double offset_x, double offset_y, NAvoid::Direction direction, bool exclusive, bool exclusive_by_orientation)
	{	

		int pin_id;

		if (this->Pins->ContainsKey(name))
		{
			pin_id = this->Pins[name];
		}
		else
		{
			this->_connectionPins_LastID++;
			pin_id = this->_connectionPins_LastID;
			this->Pins->Add(name, pin_id);
		}
		
		//always 'proportional' - inside_offset = 0
		Avoid::ShapeConnectionPin *pin = new Avoid::ShapeConnectionPin(
									 					this->_shapeRef, 
														pin_id, 
														offset_x, 
														offset_y, 
														true,
														0, 
														(Avoid::ConnDirFlag)direction
												);

		pin->setExclusive(exclusive);
		pin->setExclusiveByOrientation(exclusive_by_orientation);
			
		
	}

}

