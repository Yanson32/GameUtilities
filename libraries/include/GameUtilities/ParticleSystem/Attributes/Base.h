#ifndef COMPONENT_PARTICLE_SYSTEM_BASE_H
#define COMPONENT_PARTICLE_SYSTEM_BASE_H
#include "particlesystem_export.h"
#include <vector>

namespace GU
{
	namespace PS
	{
		namespace AT
		{
            class Manager;
			class PARTICLESYSTEM_EXPORT Base
			{
				public:
					Base(GU::PS::AT::Manager& newManager, const std::size_t &newSize, const int &newId = -1);
					virtual void remove(const std::size_t &index) = 0;
					virtual ~Base();
					const int id = -1;
				protected:

                    GU::PS::AT::Manager &manager;
			};
		}
	}
}
#endif // COMPONENT_PARTICLE_SYSTEM_H
