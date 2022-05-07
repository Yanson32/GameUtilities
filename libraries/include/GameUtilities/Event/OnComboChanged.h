#ifndef GAMEUTILITIES_ON_COMBO_CHANGED_H 
#define GAMEUTILITIES_ON_COMBO_CHANGED_H 
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       05/07/22
*   Purpose:    This event is to indicate when a combo box has changed 
**************************************************************************/
#include "GameUtilities/Event/Event.h"
#include "event_export.h"

namespace GU
{
    namespace Evt
    {

        class EVENT_EXPORT OnComboChanged: public Event
        {
            public:
               
                /**************************************************************************
                *   @brief  Constructor   
                *   @param  newComboId is the id of the combo box
                *   @param  newIndex is the index of the data element that has changed. 
                **************************************************************************/
                OnComboChanged(const int newComboId, const int newIndex);
                

                /**************************************************************************
                *   @brief  Destructor
                **************************************************************************/
                virtual ~OnComboChanged();
                
            public:
                const int comboId = -1;                     //Id of the combo box
                const int index;                            //Index of the data element
        };
    }
}
#endif 
