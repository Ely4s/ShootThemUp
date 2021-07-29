//
//  Event.h
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 27/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#ifndef Event_h
#define Event_h

#include "main.h"

void Event_HandleTypedKey(Event * event);
void Event_HandleRealTimeInput(Event * event);

bool Event_IsEventRealTime(Event * event, int scanCode);
bool Event_IsEventType(Event * event, SDL_EventType eventType);
bool Event_IsEventKeyTyped(Event * event, int eventKeyTyped);
bool Event_IsMouseDown(Event * event);

#endif /* Event_h */
