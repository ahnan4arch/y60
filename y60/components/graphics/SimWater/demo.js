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
if (__main__ == undefined) var __main__ = "SimWaterTest";

use("SceneViewer.js");

plug("SimWater");

window = new RenderWindow();

function SimWaterTestApp(theArguments) {
    this.Constructor(this, theArguments);
}

SimWaterTestApp.prototype.Constructor = function(self, theArguments) {

    //////////////////////////////////////////////////////////////////////
    //
    // Constructor
    //
    //////////////////////////////////////////////////////////////////////

    SceneViewer.prototype.Constructor(self, theArguments);
    var Base = [];

    //////////////////////////////////////////////////////////////////////
    //
    // public members
    //
    //////////////////////////////////////////////////////////////////////

    // setup
    Base.setup = self.setup;
    self.setup = function(theWidth, theHeight, theTitle) {
        Base.setup(theWidth, theHeight, false, theTitle);
        window.resize(theWidth, theHeight);
        _myWater = new SimWater();
        window.addExtension(_myWater);
        _myWater.addFloormap( "data/whiskeyglas2.png" );
        print( "active floormap: " + _myWater.activeFloormap + " of " + _myWater.floormapCount );
        _myWater.addFloormap( "data/greypattern.png" );
        print( "active floormap: " + _myWater.activeFloormap  + " of " + _myWater.floormapCount );
        _myWater.activeFloormap = 1;

        _myWater.addCubemap( "data/forest_2_front.png", "data/forest_2_left.png", "data/forest_2_back.png", 
                             "data/forest_2_right.png", "data/forest_2_top.png", "data/forest_2_bottom.png" ); 

        print( "active cubemap: " + _myWater.activeCubemap  + " of " + _myWater.cubemapCount );


        _myWater.addCubemap( "data/cube_top.png", "data/cube_left.png", "data/cube_bottom.png", 
                             "data/cube_right.png", "data/cube_roof.png", "data/cube_ground.png" ); 

        print( "active cubemap: " + _myWater.activeCubemap  + " of " + _myWater.cubemapCount );
        _myWater.activeCubemap = 0;

        self.registerSettingsListener( _myWater, "Water" );
        print("setup done");
    }

    Base.onFrame = self.onFrame;
    self.onFrame = function(theTime) {
        Base.onFrame(theTime);

    }

    Base.onKey = self.onKey;
    self.onKey = function(theKey, theKeyState, theX, theY, theShiftFlag, theCtrlFlag, theAltFlag) {
         if (theCtrlFlag) {
            Base.onKey(theKey, theKeyState, theX, theY, theShiftFlag, theCtrlFlag, theAltFlag);
             return;
         }
         if (!theKeyState) {
            return;
        }
        switch (theKey) {
            case 'left':
                _myWater.timestep -= 0.001;
                print(_myWater.timestep);
                break;
            case 'right':
                _myWater.timestep += 0.001;
                print(_myWater.timestep);
                break;
            case 'space':
                var myIndex = _myWater.activeCubemap + 1;
                if (myIndex == _myWater.cubemapCount) {
                    myIndex = 0;
                }
                _myWater.activeCubemap = myIndex;
                print( "active cubemap: " + _myWater.activeCubemap  + " of " + _myWater.cubemapCount );
                break;
        }
    }

    Base.onMouseButton = self.onMouseButton;
    self.onMouseButton = function( theButton, theState, theX, theY ) {
        Base.onMouseButton( theButton, theState, theX, theY);
        _myWater.splash(new Vector2i(theX, theY), 7, 10);
    }

    var _myWater = null;
    var _myScale = 1.0;
}

if (__main__ == "SimWaterTest") {
    print("SimWaterTest");
    try {
        var ourSimWaterTestApp = new SimWaterTestApp(
                [expandEnvironment("${PRO}") + "/src/y60/shader/shaderlibrary_nocg.xml"]);
        ourSimWaterTestApp.setup(600, 600, "SimWaterTest");
        ourSimWaterTestApp.go();
    } catch (ex) {
        print("-------------------------------------------------------------------------------");
        print("### Error: " + ex);
        print("-------------------------------------------------------------------------------");
        exit(1);
    }
}
