//=============================================================================
// Copyright (C) 1993-2005, ART+COM AG Berlin
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of ART+COM AG Berlin, and
// are copy protected by law. They may not be disclosed to third parties
// or copied or duplicated in any form, in whole or in part, without the
// specific, prior written permission of ART+COM AG Berlin.
//=============================================================================
//
//   $RCSfile: DemoRendererExtension.js,v $
//   $Author: christian $
//   $Revision: 1.6 $
//   $Date: 2004/10/31 15:58:17 $
//
//
//=============================================================================

if (__main__ == undefined) var __main__ = "DemoRendererExtension";

use("SceneViewer.js");
plug("DemoRendererExtension");


function DemoRendererExtensionApp(theArguments) {
    this.Constructor(this, theArguments);
}

DemoRendererExtensionApp.prototype.Constructor = function(self, theArguments) {
    var _myTextOverlay = null;

    //////////////////////////////////////////////////////////////////////
    //
    // Constructor
    //
    //////////////////////////////////////////////////////////////////////

    SceneViewer.prototype.Constructor(self, theArguments);
    var Base = [];
    var _myDemoRenderExtension = new DemoRendererExtension();

    //////////////////////////////////////////////////////////////////////
    //
    // public members
    //
    //////////////////////////////////////////////////////////////////////

    // setup
    Base.setup = self.setup;
    self.setup = function(theWidth, theHeight, theTitle) {
        Base.setup(theWidth, theHeight, false, theTitle);
        window.addExtension(_myDemoRenderExtension);
        self.registerSettingsListener(_myDemoRenderExtension, "DemoBehaviour");
        createTextOverlay();
    }

    Base.onKey = self.onKey;
    self.onKey = function(theKey, theState, theX, theY, theShiftFlag, theCtrlFlag, theAltFlag) {
        Base.onKey(theKey, theState, theX, theY, theShiftFlag, theCtrlFlag, theAltFlag);
    }

    Base.onFrame = self.onFrame;
    self.onFrame = function(theTime) {
        Base.onFrame(theTime);
    }

    Base.onMouseMotion = self.onMouseMotion;
    self.onMouseMotion = function(theX, theY) {
        if (Base.onMouseMotion) {
            Base.onMouseMotion(theX, theY);
        }
    }

    Base.onMouseButton = self.onMouseButton;
    self.onMouseButton = function(theButton, theState, theX, theY) {
        if (Base.onMouseButton) {
            Base.onMouseButton(theButton, theState, theX, theY);
        }
    }

    Base.onMouseWheel = self.onMouseWheel;
    self.onMouseWheel = function(theDeltaX, theDeltaY) {
        if (Base.onMouseWheel) {
            Base.onMouseWheel(theDeltaX, theDeltaY);
        }
    }

    ////////////// private members ////////////

    function createTextOverlay() {
        window.loadTTF("Arial", "${PRO}/src/Y60/gl/text/fonts/arial.ttf", 18);
        window.setTextPadding(10,10,10,10);
        window.setTextColor([0.2,0.2,1,1], [1,1,1,1]);

        var myTextImage = self.getImageManager().getImageNode("infobox");
        _myTextOverlay = new ImageOverlay(self.getOverlayManager(), myTextImage);
        _myTextOverlay.applyMode = "decal";
        _myTextOverlay.color = new Vector4f(0.8,0.8,1,0.6);

        var myTextSize = window.renderTextAsImage(myTextImage, "Press Ctrl-Q to quit.", "Arial", 300, 0);
        _myTextOverlay.width  = myTextSize.x;
        _myTextOverlay.height = myTextSize.y;
        _myTextOverlay.srcsize.x = myTextSize.x / myTextImage.width;
        _myTextOverlay.srcsize.y = myTextSize.y / myTextImage.height;

        _myTextOverlay.position = new Vector2f(10, 30);
        _myTextOverlay.visible = true;
    }

}

//
// main
//

if (__main__ == "DemoRendererExtension") {
    print("DemoRendererExtension");
    try {
        var ourDemoRendererExtensionApp = new DemoRendererExtensionApp(arguments);

        ourDemoRendererExtensionApp.setup(320, 200, "DemoRendererExtension");
        ourDemoRendererExtensionApp.go();
    } catch (ex) {
        print("-------------------------------------------------------------------------------");
        print("### Error: " + ex);
        print("-------------------------------------------------------------------------------");
        exit(1);
    }
}


