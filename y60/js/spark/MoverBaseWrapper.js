/*jslint*/
/*globals use, spark, MoverBase, LEFT_BUTTON, RIGHT_BUTTON, MIDDLE_BUTTON,
          BUTTON_UP, BUTTON_DOWN*/

use("MoverBase.js");

spark.MoverBaseWrapper = spark.Class("MoverBaseWrapper");
spark.MoverBaseWrapper.Constructor = function (Protected, theViewport) {
    var Base = {};
    var Public = this;
    
    MoverBase.prototype.Constructor(this, theViewport);
    
    var mapper = {
        primary: LEFT_BUTTON,
        secondary: RIGHT_BUTTON,
        tertiary: MIDDLE_BUTTON
    };
    
    Public.onMouseButtonUp = function (theEvent) {
        Public.onMouseButton(mapper[theEvent.button], BUTTON_UP, theEvent.stageX, theEvent.stageY);
    };
    
    Public.onMouseButtonDown = function (theEvent) {
        Public.onMouseButton(mapper[theEvent.button], BUTTON_DOWN, theEvent.stageX, theEvent.stageY);
    };
};