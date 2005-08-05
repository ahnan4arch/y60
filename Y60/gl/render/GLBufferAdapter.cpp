//=============================================================================
// Copyright (C) 2003, ART+COM AG Berlin
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of ART+COM AG Berlin, and
// are copy protected by law. They may not be disclosed to third parties
// or copied or duplicated in any form, in whole or in part, without the
// specific, prior written permission of ART+COM AG Berlin.
//=============================================================================
//
//   $RCSfile: GLBufferAdapter.cpp,v $
//   $Author: martin $
//   $Revision: 1.7 $
//   $Date: 2005/03/09 17:10:35 $
//
//  Description: This class performs buffer magic.
//
//=============================================================================

#include "GLBufferAdapter.h"

#include <asl/string_functions.h>

#include <y60/PixelEncoding.h>
#include <paintlib/plpngenc.h>
#include <paintlib/pltiffenc.h>
#include <paintlib/planybmp.h>

#include <iostream>

#ifdef WIN32
#   include <windows.h>
#endif

#include <GL/gl.h>

using namespace std;
using namespace asl;

namespace y60 {

    BufferAdaptor::BufferAdaptor (int theWidth, int theHeight, int theComponents) :
                _myWidth(theWidth), _myHeight(theHeight), _myComponents(theComponents) {
        alloc(_myWidth * _myHeight * _myComponents);
    }
    BufferAdaptor::~BufferAdaptor() {
    }

    void 
    BufferAdaptor::alloc(const unsigned myMemorySize) {
        _myData.resize(myMemorySize);
    }
        
    asl::Block &
    BufferAdaptor::getBlock(){
        return _myData;
    }

    const unsigned 
    BufferAdaptor::getWidth() const {
        return _myWidth;
    }

    const unsigned 
    BufferAdaptor::getHeight() const {
        return _myHeight;
    }

    const unsigned 
    BufferAdaptor::getComponents() const {
        return _myComponents;
    }
    
    void
    BufferAdaptor::performAction(GLSourceBuffer theSourceBuffer) {
        switch (theSourceBuffer) {
            case FRAME_BUFFER:
                glReadBuffer(GL_BACK);
                break;
            case DEPTH_BUFFER:
                //break;
            default:
                throw GLBufferAdapterException(std::string("Unknown Sourcebuffer: " ) + asl::as_string(theSourceBuffer),
                                               PLUS_FILE_LINE);
                
        }
        glReadPixels(0, 0, _myWidth, _myHeight, GL_RGBA, GL_UNSIGNED_BYTE, _myData.begin());
}

    // ----------------------------------------------------------------------------------------    
    BufferToFile::BufferToFile (int theWidth, int theHeight, int theComponents) : 
                BufferAdaptor(theWidth, theHeight, theComponents) {
    }
    
    BufferToFile::~BufferToFile() {
    }    
    
    bool 
    BufferToFile::saveBufferAsImage(unsigned theFormat, const std::string & theFileName) {
        PLAnyPicDecoder myDecoder;
        PLAnyBmp myBmp;
        PixelEncoding myEncoding;

        switch(getComponents()) {
          case 1:
              myEncoding = GRAY;
              break;
          case 3:
              myEncoding = RGB;
              break;
          case 4:
              myEncoding = RGBA;
              break;
        }
        PLPixelFormat pf;
        if (!mapPixelEncodingToFormat(myEncoding, pf)) {
            throw GLBufferAdapterException(std::string("unsupported pixel format"), PLUS_FILE_LINE); 
        }
        myBmp.Create( getWidth(), getHeight(), pf, 
                      getBlock().begin() + getWidth() * (getHeight()-1) * getComponents(), -1 * getWidth() * getComponents());
        switch(theFormat) {
            case PL_FT_PNG:
                {
                    PLPNGEncoder myEncoder;
                    myEncoder.MakeFileFromBmp(theFileName.c_str(), &myBmp);               
                }
                break;
             default:
                throw GLBufferAdapterException(std::string("Unknown target image format: " ) + asl::as_string(theFormat),
                                               PLUS_FILE_LINE);
        }
        return true;
    }        
}

