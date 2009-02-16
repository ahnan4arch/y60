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
// !!!!!!! AUTOMATICALLY GENERATED FILE - ONLY PERFORM CHANGES IN THE !!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!! CORRESPONDING XSD FILE !!!!!!!!!!!!!!!!!!!!!!!!!

#include <string>
std::string ourShaderLibraryxsd = std::string(
"<?xml version='1.0' encoding='utf-8' ?>\n"
"<xs:schema xmlns:xs='http://www.w3.org/2001/XMLSchema'>\n"
"    <xs:simpleType name='Point3f'>\n"
"        <xs:restriction base='xs:string'/>\n"
"    </xs:simpleType>\n"
"    <xs:simpleType name='Vector3f'>\n"
"        <xs:restriction base='xs:string'/>\n"
"    </xs:simpleType>\n"
"    <xs:simpleType name='Vector4f'>\n"
"        <xs:restriction base='xs:string'/>\n"
"    </xs:simpleType>\n"
"    <xs:simpleType name='Vector2f'>\n"
"        <xs:restriction base='xs:string'/>\n"
"    </xs:simpleType>\n"
"    <xs:simpleType name='Vector2i'>\n"
"        <xs:restriction base='xs:string'/>\n"
"    </xs:simpleType>\n"
"    <xs:simpleType name='VectorOfVector2i'>\n"
"        <xs:restriction base='xs:string'/>\n"
"    </xs:simpleType>\n"
"    <xs:simpleType name='VectorOfVector2f'>\n"
"        <xs:restriction base='xs:string'/>\n"
"    </xs:simpleType>\n"
"    <xs:simpleType name='VectorOfVector3f'>\n"
"        <xs:restriction base='xs:string'/>\n"
"    </xs:simpleType>\n"
"    <xs:simpleType name='VectorOfVector4f'>\n"
"        <xs:restriction base='xs:string'/>\n"
"    </xs:simpleType>\n"
"    <xs:simpleType name='VectorOfFloat'>\n"
"        <xs:restriction base='xs:string'/>\n"
"    </xs:simpleType>\n"
"    <xs:simpleType name='VectorOfString'>\n"
"        <xs:restriction base='xs:string'/>\n"
"    </xs:simpleType>\n"
"    <xs:simpleType name='VectorOfVectorOfString'>\n"
"        <xs:restriction base='xs:string'/>\n"
"    </xs:simpleType>\n"
"    <xs:simpleType name='Matrix4f'>\n"
"        <xs:restriction base='xs:string'/>\n"
"    </xs:simpleType>\n"
"    <xs:simpleType name='VectorOfBlendFunction'>\n"
"        <xs:annotation>\n"
"            <xs:documentation>Type for a vector of blendfunction enum values. Legal values:\n"
"One of the following Enum values:\n"
"- one\n"
"- zero\n"
"- dst_color\n"
"- src_color\n"
"- one_minus_dst_color\n"
"- one_minus_src_color\n"
"- src_alpha\n"
"- one_minus_src_alpha\n"
"- dst_alpha\n"
"- one_minus_dst_alpha\n"
"- src_alpha_saturate\n"
"- constant_color\n"
"- one_minus_constant_color\n"
"- constant_alpha\n"
"- one_minus_constant_alpha\n"
"Example:\n"
"[src_alpha, one_minus_src_alpha]</xs:documentation>\n"
"        </xs:annotation>\n"
"        <xs:restriction base='xs:string'/>\n"
"    </xs:simpleType>\n"
"    <xs:element name='properties'>\n"
"        <xs:complexType>\n"
"            <xs:sequence minOccurs='0' maxOccurs='unbounded'>\n"
"                <xs:element ref='float'/>\n"
"                <xs:element ref='point3f'/>\n"
"                <xs:element ref='vector2f'/>\n"
"                <xs:element ref='vector3f'/>\n"
"                <xs:element ref='vector4f'/>\n"
"                <xs:element ref='matrix4f'/>\n"
"                <xs:element ref='vectorofvector2f'/>\n"
"                <xs:element ref='vectorofvector4f'/>\n"
"                <xs:element ref='vectoroffloat'/>\n"
"                <xs:element ref='vectorofstring'/>\n"
"                <xs:element ref='sampler1d'/>\n"
"                <xs:element ref='sampler2d'/>\n"
"                <xs:element ref='sampler3d'/>\n"
"                <xs:element ref='samplerCUBE'/>\n"
"                <xs:element ref='vectorofblendfunction'/>\n"
"            </xs:sequence>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='float'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='xs:float'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                    <xs:attribute name='function' type='xs:string'/>\n"
"                    <xs:attribute name='register' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='sampler1d'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='xs:int'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='sampler2d'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='xs:int'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='sampler3d'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='xs:int'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='vectorofvector2f'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='VectorOfVector2f'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='vectorofvector4f'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='VectorOfVector4f'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='vectoroffloat'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='VectorOfFloat'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='vectorofstring'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='VectorOfString'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='samplerCUBE'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='xs:int'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='vector4f'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='Vector4f'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                    <xs:attribute name='function' type='xs:string'/>\n"
"                    <xs:attribute name='register' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='matrix4f'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='Matrix4f'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                    <xs:attribute name='function' type='xs:string'/>\n"
"                    <xs:attribute name='register' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='point3f'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='Point3f'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='vector2f'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='Vector2f'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                    <xs:attribute name='function' type='xs:string'/>\n"
"                    <xs:attribute name='register' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='vector3f'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='Vector3f'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                    <xs:attribute name='function' type='xs:string'/>\n"
"                    <xs:attribute name='register' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='shaders'>\n"
"        <xs:complexType>\n"
"            <xs:sequence>\n"
"                <xs:element ref='shader'/>\n"
"            </xs:sequence>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='shader'>\n"
"        <xs:complexType>\n"
"            <xs:sequence>\n"
"                <xs:element ref='supports'/>\n"
"                <xs:element ref='fragmentshader'/>\n"
"                <xs:element ref='vertexshader'/>\n"
"                <xs:element ref='fixedfunctionshader'/>\n"
"            </xs:sequence>\n"
"            <xs:attribute name='name' type='xs:string'/>\n"
"            <xs:attribute name='id' type='xs:ID'/>\n"
"            <xs:attribute name='cost' type='xs:float'/>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='supports'>\n"
"        <xs:complexType>\n"
"            <xs:sequence>\n"
"                <xs:element ref='feature'/>\n"
"            </xs:sequence>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='feature'>\n"
"        <xs:complexType>\n"
"            <xs:attribute name='class' type='xs:IDREF'/>\n"
"            <xs:attribute name='values' type='VectorOfString'/>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:complexType name='CgShader'>\n"
"        <xs:attribute name='profiles' type='VectorOfString'/>\n"
"        <xs:attribute name='files' type='VectorOfString'/>\n"
"        <xs:attribute name='entryfunctions' type='VectorOfString'/>\n"
"        <xs:attribute name='compilerargs' type='VectorOfVectorOfString' use='optional'/>\n"
"    </xs:complexType>\n"
"    <xs:element name='fragmentshader'>\n"
"        <xs:complexType>\n"
"            <xs:sequence minOccurs='0' maxOccurs='1'>\n"
"                <xs:element ref='properties'/>\n"
"            </xs:sequence>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='CgShader'/>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='vertexshader'>\n"
"        <xs:complexType>\n"
"            <xs:sequence minOccurs='0' maxOccurs='1'>\n"
"                <xs:element ref='properties'/>\n"
"                <xs:element ref='vertexparameters'/>\n"
"            </xs:sequence>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='CgShader'/>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='fixedfunctionshader'>\n"
"        <xs:complexType>\n"
"            <xs:sequence minOccurs='0' maxOccurs='1'>\n"
"                <xs:element ref='properties'/>\n"
"                <xs:element ref='vertexparameters'/>\n"
"            </xs:sequence>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='CgShader'/>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='vertexparameters'>\n"
"        <xs:complexType>\n"
"            <xs:sequence minOccurs='0' maxOccurs='unbounded'>\n"
"                <xs:element ref='vector2f'/>\n"
"                <xs:element ref='vector3f'/>\n"
"                <xs:element ref='vector4f'/>\n"
"                <xs:element ref='float'/>\n"
"                <xs:element ref='sampler2d'/>\n"
"            </xs:sequence>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='combiners'>\n"
"        <xs:complexType>\n"
"            <xs:sequence>\n"
"                <xs:element ref='combiner'/>\n"
"            </xs:sequence>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='combiner'>\n"
"        <xs:complexType>\n"
"            <xs:attribute name='name' type='xs:string'/>\n"
"            <xs:attribute name='id' type='xs:ID'/>\n"
"            <xs:sequence>\n"
"                <xs:element ref='combineRGB' minOccurs='0' maxOccurs='1'/>\n"
"                <xs:element ref='combineAlpha' minOccurs='0' maxOccurs='1'/>\n"
"            </xs:sequence>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:complexType name='combineChannel'>\n"
"        <xs:attribute name='mode' type='xs:string'/>\n"
"        <xs:attribute name='scale' type='xs:float'/>\n"
"        <xs:sequence>\n"
"            <xs:element ref='arg0' minOccurs='0' maxOccurs='1'/>\n"
"            <xs:element ref='arg1' minOccurs='0' maxOccurs='1'/>\n"
"            <xs:element ref='arg2' minOccurs='0' maxOccurs='1'/>\n"
"        </xs:sequence>\n"
"    </xs:complexType>\n"
"    <xs:element name='combineRGB'>\n"
"        <xs:complexType>\n"
"            <xs:complexContent>\n"
"                <xs:extension base='combineChannel'/>\n"
"            </xs:complexContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='combineAlpha'>\n"
"        <xs:complexType>\n"
"            <xs:complexContent>\n"
"                <xs:extension base='combineChannel'/>\n"
"            </xs:complexContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:complexType name='combineArgument'>\n"
"        <xs:attribute name='source' type='xs:string'/>\n"
"        <xs:attribute name='operand' type='xs:string'/>\n"
"    </xs:complexType>\n"
"    <xs:element name='arg0'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='combineArgument'/>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='arg1'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='combineArgument'/>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='arg2'>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='combineArgument'/>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"    <xs:element name='vectorofblendfunction'>\n"
"        <xs:annotation>\n"
"            <xs:documentation>This element contains a vector of blendfunction enum values as text child.\n"
"Example:\n"
"&lt;vectorofblendfunction&gt;[src_alpha, one_minus_src_alpha]&lt;/vectorofblendfunction&gt;</xs:documentation>\n"
"        </xs:annotation>\n"
"        <xs:complexType>\n"
"            <xs:simpleContent>\n"
"                <xs:extension base='VectorOfBlendFunction'>\n"
"                    <xs:attribute name='name' type='xs:string'/>\n"
"                </xs:extension>\n"
"            </xs:simpleContent>\n"
"        </xs:complexType>\n"
"    </xs:element>\n"
"</xs:schema>\n"
);
