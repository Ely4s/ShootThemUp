//
//  Event.c
//  ShootThemUp
//
//  Created by El-idrissi Elyas on 27/11/2019.
//  Copyright © 2019 El-idrissi Elyas. All rights reserved.
//

#include "Event.h"

void Event_HandleTypedKey(Event * event)
{
    SDL_PollEvent(&event->e);

    if(!Event_IsEventType(event, SDL_MOUSEBUTTONUP))
    {
        if(event->mouseCooldown > 0)
        {
            event->mouseCooldown -= 1;
            
            if(event->mouseCooldown < 0)
            {
                event->mouseCooldown= 0;
            }
        }
    }
    
    if(event->mouseCooldown == 0)
    {
        event->mouseCanClick = true;
    }
    else
    {
        event->mouseCanClick = false;
    }

}
void Event_HandleRealTimeInput(Event * event)
{
    SDL_PumpEvents();
    event->KeyStates = SDL_GetKeyboardState(NULL);
    SDL_GetMouseState(&event->Xmouse, &event->Ymouse);
    event->Xmouse *=2;
    event->Ymouse *=2;  
}
bool Event_IsEventRealTime(Event * event, int scanCode)
{
    return event->KeyStates[scanCode];
}

bool Event_IsEventType(Event * event, SDL_EventType eventType)
{
    return event->e.type == eventType;
}

bool Event_IsEventKeyTyped(Event * event, int eventKeyTyped)
{
    return event->e.key.keysym.sym == eventKeyTyped;
}
bool Event_IsMouseDown(Event * event)
{
    if(Event_IsEventType(event, SDL_MOUSEBUTTONUP) && event->mouseCanClick)
    {
        event->mouseCooldown = 3;
        return 1;
    }
    else return 0;
    
//    if(event->mouseState == 1 && event->mouseCooldown == 0)
//    {
//        if(Event_IsEventType(event, SDL_MOUSEBUTTONDOWN))
//        {
//            event->mouseState = 0;
//            event->mouseCooldown = 5;
//            return 1;
//        }
//        else
//        {
//            return 0;
//        }
//    }
//
//    return 0;
}


//int
////void Event_SetEvent(Event * e, SDL_Event * eNew)
////{
////    e->event = * eNew;
////}
////
////bool Event_HasEvent(Event * e)
////{
////    return SDL_PollEvent(&e->event);
////}
////
////bool Event_IsEvent(Event * e, int eventType)
////{
////    return e->event.type == eventType;
////}
////
////const char * Event_GetEventKey(Event * e)
////{
////    return SDL_GetKeyName(e->event.key.keysym.sym);
////}
////
////bool Event_IsEventKeyEqualTo(Event * e, char * eventKey)
////{
////    return !strcmp(Event_GetEventKey(e), eventKey);
//}
