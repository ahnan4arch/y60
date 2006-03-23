//============================================================================
// Copyright (C) 2004-2006, ART+COM AG Berlin
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of ART+COM AG Berlin, and
// are copy protected by law. They may not be disclosed to third parties
// or copied or duplicated in any form, in whole or in part, without the
// specific, prior written permission of ART+COM AG Berlin.
//============================================================================

#ifndef AC_Y60_GEOMETRY_FUNCTIONS_INCLUDED
#define AC_Y60_GEOMETRY_FUNCTIONS_INCLUDED

#include <y60/Scene.h>
#include <y60/VertexIndexBuilder.h>
#include <y60/ShapeBuilder.h>
#include <y60/ElementBuilder.h>
#include <y60/MaterialBuilder.h>

#include <dom/Nodes.h>
#include <asl/Vector234.h>
#include <asl/PerlinNoise.h>

#include <string>
#include <iostream>

namespace y60 {
/// @addtogroup Y60modelling \@{
struct PhongProperties {
    asl::Vector4f ambientColor;
    asl::Vector4f diffuseColor;
    asl::Vector4f emissiveColor;
    asl::Vector4f specularColor;
    float shininess;
};

dom::NodePtr createPhongTexturedMaterial(ScenePtr theScene,
                                const std::string & theTextureFilename,
                                const std::string & theName,
                                const PhongProperties & thePhongProperties,
                                bool theTransparencyFlag = false,
                                bool theSpriteFlag = false,
                                unsigned theDepth = 1);

dom::NodePtr createUnlitTexturedColoredMaterial(y60::ScenePtr theScene,
                                 const std::string & theTextureFilename,
                                 const std::string & theName = "ColorMaterial",
                                 bool theSpriteFlag = false,
                                 unsigned theDepth = 1);

dom::NodePtr createUnlitTexturedMaterial(y60::ScenePtr theScene,
                                 const std::string & theTextureFilename,
                                 const std::string & theName = "Material",
                                 bool theTransparencyFlag = false,
                                 bool theSpriteFlag = false,
                                 unsigned theDepth = 1,
                                 const asl::Vector4f & theColor = asl::Vector4f(1.0, 1.0, 1.0, 1.0));

dom::NodePtr createUnlitTexturedMaterial(y60::ScenePtr theScene,
                                 dom::NodePtr theImageNode,
                                 const std::string & theName = "Material",
                                 bool theTransparencyFlag = false,
                                 bool theSpriteFlag = false,
                                 const asl::Vector4f & theColor = asl::Vector4f(1.0, 1.0, 1.0, 1.0));

dom::NodePtr createLambertMaterial(y60::ScenePtr theScene,
                                   const asl::Vector4f & theDiffuseColor = asl::Vector4f(1.0, 1.0, 1.0, 1.0),
                                   const asl::Vector4f & theAmbientColor = asl::Vector4f(0.0, 0.0, 0.0, 1.0));

dom::NodePtr createColorMaterial(y60::ScenePtr theScene,
                                 const asl::Vector4f & theColor = asl::Vector4f(1.0, 1.0, 1.0, 1.0));

dom::NodePtr createTransform(dom::NodePtr theParentNode);
dom::NodePtr createBody(dom::NodePtr theParentNode, const std::string & theShapeId);

/**
 * Creates a canvas in the scene given in theScene
 * @param theScene Scene to create canvas in
 * @param theCanvasId Id of the canvas to create or "" if the Id should be autogenerated
 * @return Newly created canvas Node
 */
dom::NodePtr createCanvas(y60::ScenePtr theScene, const std::string & theCanvasId);
dom::NodePtr createQuad(y60::ScenePtr theScene, const std::string & theMaterialId,
                        asl::Vector3f theTopLeftCorner, asl::Vector3f theBottomRightCorner);

dom::NodePtr createCrosshair(y60::ScenePtr theScene, const std::string & theMaterialId,
                             float theInnerRadius, float theHairLength,
                             const std::string & theName = "CrosshairShape");

dom::NodePtr
createDistanceMarkup(y60::ScenePtr, const std::string & theMaterialId,
                     const asl::Vector3f & thePointA,  const asl::Vector3f & thePointB,
                     const std::string & theName = "DistanceMarkupShape");
dom::NodePtr
createDistanceMarkup(y60::ScenePtr, const std::string & theMaterialId,
                     const std::vector<asl::Vector3f> & thePositions,
                     const std::string & theName = "DistanceMarkupShape");
dom::NodePtr
createAngleMarkup(y60::ScenePtr theScene, const std::string & theMaterialId,
                  const asl::Vector3f & theApex,
                  const asl::Vector3f & thePointA,  const asl::Vector3f & thePointB,
                  bool theOuterAngleFlag, const std::string & theName = "AngleMarkupShape");


dom::NodePtr
createTriangleMeshMarkup(y60::ScenePtr theScene, const std::string & theLineMaterialId,
                         const std::string & theAreaMaterialId,
                         const std::vector<asl::Vector3f> & thePositions,
                         const std::string & theName = "TriangleMeshMarkupShape") ;

/** Creates a stack of quads used for volumetric rendering */
dom::NodePtr createQuadStack(y60::ScenePtr theScene, const asl::Vector3i & theDimensions,
                     float theSize, const std::string & theMaterialId,
                     const std::string theName = "QuadStack");

dom::NodePtr
createLineStrip(y60::ScenePtr theScene, const std::string & theLineMaterialId,
                         const std::vector<asl::Vector3f> & thePositions,
                         const std::vector<asl::Vector2f> & theTexCoords = std::vector<asl::Vector2f>(),
                         const std::vector<asl::Vector4f> & theColors = std::vector<asl::Vector4f>()) ;

dom::NodePtr
createQuadStrip(y60::ScenePtr theScene, const std::string & theMaterialId,
                         const std::vector<asl::Vector3f> & thePositions,
                         const std::vector<asl::Vector2f> & theTexCoords = std::vector<asl::Vector2f>(),
                         const std::vector<asl::Vector4f> & theColors = std::vector<asl::Vector4f>()) ;

dom::NodePtr
createStrip(const std::string & theType, y60::ScenePtr theScene, 
        const std::string & theMaterialId,
        const std::vector<asl::Vector3f> & thePositions,
        const std::vector<asl::Vector2f> & theTexCoords,
        const std::vector<asl::Vector4f> & theColors); 

dom::NodePtr createVoxelProxyGeometry(y60::ScenePtr theScene, const asl::Box3f & theVoxelBox,
                                      const asl::Matrix4f & theModelMatrix, const asl::Matrix4f & theCameraMatrix,
                                      const asl::Vector3i & theVolumeSize, float theSampleRate,
                                      const std::string & theMaterialId, const std::string & theName);

struct PlanePosition {
    PlanePosition(const asl::Point3f & theOrigin,
                  const asl::Vector3f & theXVector,
                  const asl::Vector3f & theYVector) :
        _myOrigin(theOrigin),
        _myXVector(theXVector),
        _myYVector(theYVector)
    {}
    PlanePosition() : _myOrigin(0, 0, 0),
        _myXVector(1, 0, 0),
        _myYVector(0, 1, 0)
    {}

