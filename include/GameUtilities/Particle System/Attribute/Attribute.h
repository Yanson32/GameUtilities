#ifndef GU_ATTRIBUTE_H
#define GU_ATTRIBUTE_H
#include "GameUtilities/Particle System/Container.h"
#include "GameUtilities/Particle System/Updater/Updater.h"
namespace GU
{
    namespace PS
    {
        namespace AT
        {
            template<class T>
            class Attribute
            {
                public:
                    Attribute() = delete;
                    Attribute(const int id): id(id){}
                    virtual void Update();
                    const int id;

                private:
                    Container<T> attribute;

            };

            template <class T>
            void Attribute<T>::Update()
            {
            }


			template<class T>
			class Updater
			{
				public:
					void Update();
			};


			template<class T>
			void Updater<T>::Updater()
			{

			}
        }
    }
}

#endif // GU_ATTRIBUTE_H
