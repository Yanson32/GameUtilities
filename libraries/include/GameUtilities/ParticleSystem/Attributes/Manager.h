#ifndef ATTRIBUTES_MANAGER_H
#define ATTRIBUTES_MANAGER_H
#include "particlesystem_export.h"
#include "GameUtilities/ParticleSystem/Attributes/AttributeBase.h"
#include <memory>
#include <vector>
#include <stack>

namespace GU
{
	namespace PS
	{
		namespace AT
		{
		    struct Remove
		    {
                public:
                    Remove(const std::size_t &newIndex):
                    index(newIndex)
                    {

                    }
                    std::size_t index = -1;
		    };
			struct Message
			{
			    Message()
			    {

			    }
			    enum Type
			    {
                    REMOVE
			    }type;
				union
				{
                    Remove remove;
				};
			};

			class PARTICLESYSTEM_EXPORT Manager
			{
                public:
                    Manager();
                    void sendMessage(const Message &message);
                    bool hasComponent(const int &id) const;
                    void addAttribute(std::shared_ptr<GU::PS::AT::AttributeBase> comp);
                    std::shared_ptr<GU::PS::AT::AttributeBase> getComponent(const int &id) const;
					void remove(const std::size_t &index);
					virtual ~Manager();
				private:
					std::vector<std::shared_ptr<GU::PS::AT::AttributeBase>> components;
					std::stack<GU::PS::AT::Message> messages;
			};
		}
	}
}

#endif
