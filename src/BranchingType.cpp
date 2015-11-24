//
//  BranchingType.cpp
//  mySketch
//
//  Created by Vytautas Niedvaras on 12/11/2015.
//
//

#include "BranchingType.hpp"

BranchingType::BranchingType(ofVec3f _angles,  vector<int> _childrenTypes): angles    (_angles), childrenTypes(_childrenTypes){
    length = 30;
    strokeWeight = 2;
}

//setters/getters for angles
void BranchingType::setAngles(ofVec3f newAngles){
    angles = newAngles;
}


float* BranchingType::getAngleX(){
    return &(angles.x);
}

float* BranchingType::getAngleY(){
    return &(angles.y);
}

float* BranchingType::getAngleZ(){
    return &(angles.z);
}

float* BranchingType::getLength(){
    return &(length);
}

float* BranchingType::getStrokeWeight(){
    return &(strokeWeight);
}


//--------

void BranchingType::setAngleX(float setX){
    angles.x = setX;
}

void BranchingType::setAngleY(float setY){
    angles.y = setY;
}

void BranchingType::setAngleZ(float setZ){
    angles.z = setZ;
}

void BranchingType::setLength(float lng){
    length = lng;
}

void BranchingType::setStrokeWeight(float strWeight){
    strokeWeight = strWeight;
}

//--------


//---------


//--------------

vector<int> BranchingType::getChildrenTypes(){
    
    return childrenTypes;
}


void BranchingType::setChildrenTypes(vector<int> newChildrenTypes){
    
    childrenTypes = newChildrenTypes;
}

int BranchingType::getNumChildren(){
    
    return childrenTypes.size();
}

