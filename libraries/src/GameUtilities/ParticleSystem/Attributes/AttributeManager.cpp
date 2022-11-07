#include "GameUtilities/ParticleSystem/Attributes/AttributeManager.h"
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
			AttributeManager::AttributeManager()
			{

			}

            void AttributeManager::sendMessage(const Message &message)
            {
                messages.push(message);
            }

			void AttributeManager::remove(const std::size_t &index)
			{
				for(std::size_t i = 0; i < components.size(); ++i)
				{
					assert(components[i] != nullptr);
                    components[i]->remove(index);
				}
			}
            std::shared_ptr<GU::PS::AT::AttributeBase> AttributeManager::getComponent(const int &id) const
            {

                for(std::size_t i = 0; i < components.size(); ++i)
                {
					assert(components[i] != nullptr);
                    if(components[i]->m_id == id)
                    {
                        return components[i];
                    }
                }
                throw std::runtime_error("Invalid component requested");
            }

			bool AttributeManager::hasComponent(const int &id) const
			{
			    for(auto it = components.begin(); it != components.end(); it++)
                {
					//assert((*it) != nullptr);
					if((*it) != nullptr)
                    if((*it)->m_id == id)
                        return true;
                }

                return false;
			}


			void AttributeManager::addAttribute(std::shared_ptr<GU::PS::AT::AttributeBase> comp)
			{
				assert(comp != nullptr);
                if(hasComponent(comp->m_id))
                    throw std::runtime_error("Component already exists");

			    components.push_back(comp);
			}

			AttributeManager::~AttributeManager()
			{

			}
		}
	}
}
