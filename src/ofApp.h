#pragma once

#include "ofMain.h"
#include "TreeSeg.hpp"
#include "BranchingType.hpp"
#include "ofxDatGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void windowResized(int w, int h);
    
    //recursive function
    void generate(ofVec3f startLoc, ofVec3f vel, BranchingType type, int times);

    //BranchingType consists of rotation angles and Types of children spawned
    vector<BranchingType>types;//
    
    //Stick contains start and end points of a "stick" - lines displayed
    vector<TreeSeg>sticks; //vector of TreeSegments/branches, to be optimized in future
    

    

    //ceate pointers to GUI objects
    ofxDatGui* brGui;
    
    ofxDatGuiDropdown* typesDropdown;
    
    ofxDatGuiSlider* sliderX; //rotations arouns x,y,z
    ofxDatGuiSlider* sliderY;
    ofxDatGuiSlider* sliderZ;
    ofxDatGuiSlider* sliderLength; //length
    ofxDatGuiSlider* sliderRecursions;
    ofxDatGuiMatrix* typesMatrix; //buttons for types
    
    ofxDatGuiSlider* sliderLineWidth;
    ofxDatGuiColorPicker* colorPicker;
    
    
    ofxDatGuiHeader* brGuiHeader;
    ofxDatGuiFooter* brGuiFooter;
    
//    ofFbo fbo;
    
    
    void onSliderEvent(ofxDatGuiSliderEvent e);
    void onDropdownEvent(ofxDatGuiDropdownEvent e);
    void onMatrixEvent(ofxDatGuiMatrixEvent e);
    void onColorPickerEvent(ofxDatGuiColorPickerEvent e);

    void drawTree();

    vector< vector<int> >ChildrenTp;//Children Types
    
    int selectedType;
    int numRecursions=3;
    int sticksIndex;
    bool treeDrawn = false;//not used at the moment
    
    vector<ofColor> guiColors;

};
