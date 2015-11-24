#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    guiColors.resize(7);
    guiColors[0].set(239, 83, 80); //~red
    guiColors[1].set(174, 213, 129); //~light green
    guiColors[2].set(255, 235, 59); //~yellow
    guiColors[3].set(255, 152, 0); //~orange
    guiColors[4].set(179, 229, 252); //~light blue
    guiColors[5].set(233, 30, 99); //~pink
    guiColors[6].set(186, 104, 200); //~purple
    
    sticks.resize(10000000);
    
    brGui = new ofxDatGui( ofxDatGuiAnchor::TOP_RIGHT );
    
    
    //create initial types;
    vector<string> dropDownTypes = {"Type - 1", "Type - 2", "Type - 3", "Type - 4", "Type - 5", "Type - 6", "Type - 7"};

    //add Types vector to gui drop down:
    typesDropdown = brGui->addDropdown("Select Type:", dropDownTypes);
    typesDropdown->select(0);//select initial type
    
    
    //add sliders
    sliderX = brGui->addSlider("RotateX", -180, 180);
    sliderY = brGui->addSlider("RotateY", -180, 180);
    sliderZ = brGui->addSlider("RotateZ", -180, 180);
    
    brGui->addBreak(10.0);//add a gap in GUI
    sliderLength = brGui->addSlider("Length", 0, 200);
    
    brGui->addBreak(10.0);
    //add buttons 1-7;
    typesMatrix = brGui->addMatrix("Children Types", 7, true);
    
    //add recursions slider
    sliderRecursions = brGui->addSlider("Recursions", 0, 30);
    sliderRecursions->setPrecision(0);
    sliderRecursions->bind(&numRecursions, 0, 30);
    
    //add color picker
    brGui->addBreak(10.0);
    colorPicker = brGui->addColorPicker("Type Color");
    colorPicker->setColor(guiColors[0]);
    
    //add strokeWeight slider
    sliderLineWidth = brGui->addSlider("Type Line Weight", 0.01, 10, 2);
    
    //add header - allows to drag UI around
    //footer allows to colapse it
    brGuiHeader = brGui->addHeader("Branching Controls");
    brGuiFooter = brGui->addFooter();
    
    
    //register callbacks to listen for component events
    brGui->onSliderEvent(this, &ofApp::onSliderEvent);
    brGui->onDropdownEvent(this, &ofApp::onDropdownEvent);
    brGui->onMatrixEvent(this, &ofApp::onMatrixEvent);
    brGui->onColorPickerEvent(this, &ofApp::onColorPickerEvent);
    
  
    //generate empty 2D nested vector 7*7 size
    //to store 7 button states for 7 types
    ChildrenTp.resize(7);
    for (int i = 0; i<ChildrenTp.size(); i++) {
        ChildrenTp[i].resize(7);
        ChildrenTp[i] = {};
    }
    
    //Initial values for first types:
    ChildrenTp[0] = {0,1};
    ChildrenTp[1] = {0,1};
    
    
    //generate BranchingType objects with initial ChildrenTypes
    for(int i=0; i<ChildrenTp.size(); i++){
        types.push_back(BranchingType(ofVec3f(0), ChildrenTp[i]));
    }
    
    //update button matrix with initial state;
    typesMatrix->setSelected(ChildrenTp[0]);
    
    //bind sliders to initial type - 1;
    sliderX->bind(types[0].getAngleX(), -180, 180);
    sliderY->bind(types[0].getAngleY(), -180, 180);
    sliderZ->bind(types[0].getAngleZ(), -180, 180);
    sliderLength->bind(types[0].getLength(), -200, 200);
    sliderLineWidth->bind(types[0].getStrokeWeight(), 0.01, 10);
    //ofSetBackgroundAuto(false);
    ofBackground(0);
}



//callback events:

void ofApp::onColorPickerEvent(ofxDatGuiColorPickerEvent e){
    guiColors[selectedType] = e.color;
}