    asl::Vector3f operator()(unsigned x, unsigned y) const {
        return _myOrigin + _myXVector * float(x) + _myYVector * float(y);
    }
private:

    const asl::Point3f  _myOrigin;
    const asl::Vector3f _myXVector;
    const asl::Vector3f _myYVector;
};


struct CircularPosition {
    CircularPosition(const asl::Point3f & theOrigin,
                     const float & theRadius,
                     const float & theStepSize /*,
                     const asl::Vector3f & theCircleNormal*/) : // DS: TODO: this would be nice to have.
                                                                //     Currently the circle is created in the XY-Plane
        _myOrigin(theOrigin),
        _myRadius(theRadius),
        _myStepSize(theStepSize)
    {}

    asl::Vector3f operator() (unsigned t) {
        return _myOrigin + asl::Vector3f(sin(t * _myStepSize) * _myRadius,
                                         cos(t * _myStepSize) * _myRadius,0.0);
    }
private:
    const asl::Point3f  _myOrigin;
    const float         _myRadius;
    const float         _myStepSize;
    const asl::Vector3f _myNormal;
};

// theVertices should be ordered like:
// 0 1 2 3
// 4 5 6 7
// 8 9 10 11
struct ArbitraryPlanePosition {
    ArbitraryPlanePosition(const std::vector<asl::Vector3f> & theVertices, unsigned theXCount,
        unsigned theYCount) :
            _myVertices(theVertices),
            _myXCount(theXCount)
    {
        if (_myVertices.size() < theXCount * theYCount) {
            throw asl::Exception("Number of vertices in vertex array is less than xcount * ycount",
                PLUS_FILE_LINE);
        }
    }

