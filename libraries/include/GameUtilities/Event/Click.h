#ifndef CLICK_H
#define CLICK_H
#include "event_export.h"
#include "GameUtilities/Event/Event.h"
namespace GU
{
    namespace Evt
    {
        class EVENT_EXPORT Click: public Event
        {
            public:
                Click(const int newId);
                virtual ~Click();
                const int buttonId;
            protected:

            private:
        };
    }
}
#endif // CLICK_H
