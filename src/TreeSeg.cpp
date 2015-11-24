//
//  TreeSeg.cpp
//  mySketch
//
//  Created by Vytautas Niedvaras on 12/11/2015.
//
//

#include "TreeSeg.hpp"

TreeSeg::TreeSeg(){
    
}


void TreeSeg::display(){

    ofPushStyle();
    ofSetLineWidth(*lineW);
    ofSetColor(*typeColor);
    ofDrawLine(startPt, endPt);
    ofPopStyle();

}


void TreeSeg::setStartPt(ofVec3f *newStartPt){
    startPt = *newStartPt;
}

void TreeSeg::setEndPt(ofVec3f *newEndPt){
    endPt = *newEndPt;
}

void TreeSeg::setType(int *generatedByType){
    type = *generatedByType;
}

int* TreeSeg::getType(){
    return &type;
}

void TreeSeg::setTypeColor(ofColor *typeCol){
    typeColor = typeCol;
}


void TreeSeg::setLineWidth(float *lineWidth){
    lineW = lineWidth;
}