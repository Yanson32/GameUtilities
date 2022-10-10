#ifndef GAMEUTILITIES_EVENTS_H_INCLUDED
#define GAMEUTILITIES_EVENTS_H_INCLUDED
/*********************************************************************************//**
*	@author	        Wayne J Larson Jr.
*	@date 	        12/10/22
*	@description    This file includes every event.
*************************************************************************************/

/*************************************************************************
*                           COPYRIGHT NOTICE
* GameUtilities is a toolkit for making 2d video games.
* Copyright (C) 2018 Wayne J Larson Jr. 
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 3 as 
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
***************************************************************************/
#include "GameUtilities/Event/Events/OnChangeState.h"
#include "GameUtilities/Event/Events/OnMessage.h"
#include "GameUtilities/Event/Events/OnLog.h"
#include "GameUtilities/Event/Events/Event.h"
#include "GameUtilities/Event/Events/OnPlayMusic.h"
#include "GameUtilities/Event/Events/OnPlaySound.h"
#include "GameUtilities/Event/Events/OnPop.h"
#include "GameUtilities/Event/Events/OnPushState.h"
#include "GameUtilities/Event/Events/OnResume.h"
#include "GameUtilities/Event/Events/OnStop.h"
#include "GameUtilities/Event/Events/OnStart.h"
#include "GameUtilities/Event/Events/OnAdd.h"
#include "GameUtilities/Event/Events/OnStartFocus.h"
#include "GameUtilities/Event/Events/OnEndFocus.h"
#include "GameUtilities/Event/Events/OnRefresh.h"
#include "GameUtilities/Event/Events/OnUpdate.h"
#include "GameUtilities/Event/Events/OnChange.h"
#include "GameUtilities/Event/Events/OnPush.h"
#include "GameUtilities/Event/Events/OnRemove.h"
#include "GameUtilities/Event/EventId.h"
#include "GameUtilities/Event/Events/Widget/WidgetEvent.h"
#include "GameUtilities/Event/Events/Widget/OnCheck.h"
#include "GameUtilities/Event/Events/Widget/OnTextChanged.h"
#include "GameUtilities/Event/Events/Widget/OnSliderChanged.h"
#include "GameUtilities/Event/Events/Widget/OnItemSelected.h"
#include "GameUtilities/Event/Events/Keyboard/OnKeyPressed.h"
#include "GameUtilities/Event/Events/Keyboard/OnKeyReleased.h"
#include "GameUtilities/Event/Events/Mouse/OnClick.h"
#include "GameUtilities/Event/Events/Mouse/OnContextMenu.h"
#include "GameUtilities/Event/Events/Mouse/OnEndMouseDrag.h"
#include "GameUtilities/Event/Events/Mouse/OnMouseButtonReleased.h"
#include "GameUtilities/Event/Events/Mouse/OnMouseWheel.h"
#include "GameUtilities/Event/Events/Mouse/OnStartMouseDrag.h"
#include "GameUtilities/Event/Events/Mouse/OnDoubleClick.h"
#include "GameUtilities/Event/Events/Mouse/OnMouseButtonPressed.h"
#include "GameUtilities/Event/Events/Mouse/OnMouseMoved.h"
#include "GameUtilities/Event/Events/Mouse/OnStartDrag.h"
#include "GameUtilities/Event/Events/Physics/OnStartCollision.h"
#include "GameUtilities/Event/Events/Physics/OnEndCollision.h"
#endif // EVENTS_H_INCLUDED
