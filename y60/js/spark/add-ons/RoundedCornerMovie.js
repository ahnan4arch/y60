//=============================================================================
// Copyright (C) 2009, ART+COM AG Berlin
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of ART+COM AG Berlin, and
// are copy protected by law. They may not be disclosed to third parties
// or copied or duplicated in any form, in whole or in part, without the
// specific, prior written permission of ART+COM AG Berlin.
//=============================================================================

/*jslint*/
/*globals spark*/

spark.RoundedCornerMovie = spark.ComponentClass("RoundedCornerMovie");
spark.RoundedCornerMovie.Constructor = function (Protected) {
    var Base   = {};
    var Public = this;
    Public.Inherit(spark.Movie);
    Public.Inherit(spark.RoundedCornerQuad);
    
    Base.initialize = Public.initialize;
    Public.initialize = function(theNode) {
        Base.initialize(theNode);
        Base.onMovieChanged = Protected.onMovieChanged;
        Protected.onMovieChanged = function(theFullInitFlag) {
            Base.onMovieChanged(theFullInitFlag);
            if (Public.movie.nodeName !== "image") {
                Public.update();
            }
        };
    };
    
};
