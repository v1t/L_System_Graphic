//
//  BranchingType.hpp
//  mySketch
//
//  Created by Vytautas Niedvaras on 12/11/2015.
//
//

#ifndef BranchingType_hpp
#define BranchingType_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* BranchingType_hpp */

//Type class, holds angles of rotation around x,y,z for velocity vector(what is added after every step of recursion)

//also hold childrenTypes - which types will be called after step of recursion(based (or is?) L-system).

class BranchingType {
    
private:
    
    float length;
    float strokeWeight;
    ofVec3f angles;
    vector<int> childrenTypes;
    
public:
    
    BranchingType(ofVec3f _angles, vector<int> _childrenTypes);
    
    void setAngles(ofVec3f _newAngles);
    
    float* getAngleX();
    float* getAngleY();
    float* getAngleZ();
    float* getLength();
    float* getStrokeWeight();
    
   void setAngleX(float setX);
   void setAngleY(float setY);
   void setAngleZ(float setZ);
   void setLength (float lng);
    void setStrokeWeight(float strWeight);
    
    vector<int> getChildrenTypes();
    int getNumChildren();
    
    void setChildrenTypes(vector<int> newChildrenTypes);
};