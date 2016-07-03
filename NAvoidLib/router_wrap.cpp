#include "stdafx.h"

#include <msclr\marshal_cppstd.h>
#include <vcclr.h>

#include "libavoid/router.h"
#include "libavoid/shape.h"
#include "libavoid/obstacle.h"
#include "libavoid/geomtypes.h"

#include "router_enums.h"
#include "router_wrap.h"
#include "shaperef_wrap.h"
#include "connector_wrap.h"

namespace NAvoid
{

	Router::Router(RouterFlag flags)
	{
		_router = new Avoid::Router((const unsigned int)flags);
		_attachedShapes = gcnew System::Collections::Generic::Dictionary<System::String^, NAvoid::Shape^>();
		_attachedConnectors = gcnew System::Collections::Generic::Dictionary<System::String^, NAvoid::Connector^>();
		
		

	}

	Router::~Router()
	{
		delete _router;
		_router = 0;
	}

	bool Router::ProcessTransaction()
	{
		//send all then pending checkpoints to the libavoid router
		for each (NAvoid::Connector^ conn in _attachedConnectors->Values)
		{
			conn->setRoutingCheckPoints();
		}

		//process transaction
		return _router->processTransaction();
	}

	void Router::DeleteShape(Shape^ shape)
	{
		_router->deleteShape(shape->_shapeRef);
		_attachedShapes->Remove(shape->Name());
	}

	void Router::DeleteShape(System::String^ name)
	{
		this->DeleteShape(_attachedShapes[name]);
	}

	void Router::MoveShape(Shape^ shape, double xmove, double ymove)
	{
		_router->moveShape(shape->_shapeRef, xmove, ymove);
	}
	
	void Router::DeleteConnector(Connector^ conn)
	{
		_router->deleteConnector(conn->_connRef);
		_attachedConnectors->Remove(conn->Name());
	}

	void Router::DeleteConnector(System::String^ name)
	{
		this->DeleteConnector(_attachedConnectors[name]);
	}

	void Router::SetRoutingParameter(const RoutingParameters parameter, const double value) {
		_router->setRoutingParameter((Avoid::RoutingParameter) parameter, value);
	}

	double Router::RoutingParameter(const RoutingParameters parameter)
	{
		return _router->routingParameter((Avoid::RoutingParameter) parameter);
	}

	void Router::SetRoutingOption(const RoutingOptions option, const bool value)
	{
		_router->setRoutingOption((Avoid::RoutingOption) option, value);
	}

	bool Router::RoutingOption(const RoutingOptions option)
	{
		return _router->routingOption((Avoid::RoutingOption) option);
	}

	void Router::SetRoutingPenalty(const RoutingParameters penType, const double penVal)
	{
		_router->setRoutingPenalty((Avoid::RoutingParameter) penType, penVal);
	}

	Shape^ Router::AddRectangle(System::String^ name, double top, double left, double bottom, double right)
	{
		System::Collections::Generic::IList<Point^>^ poly = gcnew System::Collections::Generic::List<Point^>;
		poly->Add(gcnew NAvoid::Point(right, top));
		poly->Add(gcnew NAvoid::Point(right, bottom));
		poly->Add(gcnew NAvoid::Point(left, bottom));
		poly->Add(gcnew NAvoid::Point(left, top));

		return this->AddShape(name, poly);
	}

	Shape^ Router::AddShape(System::String^ name, System::Collections::Generic::IList<Point ^> ^poly)
	{
		Shape^ shape = gcnew NAvoid::Shape(this, name, poly);
		_attachedShapes->Add(name, shape);
		return shape;
	}
		
	void ConnectorCallback(void *ptr) {
		
		//blah blah for interacting with an unmanaged callback 
		System::IntPtr pointer(ptr);
		System::Runtime::InteropServices::GCHandle handle = System::Runtime::InteropServices::GCHandle::FromIntPtr(pointer);
		NAvoid::Connector^ conn = (Connector^)handle.Target;
				

		NAvoid::Router^ router;
		router = conn->internal_router;

		router->OnConnectorRepaint(conn);
		
	}
	
	void Router::OnConnectorRepaint(Connector^ conn) {
		ConnectorRepaintEventArgs^ e = gcnew ConnectorRepaintEventArgs();
		e->Connector = conn;

		this->ConnectorRepaint(this, e);
	}

	Connector^ Router::ConnectShapes(System::String^ connector_name, Shape^ from_shape, System::String ^from_pin, Shape^ to_shape, System::String^ to_pin)
	{
		Connector^ conn = gcnew NAvoid::Connector(connector_name, this, from_shape, from_pin, to_shape, to_pin);

		//blah blah for interacting with an unmanaged callback 
		System::Runtime::InteropServices::GCHandle handle = System::Runtime::InteropServices::GCHandle::Alloc(conn);
		System::IntPtr pointer = System::Runtime::InteropServices::GCHandle::ToIntPtr(handle);
		void* ptr = pointer.ToPointer();
		conn->_connRef->setCallback(ConnectorCallback, ptr);
		
		_attachedConnectors->Add(connector_name, conn);
		return conn;
	}

	System::Collections::Generic::IDictionary<System::String^, NAvoid::Shape^>^ Router::AttachedShapes()
	{
		return _attachedShapes;
	}

	System::Collections::Generic::IDictionary<System::String^, NAvoid::Connector^>^ Router::AttachedConnectors()
	{
		return _attachedConnectors;
	}

	void Router::OutputDiagram(System::String^ filename) {
		
		_router->outputDiagram(msclr::interop::marshal_as<std::string>(filename));
	}
		
	void Router::OutputDiagramSVG(System::String^ filename) {
		
		_router->outputDiagramSVG(msclr::interop::marshal_as<std::string>(filename));
	}


}
		



	