void ofApp::onSliderEvent(ofxDatGuiSliderEvent e){
    
}

void ofApp::onDropdownEvent(ofxDatGuiDropdownEvent e){
    //go through all drop down options (available types)
    //re-bind x,y,z sliders to control values in diferent types
    for(int i=0; i<typesDropdown->size(); i++){
        if (e.target->getSelected() == (typesDropdown->getChildAt(i))) {
            
            selectedType = i;
            sliderX->bind(types[i].getAngleX(), -180, 180);

            sliderY->bind(types[i].getAngleY(), -180, 180);
            sliderZ->bind(types[i].getAngleZ(), -180, 180);
            sliderLength->bind(types[i].getLength(), -200, 200);
            sliderLineWidth->bind(types[i].getStrokeWeight(), 0.01, 10);
            
            typesMatrix->setSelected(types[i].getChildrenTypes());
            colorPicker->setColor(guiColors[i]);
            
        }
    }
    treeDrawn = false;

}



void ofApp::onMatrixEvent(ofxDatGuiMatrixEvent e){
    types[selectedType].setChildrenTypes(typesMatrix->getSelected());
    treeDrawn = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    fbo.allocate(ofGetWidth(), ofGetHeight());
//    fbo.begin();
//    fbo.clear();
//    
//    for(int i=0; i<sticksIndex-1; i++){ //go through all sticks, display, to be changed with for_each in the future
//        sticks[i].TreeSeg::display();
//    }
//    
//    fbo.end();
//    
//    cout<<fbo.getWidth()<<" "<<ofGetWidth()<<endl;
    

    
}

void ofApp::windowResized(int w, int h){
    
  //  fbo.allocate(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawTree();
    drawTree();
}


void ofApp::drawTree(){
    
    sticksIndex = 0;
    generate(ofVec3f(0), ofVec3f(0, 30, 0), types[0], numRecursions);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
 
    for(int i=0; i<sticksIndex-1; i++){ //go through all sticks, display, to be changed with for_each in the future
        sticks[i].TreeSeg::display();
    }

    ofPopMatrix();
    treeDrawn = true;

}

//------------------------


//recursive function, takes starting position, velocity(whats added after every recursion), type(rotation angles and childrenTypes called and Int times - recursion steps.
void ofApp::generate(ofVec3f startLoc, ofVec3f vel, BranchingType type, int times){
    

    vector<int> childrenTypeIndexes = type.getChildrenTypes();//get vector<int>, stated which types will be called lso how many times void generate() will call itself during one step of recursion.
    
    times--; //base case
    if (times>0) {
        for (int i=0; i<childrenTypeIndexes.size(); i++) {  //change with for_all in future
            
            ofVec3f velCopy = vel;

            //scale length based on Type lenght;
            velCopy =velCopy.getScaled(*(types[childrenTypeIndexes[i]].getLength()));

            //Rotate Velocity around X,Y,Z (vector thats added to start location after every recursion).
            
            velCopy.rotate(*(types[childrenTypeIndexes[i]].getAngleX()), *(types[childrenTypeIndexes[i]].getAngleY()), *(types[childrenTypeIndexes[i]].getAngleZ()));

            ofVec3f endLoc = startLoc+velCopy;
            
            //add rotated vel vector to starting location to get endLocation of the stick
            
            sticks[sticksIndex].setStartPt(&startLoc);
            sticks[sticksIndex].setEndPt(&endLoc);
            sticks[sticksIndex].setType(&childrenTypeIndexes[i]);
            sticks[sticksIndex].setTypeColor(&(guiColors[childrenTypeIndexes[i]]));
            sticks[sticksIndex].setLineWidth(types[childrenTypeIndexes[i]].getStrokeWeight());
            sticksIndex++;

            //function calls itself. newly generated endLoc as starting position and rotated velocity vector for next step
            generate(endLoc, velCopy, types[childrenTypeIndexes[i]], times);
            
        }
    }
    
    
}


