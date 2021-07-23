#include "GameUtilities/ParticleSystem/Attributes/Manager.h"
#include "GameUtilities/ParticleSystem/Attributes/Position.h"
#include "GameUtilities/ParticleSystem/Attributes/Velocity.h"
#include "GameUtilities/ParticleSystem/Attributes/LifeSpan.h"
#include "GameUtilities/ParticleSystem/Attributes/Id.h"
#include <iostream>
#include <cassert>
namespace GU
{
	namespace PS
	{
		namespace AT
		{
			Manager::Manager()
			{

			}

            void Manager::sendMessage(const Message &message)
            {
                messages.push(message);
            }

			void Manager::remove(const std::size_t &index)
			{
				for(std::size_t i = 0; i < components.size(); ++i)
				{
					assert(components[i] != nullptr);
                    components[i]->remove(index);
				}
			}
            std::shared_ptr<GU::PS::AT::Base> Manager::getComponent(const int &id) const
            {

                for(std::size_t i = 0; i < components.size(); ++i)
                {
					assert(components[i] != nullptr);
                    if(components[i]->id == id)
                    {
                        return components[i];
                    }
                }
                throw std::runtime_error("Invalid component requested");
            }

			bool Manager::hasComponent(const int &id) const
			{
			    for(auto it = components.begin(); it != components.end(); it++)
                {
					//assert((*it) != nullptr);
					if((*it) != nullptr)
                    if((*it)->id == id)
                        return true;
                }

                return false;
			}


			void Manager::addAttribute(std::shared_ptr<GU::PS::AT::Base> comp)
			{
				assert(comp != nullptr);
                if(hasComponent(comp->id))
                    throw std::runtime_error("Component already exists");

			    components.push_back(comp);
			}

			Manager::~Manager()
			{

			}
		}
	}
}
