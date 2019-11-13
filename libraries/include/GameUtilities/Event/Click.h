#ifndef CLICK_H
#define CLICK_H
#include "GameUtilities/Event/Event.h"
namespace GU
{
    namespace Evt
    {
        class Click: public Event
        {
            public:
                Click(const int newId);
                virtual ~Click();
                const int id;
            protected:

            private:
        };
    }
}
#endif // CLICK_H
