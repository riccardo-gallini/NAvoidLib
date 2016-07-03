#pragma once

#include "stdafx.h"

#include <msclr\marshal_cppstd.h>

#include "libavoid/router.h"
#include "libavoid/shape.h"
#include "libavoid/obstacle.h"
#include "libavoid/geomtypes.h"

#include "router_enums.h"
#include "point_wrap.h"

namespace NAvoid
{

	static const unsigned int runningTo = 1;
	static const unsigned int runningFrom = 2;
	static const unsigned int runningToAndFrom = runningTo | runningFrom;
	static const double zeroParamValue = 0;
	static const double chooseSensibleParamValue = -1;
	
	ref class Shape;
	ref class Connector;

	public ref class ConnectorRepaintEventArgs : System::EventArgs 
	{

		public:
			Connector^ Connector;


	};

	public ref class Router
	{
		public:

			
			bool ProcessTransaction();
			void DeleteShape(Shape ^shape);
			void DeleteShape(System::String^ name);
			void MoveShape(Shape ^shape, double xmove, double ymove);
			void DeleteConnector(Connector ^conn);
			void DeleteConnector(System::String^ name);
			
			void SetRoutingPenalty(const RoutingParameters penType, const double penVal);

			void SetRoutingParameter(const RoutingParameters parameter, const double value);
			double RoutingParameter(const RoutingParameters parameter);
			void SetRoutingOption(const RoutingOptions option, const bool value);
			bool RoutingOption(const RoutingOptions option);
			
			Shape^ AddRectangle(System::String^ name, double top, double left, double bottom, double right);
			Shape^ AddShape(System::String^ name, System::Collections::Generic::IList<Point ^> ^poly);
			Connector^ ConnectShapes(System::String^ connector_name, Shape^ from_shape, System::String^ from_pin, Shape^ to_shape, System::String^ to_pin);
			
			System::Collections::Generic::IDictionary<System::String^, NAvoid::Shape^>^ AttachedShapes();
			System::Collections::Generic::IDictionary<System::String^, NAvoid::Connector^>^ AttachedConnectors();

			event System::EventHandler<ConnectorRepaintEventArgs^>^ ConnectorRepaint;

			void OutputDiagram(System::String^ filename);
			void OutputDiagramSVG(System::String^ filename);
				
	internal:
			Avoid::Router *_router;

			Router(RouterFlag flags);
			~Router();

			void OnConnectorRepaint(NAvoid::Connector^ conn);

	private:
		
		System::Collections::Generic::IDictionary<System::String^, NAvoid::Shape^>^ _attachedShapes;
		System::Collections::Generic::IDictionary<System::String^, NAvoid::Connector^>^ _attachedConnectors;

			//void printInfo(void);
		
			//ShapeRef *shapeContainingPoint(const Point& point);

			/**
			*  @brief  Set an addon for doing orthogonal topology improvement.
			*
			*  It is expected that you would use the topology::AvoidTopologyAddon()
			*  from libtopology rather than write your own.  This is done so that
			*  libavoid does not have to depend on libtopology.
			*/
			/* SKIP ---    TODO: check Orthogonal Topology is needed?
			void setTopologyAddon(TopologyAddonInterface *topologyAddon);
			void improveOrthogonalTopology(void);

			*/
				
		
	};

}