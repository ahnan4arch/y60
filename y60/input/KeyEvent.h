/* __ ___ ____ _____ ______ _______ ________ _______ ______ _____ ____ ___ __
//
// Copyright (C) 1993-2008, ART+COM AG Berlin, Germany <www.artcom.de>
//
// These coded instructions, statements, and computer programs contain
// proprietary information of ART+COM AG Berlin, and are copy protected
// by law. They may be used, modified and redistributed under the terms
// of GNU General Public License referenced below.
//
// Alternative licensing without the obligations of the GPL is
// available upon request.
//
// GPL v3 Licensing:
//
// This file is part of the ART+COM Y60 Platform.
//
// ART+COM Y60 is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// ART+COM Y60 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with ART+COM Y60.  If not, see <http://www.gnu.org/licenses/>.
// __ ___ ____ _____ ______ _______ ________ _______ ______ _____ ____ ___ __
*/
//
//   $RCSfile: KeyEvent.h,v $
//   $Author: ulrich $
//   $Revision: 1.4 $
//   $Date: 2004/11/27 10:14:52 $
//
//
//=============================================================================

#ifndef _Y60_INPUT_KEYEVENT_INCLUDED_
#define _Y60_INPUT_KEYEVENT_INCLUDED_

#include "y60_input_settings.h"

#include "Event.h"
#include "KeyCodes.h"

namespace y60 {

    struct Y60_INPUT_DECL KeyEvent : public Event {
        KeyEvent(Type theEventType,
                unsigned char theScanCode,
                KeyCode theKeyCode,
                const char * theKeyString,
                unsigned int theModifiers);
        KeyEvent(const dom::NodePtr & theNode);
        virtual ~KeyEvent();

        const unsigned char scanCode;
        const KeyCode keyCode;
        const std::string keyString;
        const unsigned int modifiers;

        virtual EventPtr copy() const {
            return EventPtr(new KeyEvent(*this));
        }

        virtual dom::NodePtr asNode() const;

    private:
        Type getType(int theState) const;
    };
    typedef asl::Ptr<KeyEvent> KeyEventPtr;
}

#endif

