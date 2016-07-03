#include "libavoid/libavoid.h"

using namespace Avoid;

namespace NAvoidTest {

	public ref class test3 {

	public:
		static int main(void);


	};


int test3::main(void) {
	Router *router = new Router(
		PolyLineRouting | OrthogonalRouting);
	router->setRoutingParameter((RoutingParameter)0, 50);
	router->setRoutingParameter((RoutingParameter)1, 0);
	router->setRoutingParameter((RoutingParameter)2, 0);
	router->setRoutingParameter((RoutingParameter)3, 4000);
	router->setRoutingParameter((RoutingParameter)4, 0);
	router->setRoutingParameter((RoutingParameter)5, 100);
	router->setRoutingOption((RoutingOption)0, true);
	router->setRoutingOption((RoutingOption)1, true);
	router->setRoutingOption((RoutingOption)2, false);



	Polygon poly75(4);
	poly75.ps[0] = Point(715.439, 1924.42);
	poly75.ps[1] = Point(715.439, 1944.42);
	poly75.ps[2] = Point(683.439, 1944.42);
	poly75.ps[3] = Point(683.439, 1924.42);
	new ShapeRef(router, poly75, 75);

	Polygon poly76(4);
	poly76.ps[0] = Point(282.5, 1872.42);
	poly76.ps[1] = Point(282.5, 1934.42);
	poly76.ps[2] = Point(220.5, 1934.42);
	poly76.ps[3] = Point(220.5, 1872.42);
	new ShapeRef(router, poly76, 76);


	Polygon poly78(4);
	poly78.ps[0] = Point(715.439, 1862.42);
	poly78.ps[1] = Point(715.439, 1882.42);
	poly78.ps[2] = Point(683.439, 1882.42);
	poly78.ps[3] = Point(683.439, 1862.42);
	new ShapeRef(router, poly78, 78);


	Polygon poly136(4);
	poly136.ps[0] = Point(727.439, 1944.42);
	poly136.ps[1] = Point(727.439, 2004.42);
	poly136.ps[2] = Point(671.439, 2004.42);
	poly136.ps[3] = Point(671.439, 1944.42);
	new ShapeRef(router, poly136, 136);



	Polygon poly138(4);
	poly138.ps[0] = Point(727.439, 1802.42);
	poly138.ps[1] = Point(727.439, 1862.42);
	poly138.ps[2] = Point(671.439, 1862.42);
	poly138.ps[3] = Point(671.439, 1802.42);
	new ShapeRef(router, poly138, 138);


	ConnRef *connRef250 = new ConnRef(router, 250);
	ConnEnd srcPt250(Point(251.5, 1903.42), 15);
	connRef250->setSourceEndpoint(srcPt250);
	ConnEnd dstPt250(Point(684.439, 1934.42), 4);
	connRef250->setDestEndpoint(dstPt250);
	connRef250->setRoutingType((ConnType)2);
	std::vector<Checkpoint> checkpoints250(1);
	checkpoints250[0] = Point(661.439, 1903.42);
	connRef250->setRoutingCheckpoints(checkpoints250);

	ConnRef *connRef251 = new ConnRef(router, 251);
	ConnEnd srcPt251(Point(251.5, 1903.42), 15);
	connRef251->setSourceEndpoint(srcPt251);
	ConnEnd dstPt251(Point(684.439, 1872.42), 4);
	connRef251->setDestEndpoint(dstPt251);
	connRef251->setRoutingType((ConnType)2);
	std::vector<Checkpoint> checkpoints251(1);
	checkpoints251[0] = Point(661.439, 1903.42);
	connRef251->setRoutingCheckpoints(checkpoints251);


	router->processTransaction();
	router->outputDiagramSVG("c:\checkpointNudging1");
	bool atEnds = true;
	bool overlap = router->existsOrthogonalFixedSegmentOverlap(atEnds);
	delete router;
	return (overlap) ? 1 : 0;
}

}

