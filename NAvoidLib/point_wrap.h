#pragma once

namespace NAvoid {

	public ref class Point : public System::IEquatable<Point^>
	{

		private:
			double _X ;
			double _Y ;


		public:
		
			double X();
			double Y();
		
			virtual bool Equals(Point ^other);

		internal:
			Point(double x, double y);

	};
	

}