    asl::Vector3f operator()(unsigned x, unsigned y) const {
        return _myVertices[y * _myXCount + x];
    }
private:
    const std::vector<asl::Vector3f> & _myVertices;
    unsigned _myXCount;
};


struct NoisePlanePosition {
    NoisePlanePosition(const asl::PerlinNoise2D & theNoiseFunction,
                       const asl::Point3f & theOrigin,
                       const asl::Vector3f & theXVector,
                       const asl::Vector3f & theYVector,
                       const asl::Vector2f & theXSampleVector,
                       const asl::Vector2f & theYSampleVector,
                       const float & theAmplitude) :
        _myNoise(theNoiseFunction),
        _myOrigin(theOrigin),
        _myXSampleVector(theXSampleVector),
        _myYSampleVector(theYSampleVector),
        _myXVector(theXVector),
        _myYVector(theYVector),
        _myAmplitude(theAmplitude)
    {}
        /*
    asl::Vector3f operator()(unsigned x, unsigned y) const {
        asl::Vector2f myPos = _myXSampleVector * float(x) + _myYSampleVector * float(y);
        float myValue = _myNoise(myPos) * _myAmplitude;
        asl::Vector3f myPosition = _myOrigin + _myXVector * float(x) + _myYVector * float(y);
        myPosition[2] = myValue;
        return myPosition;

    }
    */

    asl::Vector3f operator()(unsigned x, unsigned y) const {
        return calcPosition(float(x), float(y));
    }

    asl::Vector3f calcPosition(const float &x, const float & y) const {
        asl::Vector2f myPos = _myXSampleVector * x + _myYSampleVector * y;
        asl::Vector3f myPosition = _myOrigin + _myXVector * x + _myYVector * y;
        myPosition[2] = _myNoise(myPos) * _myAmplitude;
        return myPosition;
    }

protected:
    const asl::Vector2f _myXSampleVector;
    const asl::Vector2f _myYSampleVector;
private:
    asl::PerlinNoise2D  _myNoise;
    const asl::Point3f  _myOrigin;
    const asl::Vector3f _myXVector;
    const asl::Vector3f _myYVector;
    const float         _myAmplitude;
};

struct JitterPlanePosition : public NoisePlanePosition {
    JitterPlanePosition(const asl::PerlinNoise2D & theNoiseFunction,
                       const asl::Point3f & theOrigin,
                       const asl::Vector3f & theXVector,
                       const asl::Vector3f & theYVector,
                       const asl::Vector2f & theXSampleVector,
                       const asl::Vector2f & theYSampleVector,
                       const float & theAmplitude,
                       const float & theJitter) :
        NoisePlanePosition(theNoiseFunction, theOrigin, theXVector,
                theYVector, theXSampleVector, theYSampleVector, theAmplitude),
                _myJitter(theJitter)
    {}

    asl::Vector3f operator()(unsigned x, unsigned y) const {
        float myJitteredX = float(x) + float(rand())/float(RAND_MAX)*_myJitter*2.0f-_myJitter;
        float myJitteredY = float(y) + float(rand())/float(RAND_MAX)*_myJitter*2.0f-_myJitter;
        // std::cerr << "Jitter from "<<x<<","<<y<< " => " << myJitteredX<< ", " << myJitteredY << std::endl;
        return calcPosition(myJitteredX, myJitteredY);
    }
private:
    float _myJitter;
};

struct ConstPosition {
    ConstPosition(const asl::Point3f & theOrigin) :
        _myOrigin(theOrigin){}
    ConstPosition() : _myOrigin(0, 0, 0) {}

