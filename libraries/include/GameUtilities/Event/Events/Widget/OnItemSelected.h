#ifndef GAMEUTILITIES_ON_COMBO_CHANGED_H 
#define GAMEUTILITIES_ON_COMBO_CHANGED_H 
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       05/07/22
*   Purpose:    This event is to indicate when a combo box has changed 
**************************************************************************/
#include "GameUtilities/Event/Event.h"
#include "GameUtilities/Core/String.h"
#include "event_export.h"

namespace GU
{
    namespace Evt
    {

        class EVENT_EXPORT OnItemSelected: public Event
        {
            public:
               
                /**************************************************************************
                *   @brief  Constructor   
                *   @param  comboId is the id of the combo box
                *   @param  index is the index of the data element that has changed. 
                **************************************************************************/
                OnItemSelected(const int &comboId, const int &index = -1, const GU::Core::String &text = "");
                

                /**************************************************************************
                *   @brief  Destructor
                **************************************************************************/
                virtual ~OnItemSelected();
                
            public:
                const int m_comboId = -1;                     //Id of the combo box
                const int m_index;                            //Index of the data element
                const GU::Core::String m_text;     
        };
    }
}
#endif 
