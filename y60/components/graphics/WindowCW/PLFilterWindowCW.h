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
//
// Description: TODO  
//
// Last Review: NEVER, NOONE
//
//  review status report: (perfect, ok, fair, poor, disaster, notapplicable, unknown)
//    usefullness            : unknown
//    formatting             : unknown
//    documentation          : unknown
//    test coverage          : unknown
//    names                  : unknown
//    style guide conformance: unknown
//    technical soundness    : unknown
//    dead code              : unknown
//    readability            : unknown
//    understandabilty       : unknown
//    interfaces             : unknown
//    confidence             : unknown
//    integration            : unknown
//    dependencies           : unknown
//    cheesyness             : unknown
//
//    overall review status  : unknown
//
//    recommendations: 
//       - unknown
// __ ___ ____ _____ ______ _______ ________ _______ ______ _____ ____ ___ __
*/
//
//   $Id: PLFilterWindowCW.h,v 1.2 2004/11/09 16:56:34 janbo Exp $
//   $RCSfile: PLFilterWindowCW.h,v $
//   $Author: janbo $
//   $Revision: 1.2 $
//   $Date: 2004/11/09 16:56:34 $
//
//
//  Description:
//
//
//=============================================================================

#ifndef _ac_som_PLFilterWindowCW_h_
#define _ac_som_PLFilterWindowCW_h_

#include "y60_windowcwfilter_settings.h"

#include <asl/base/Exception.h>

#if defined(_MSC_VER)
#   pragma warning (push,1)
#endif //defined(_MSC_VER)
#include <paintlib/plpaintlibdefs.h>
#include <paintlib/Filter/plfilter.h>
#if defined(_MSC_VER)
#   pragma warning (pop)
#endif //defined(_MSC_VER)

DEFINE_EXCEPTION(UnsupportedPixelFormat, asl::Exception)


class PLBmp;

//  1.0|        ___
//     |       /
//     |      /
//  0.5|---  /
//     |    /
//     |   /   window center
//  0.0|__/  /
//     -----^----- 1.0
//        <---> window width

class PLFilterWindowCW : public PLFilter {
    public:
        PLFilterWindowCW(float theWindowCenter, float theWindowWidth);
        virtual ~PLFilterWindowCW() {};
        virtual void Apply(PLBmpBase * theSource, PLBmp * theDestination) const;

    private:
        float _myCenter;
        float _myWidth;        
};

#endif