    asl::Vector3f operator()(unsigned x, unsigned y) const {
        return _myOrigin;
    }
private:
    const asl::Point3f  _myOrigin;
};

struct ConstNormal {
    ConstNormal(const asl::Vector3f & theNormal) : _myNormal(theNormal) {}
    ConstNormal() : _myNormal(0.f, 0.f, 1.f) {}

    asl::Vector3f operator()(unsigned x, unsigned y) const {
        return _myNormal;
    }
private:
    const asl::Vector3f _myNormal;
};

struct PlaneUVCoord {
    PlaneUVCoord(const asl::Point2f & theOrigin,
                  const asl::Vector2f & theXVector,
                  const asl::Vector2f & theYVector) :
        _myOrigin(theOrigin),
        _myXVector(theXVector),
        _myYVector(theYVector)
    {}
    PlaneUVCoord() :
        _myOrigin(0., 0.),
        _myXVector(1., 0.),
        _myYVector(0., 1.)
    {}
    PlaneUVCoord(unsigned myXSubdivisions, unsigned myYSubdivisions) :
        _myOrigin(0., 0.),
        _myXVector(1.f / myXSubdivisions, 0.),
        _myYVector(0., 1.f / myYSubdivisions)
    {}
    asl::Vector2f operator()(unsigned x, unsigned y) const {
        return _myOrigin + _myXVector * float(x) + _myYVector * float(y);
    }
private:
    const asl::Point2f  _myOrigin;
    const asl::Vector2f _myXVector;
    const asl::Vector2f _myYVector;
};

// theTexCoords should be ordered like:
// 0 1 2 3
// 4 5 6 7
// 8 9 10 11
struct ArbitraryUVCoord {
    ArbitraryUVCoord(const std::vector<asl::Vector2f> & theTexCoords, unsigned theXCount, unsigned theYCount) :
        _myTexCoords(theTexCoords), _myXCount(theXCount)
    {
        if (theTexCoords.size() != (theXCount * theYCount)) {
            throw asl::Exception("Number of texcoords doesn't match xcount * ycount", PLUS_FILE_LINE);
        }
    }

    asl::Vector2f operator()(unsigned x, unsigned y) const {
        return _myTexCoords[y * _myXCount + x];
    }
private:
    const std::vector<asl::Vector2f> & _myTexCoords;
    unsigned _myXCount;
};

struct BlackColor {
    asl::Vector4f operator()(unsigned x, unsigned y) const {
        return asl::Vector4f(0,0,0,1);
    }
};

struct WhiteColor {
    asl::Vector4f operator()(unsigned x, unsigned y) const {
        return asl::Vector4f(1,1,1,1);
    }
};

struct ConstColor {
    ConstColor(const asl::Vector4f & theColor) : _myColor(theColor) {}
    ConstColor() : _myColor(1.f, 1.f, 1.f, 1.f) {}

    asl::Vector4f operator()(unsigned x, unsigned y) const {
        return _myColor;
    }
private:
    const asl::Vector4f _myColor;
};

struct GradiantColor {
    GradiantColor(const asl::Vector4f & theStart, const asl::Vector4f & theEnd,
                 unsigned theLength) :
        _myStart(theStart), _myEnd(theEnd), _myLenght(theLength) {}

    asl::Vector4f operator()(unsigned x, unsigned y) const {
        return _myStart * (float(x) / _myLenght) + _myEnd * (1 - (float(x) / _myLenght));
    }
private:
    const asl::Vector4f & _myStart;
    const asl::Vector4f & _myEnd;
    unsigned              _myLenght;
};

struct ExponentialColorGradient {
    ExponentialColorGradient(const asl::Vector4f & theStart, const asl::Vector4f & theEnd,
                 unsigned theLength, float thePower) :
        _myStart(theStart), _myEnd(theEnd), _myLength(theLength), _myPower(thePower) {}

