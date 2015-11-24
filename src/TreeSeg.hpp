//
//  TreeSeg.hpp
//  mySketch
//
//  Created by Vytautas Niedvaras on 12/11/2015.
//
//

#ifndef TreeSeg_hpp
#define TreeSeg_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* TreeSeg_hpp */

//class that holds start and end points of the stick,
//also a function to draw them out.
//To be optimized in the future, ofDrawLine method seems to be very slow. 

class TreeSeg{
    
private:
    
    ofVec3f startPt;
    ofVec3f endPt;
    int type;
    ofColor* typeColor;
    float* lineW;
    
public:
    
    TreeSeg();
    void display();

    void setStartPt(ofVec3f *newStartPt);
    void setEndPt(ofVec3f *newEndPt);
    
    void setType(int *generatedByType);
    int* getType();
    
    void setTypeColor(ofColor *typeCol);
    
    void setLineWidth(float *lineWidth);
};

