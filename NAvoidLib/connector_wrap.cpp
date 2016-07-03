
#include "router_enums.h"
#include "router_wrap.h"
#include "shaperef_wrap.h"
#include "connector_wrap.h"

namespace NAvoid {
	
	Connector::Connector(System::String^ name, Router^ router, Shape^ from_shape, System::String^ from_pin, Shape^ to_shape, System::String^ to_pin) {
		internal_router = router;
		_name = name;

		const unsigned int _src_pin = from_shape->Pins[from_pin];
		Avoid::ConnEnd src = Avoid::ConnEnd(from_shape->_shapeRef, _src_pin);
		src.SetOrientation(Avoid::ConnEndOrientation::ConnEndSource);
				
		const unsigned int _dst_pin = to_shape->Pins[to_pin];
		Avoid::ConnEnd dst = Avoid::ConnEnd(to_shape->_shapeRef, _dst_pin);
		dst.SetOrientation(Avoid::ConnEndOrientation::ConnEndTarget);

		_connRef = new Avoid::ConnRef(router->_router);
		_connRef->setSourceEndpoint(src);
		_connRef->setDestEndpoint(dst);
		_connRef->setRoutingType(Avoid::ConnType::ConnType_Orthogonal);
				
		_pendingCheckPoints = gcnew System::Collections::Generic::List<NAvoid::CheckPoint^>();
	}
		
	Connector::~Connector() {
	}

	System::String^ Connector::Name() {
		return _name;
	}

	bool Connector::NeedsRepaint() {
		return _connRef->needsRepaint();
	}

	void Connector::PaintComplete() {
		_connRef->paintComplete();
	}

	void Connector::SetRoutingType(RoutingTypes routingType) {
		_connRef->setRoutingType((Avoid::ConnType) routingType);
	}
	
	RoutingTypes Connector::GetRoutingType() {
		return (RoutingTypes) (_connRef->routingType());
	}

	System::Collections::Generic::IList<Point^>^ Connector::DisplayRoute() {
		
		System::Collections::Generic::IList<Point^>^ poly = gcnew System::Collections::Generic::List<Point^>;
		Avoid::PolyLine route = _connRef->displayRoute();

		for (size_t i = 0; i < route.size(); ++i) {
			Avoid::Point pt = route.at(i);
			poly->Add(gcnew NAvoid::Point(pt.x, pt.y));
		}

		return poly;

	}
	
	void Connector::ClearCheckPoints()
	{
		_pendingCheckPoints->Clear();
	}

	void Connector::AddCheckPoint(double x, double y, Direction arrival_direction, Direction departure_direction)
	{
		_pendingCheckPoints->Add(gcnew CheckPoint(x, y, arrival_direction, departure_direction));
	}
	
	void Connector::AddCheckPoint(double x, double y)
	{
		_pendingCheckPoints->Add(gcnew CheckPoint(x, y, Direction::All, Direction::All));
	}

	
	void Connector::setRoutingCheckPoints() {
		
		size_t size = _pendingCheckPoints->Count;
		std::vector<Avoid::Checkpoint> vect(size);
		
		int i = 0;

		for each (NAvoid::CheckPoint^ chk in _pendingCheckPoints) {

			Avoid::Point pt = Avoid::Point(chk->X(), chk->Y());
			Avoid::Checkpoint cp = Avoid::Checkpoint(
											pt, 
											(Avoid::ConnDirFlags) chk->ArrivalDirection(), 
											(Avoid::ConnDirFlags) chk->DepartureDirection()
								   );
			vect[i] = cp;
			i++;
		}

		_connRef->setRoutingCheckpoints(vect);
	}

	void Connector::SetFixedExistingRoute() {
		ClearCheckPoints();
		_connRef->setFixedExistingRoute();
	}

	bool Connector::HasFixedRoute() {
		return _connRef->hasFixedRoute();
	}

	void Connector::ClearFixedRoute() {
		ClearCheckPoints();
		_connRef->clearFixedRoute();
	}
		
}