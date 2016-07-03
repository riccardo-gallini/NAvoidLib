#pragma once

#include "router_wrap.h"
#include "point_wrap.h"
#include "checkpoint_wrap.h"


namespace NAvoid {

	public ref class RouterFactory 
	{

		public:

			Router^ Create(RouterFlag flags);
			
	};

}
