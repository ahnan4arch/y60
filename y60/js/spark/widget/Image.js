/**
 * A simple Quad-image.
 *
 * NOTE: does not adjust it's size when image is changed. However, the size
 *       can be changed by setting the width, height and size properties.
 */
 
/*jslint nomen: false*/
/*globals spark, window, Modelling, Logger*/

spark.Image = spark.ComponentClass("Image");

spark.Image.Constructor = function (Protected) {
    var Base = {};
    var Public = this;
    Public.Inherit(spark.ResizableRectangle);

    /////////////////////
    // Private Members //
    /////////////////////

    var _mySource     = null;
    var _mySourceId   = null;
    var _mySourceItem = null;

    var _myImage      = null;
    var _myImageOwned = false;

    var _myTexture    = null;
    var _myUseCaching = true;

    // XXX crude hack starts here
    var _myOnImageChanged = null;
    // XXX crude hack ends here

    /////////////////////
    // Private Methods //
    /////////////////////
    
    function handleI18nLanguage(e) {
        Public.src = e.src;
    }

    function attachToI18nItem(theItemId) {
        if (_mySourceItem) {
            _mySourceItem.removeEventListener(spark.I18nEvent.LANGUAGE,
                                              handleI18nLanguage);
            _mySourceItem = null;
        }
        _mySourceItem = Public.getI18nItemByName(theItemId);
        if (!_mySourceItem) {
            Logger.fatal("no i18n item named " + theItemId);
        }
        _mySourceItem.addEventListener(spark.I18nEvent.LANGUAGE,
                                       handleI18nLanguage);
        Public.src = _mySourceItem.src;
    }

    ////////////////////
    // Public Methods //
    ////////////////////

    Public.__defineGetter__("image", function () {
        return _myImage;
    });

    Public.__defineSetter__("image", function (theNode) {
        if (!_myUseCaching || _myImageOwned) {
            _myImage.parentNode.removeChild(_myImage);
            _myImageOwned = false;
            _myImage = null;
        }
        _myImage = theNode;
        _myTexture.image = theNode.id;
        Public.width  = Protected.getNumber("width", _myImage.raster.width);
        Public.height = Protected.getNumber("height", _myImage.raster.height);

        // XXX crude hack starts here
        if (_myOnImageChanged) {
            _myOnImageChanged();
        }
        // XXX crude hack ends here
    });

    Public.__defineGetter__("src", function () {
        return _mySource;
    });

    Public.__defineSetter__("src", function (theSourceFile) {
        _mySource = theSourceFile;
        if (_myUseCaching) {
            Public.image = spark.getCachedImage(theSourceFile);
        } else {
            Public.image = Modelling.createImage(window.scene, _mySource);
        }
    });

    Public.__defineGetter__("srcId", function () {
        return _mySourceId;
    });

    Public.__defineSetter__("srcId", function (theValue) {
        _mySourceId = theValue;
        attachToI18nItem(theValue);
    });
    Public.__defineGetter__("i18nItem", function () {
        return Public.srcId;
    });
    Public.__defineSetter__("i18nItem", function (i) {
        Public.srcId = i;
    });

    // XXX: this should not exist.
    Public.__defineGetter__("texture", function () {
        return _myTexture;
    });

    Public.__defineGetter__("useCaching", function () {
        return _myUseCaching;
    });
    
    Public.__defineSetter__("useCaching", function (theFlag) {
        _myUseCaching = theFlag;
    });

    /* TODO clean this up:
     *
     * 1) if theCachedMaterial is given, use this material.
     *    - what happens to height & width?
     *    - we should set image & image-src, flagging it as "not owned"
     *    - we should set _myTexture to null
     * 
     * 2) if "useCaching" is true:
     *    - _myTexture is set to owned texture
     *    - _myMaterial is set to owned material
     *    - image & image-src is set to shared image, flagging it as "now owned"
     *
     * 3) if texture atlas is used:
     *    - the result is similar to cachedMaterial
     *    - new UV Coords must be handed over to base class (or we modify them afterwards)
     */
    Base.realize = Public.realize;
    Public.realize = function (theCachedMaterial) {
        var myImageSource = Protected.getString("src", "");
        var myImageSourceId = Protected.getString("srcId", "");
        _myUseCaching = Protected.getBoolean("useCaching", true);

        var myWidth = 0;
        var myHeight = 0;
        if (myImageSource === "") {
            myWidth = Protected.getNumber("width", 1);
            myHeight = Protected.getNumber("height", 1);
            _myImage      = Modelling.createImage(window.scene, myWidth, myHeight, "BGRA");
            _myImage.name = Public.name + "_ImagedummyImage";
            _myImageOwned = true;
            if (myImageSourceId !== "") {
                _mySourceId = myImageSourceId;
            }
        } else {
            this.src = myImageSource;
            myWidth = Protected.getNumber("width", _myImage.raster.width);
            myHeight = Protected.getNumber("height", _myImage.raster.height);
        }

        _myTexture  = Modelling.createTexture(window.scene, _myImage);
        _myTexture.name = Public.name + "-texture";
        _myTexture.wrapmode = "clamp_to_edge";
        
        var myMaterial = theCachedMaterial;
        if (myMaterial === undefined) {
            myMaterial = Modelling.createUnlitTexturedMaterial(window.scene,
                    _myTexture, Public.name + "-material", true);
        }

        Base.realize(myMaterial);

        Public.width = myWidth;
        Public.height = myHeight;
    };

    Base.postRealize = Public.postRealize;
    Public.postRealize = function () {
        if (_mySourceId) {
            attachToI18nItem(_mySourceId);
        }
        Base.postRealize();
    };

    // XXX crude hack starts here
    Public.__defineGetter__("onImageChanged", function () {
        return _myOnImageChanged;
    });
    Public.__defineSetter__("onImageChanged", function (f) {
        _myOnImageChanged = f;
    });
    // XXX crude hack ends here
};
