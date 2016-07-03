#include "router_factory.h"

namespace NAvoid {

	Router^ RouterFactory::Create(NAvoid::RouterFlag flags) {
		return gcnew Router(flags);
	}

}