    asl::Vector4f operator()(unsigned x, unsigned y) const {
        return _myStart + (_myEnd - _myStart) * pow((float(x) / _myLength), _myPower);
    }
private:
    const asl::Vector4f & _myStart;
    const asl::Vector4f & _myEnd;
    unsigned              _myLength;
    float                 _myPower;
};


// TODO:
// - Find a way to make default functions work
// - Find a way to create plane without color, texture, etc.
template <
    class THE_INDEX_BUILDER,
    class THE_POSITION_FUNCTION,
    class THE_NORMAL_FUNCTION,
    class THE_UV_FUNCTION,
    class THE_COLOR_FUNCTION>
dom::NodePtr
createPlane(y60::ScenePtr theScene, unsigned theXCount, unsigned theYCount,
            const std::string & theName,
            const std::string & theMaterialId,
            THE_INDEX_BUILDER theIndexBuilder,
            THE_POSITION_FUNCTION thePositionFunction = PlanePosition(),
            THE_NORMAL_FUNCTION theNormalFunction = ConstNormal(),
            THE_UV_FUNCTION theUVFunction = PlaneUVCoord(),
            THE_COLOR_FUNCTION theColorFunction = BlackColor())
{
    ShapeBuilder myShapeBuilder(theName);
    theScene->getSceneBuilder()->appendShape(myShapeBuilder);

    // UH: the ShapeBuilder:: prefix is necessary for gcc to work
    const unsigned myCount = theXCount * theYCount;
    myShapeBuilder.ShapeBuilder::createVertexDataBin<asl::Vector3f>(POSITION_ROLE, myCount);
    myShapeBuilder.ShapeBuilder::createVertexDataBin<asl::Vector3f>(NORMAL_ROLE, myCount);
    myShapeBuilder.ShapeBuilder::createVertexDataBin<asl::Vector4f>(COLOR_ROLE, myCount);
    myShapeBuilder.ShapeBuilder::createVertexDataBin<asl::Vector2f>("uvset", myCount);

    appendToPlane(myShapeBuilder, theXCount, theYCount, theMaterialId, theIndexBuilder,
                  thePositionFunction, theNormalFunction, theUVFunction, theColorFunction, 0);

    return myShapeBuilder.getNode();
}


/** this function can be used to append further elements to
    a plane created with createPlane().

    Example:
    myPlane = createPlane( ... );

    ShapeBuilder myBuilder(myPlane);

    appendToPlane(myBuilder, ..., myIndexOffset);

    where myIndexOffset is normaly the number of vertices in the plane
    before adding new ones. You can use smaller values for myIndexOffset
    to overdraw the same elements with a diffrent material. I don't know if
    this is of any use.
*/

template <
    class THE_INDEX_BUILDER,
    class THE_POSITION_FUNCTION,
    class THE_NORMAL_FUNCTION,
    class THE_UV_FUNCTION,
    class THE_COLOR_FUNCTION>
dom::NodePtr
appendToPlane(ShapeBuilder & theShapeBuilder,
            unsigned theXCount, unsigned theYCount,
            const std::string & theMaterialId,
            THE_INDEX_BUILDER theIndexBuilder,
            THE_POSITION_FUNCTION thePositionFunction = PlanePosition(),
            THE_NORMAL_FUNCTION theNormalFunction = ConstNormal(),
            THE_UV_FUNCTION theUVFunction = PlaneUVCoord(),
            THE_COLOR_FUNCTION theColorFunction = BlackColor(),
            unsigned theIndexOffset = 0)
{
    const unsigned myCount = theXCount * theYCount;
    ElementBuilder myElementBuilder(theIndexBuilder.getType(), theMaterialId);

    theShapeBuilder.appendElements(myElementBuilder);
    myElementBuilder.createIndex(POSITION_ROLE, POSITIONS, myCount);
    myElementBuilder.createIndex(NORMAL_ROLE, NORMALS, myCount);
    myElementBuilder.createIndex(COLOR_ROLE, COLORS, myCount);
    myElementBuilder.createIndex("uvset", getTextureRole(0), myCount);
    theIndexBuilder.createIndices(myElementBuilder, theXCount, theYCount, theIndexOffset);

    for (unsigned y = 0; y < theYCount; ++y) {
        for (unsigned x = 0; x < theXCount; ++x) {
            theShapeBuilder.appendVertexData(POSITION_ROLE, thePositionFunction(x, y));
            theShapeBuilder.appendVertexData(NORMAL_ROLE, theNormalFunction(x, y));
            theShapeBuilder.appendVertexData(COLOR_ROLE, theColorFunction(x, y));
            theShapeBuilder.appendVertexData("uvset", theUVFunction(x, y));
        }
    }

    return theShapeBuilder.getNode();
}

// WARNING:the
// Only use this function on shapes you have created with createPlane()
template <
    class THE_POSITION_FUNCTION,
    class THE_NORMAL_FUNCTION,
    class THE_UV_FUNCTION,
    class THE_COLOR_FUNCTION>
void
updatePlane(dom::NodePtr theShapeNode, unsigned theXCount, unsigned theYCount,
      THE_POSITION_FUNCTION thePositionFunction = PlanePosition(),
      THE_NORMAL_FUNCTION theNormalFunction = ConstNormal(),
      THE_UV_FUNCTION theUVFunction = PlaneUVCoord(),
      THE_COLOR_FUNCTION theColorFunction = BlackColor())
{
    ShapePtr myShape = theShapeNode->dom::Node::getFacade<y60::Shape>();
    if (!myShape) {
        throw asl::Exception(std::string("Node is not a shape: ") +
            asl::as_string(*theShapeNode), PLUS_FILE_LINE);
    }
    //myShape->setDirty(true);

    dom::NodePtr myVertexData = theShapeNode->childNode(VERTEX_DATA_NAME);

    dom::NodePtr myPositionsNode;
    dom::NodePtr myNormalsNode;
    dom::NodePtr myColorsNode;
    dom::NodePtr myUVCoordsNode;
    for (unsigned i = 0; i < myVertexData->childNodesLength(); ++i) {
        dom::NodePtr myChild = myVertexData->childNode(i);
        dom::NodePtr myText  = myChild->childNode("#text");
        const std::string myName  = myChild->getAttributeString(NAME_ATTRIB);

        if (myName == POSITION_ROLE) {
            myPositionsNode = myText;
        } else if (myName == NORMAL_ROLE) {
            myNormalsNode = myText;
        } else if (myName == COLOR_ROLE) {
            myColorsNode = myText;
        } else if (myName == "uvset") {
            myUVCoordsNode = myText;
        }
    }

    if (!myPositionsNode || !myNormalsNode || !myColorsNode || !myUVCoordsNode) {
        throw asl::Exception(std::string("Node does not contain positions and") +
            "colors and normals and uvcoords: " +
            asl::as_string(*theShapeNode), PLUS_FILE_LINE);
    }

    dom::Node::WritableValue<VectorOfVector3f> myPositionsLock(myPositionsNode);
    dom::Node::WritableValue<VectorOfVector3f> myNormalsLock(myNormalsNode);
    dom::Node::WritableValue<VectorOfVector4f> myColorsLock(myColorsNode);
    dom::Node::WritableValue<VectorOfVector2f> myUVCoordsLock(myUVCoordsNode);

    VectorOfVector3f & myPositions = myPositionsLock.get();
    VectorOfVector3f & myNormals   = myNormalsLock.get();
    VectorOfVector4f & myColors    = myColorsLock.get();
    VectorOfVector2f & myUVCoords  = myUVCoordsLock.get();

    unsigned myCounter = 0;
    for (unsigned y = 0; y < theYCount; ++y) {
        for (unsigned x = 0; x < theXCount; ++x) {
            myPositions[myCounter] = thePositionFunction(x, y);
            myNormals[myCounter]   = theNormalFunction(x, y);
            myColors[myCounter]    = theColorFunction(x, y);
            myUVCoords[myCounter]  = theUVFunction(x, y);
            myCounter++;
        }
    }
}

void smoothNormals(dom::NodePtr theShape);
/// \@}
}

#endif // AC_Y60_GEOMETRY_FUNCTIONS_INCLUDED

