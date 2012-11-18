//
//  touch_control.cpp
//  CaveStory
//
//  Created by Pavlo Ilin on 18.11.12.
//
//

#include "touch_control.h"
#include "touch_control_private.h"

static IGestureObserver* sGO = 0;

void registerGetureObserver(IGestureObserver* observer)
{
    sGO = observer;
}

void toggleGestureRecognizer(bool enabled)
{
    toggle_gesture_recognizer(enabled);
}


extern "C"
{
    void tap(float x, float y)
    {
        if (sGO)
            sGO->tap(x, y);
    }
    
    void double_tap(float x, float y)
    {
        if (sGO)
            sGO->double_tap(x, y);
    }

}