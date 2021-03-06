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

use("Y60JSSL.js");

// Use fileline() function to create location object
// theName is optional.
function Exception(theMessage, theLocation, theName) {
    var self = this; // inner function this bug workaround
    self.message    = theMessage;
    self.fileName   = theLocation ? theLocation.file : "";
    self.lineNumber = theLocation ? theLocation.line : "";
    self.name       = theName || "Exception";

    this.what = function() {
        return self.message;
    };
    this.where = function() {
        return "[" + self.fileName + ":" + self.lineNumber + "]";
    };
    this.toString = function() {
        return self.name + " in " + self.where() + ": " + self.message;
    };

    this.set = function(theMessage, theLocation, theName) {
        self.message = theMessage;
        self.fileName   = theLocation.file;
        self.lineNumber = theLocation.line;
        self.name    = theName;
    };
}

// This functions works for c++ and for JavaScript exceptions
function composeException(theException) {
    var myMessage = "";
    if (typeof(theException) == "object" && "message" in theException) {
        if (theException.name != "Error") {
            myMessage += theException.name + ": ";
        }
        myMessage += trim(theException.message);

        if ("fileName" in theException) {
            myMessage += " [" + getFilenamePart(theException.fileName);
        }

        if ("lineNumber" in theException) {
            myMessage += ":" + theException.lineNumber + "]";
        }
    } else {
        myMessage = "ERROR: " + String(theException);
    }
    return myMessage;
}

function reportException(theException) {
    Logger.error(composeException(theException));
}
