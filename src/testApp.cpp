#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    ofBackground(0,0,0);
    ofSetLogLevel(OF_LOG_VERBOSE);

    
    universalScale.x=universalScale.y=1;
    sceneNumber=1;
    
    loadandConvertTexture("mapimage.png");
    
    river_thickness=1.3;
    
    ofDisableArbTex();
    
    
    glEnable (GL_DEPTH_TEST);
	glShadeModel (GL_SMOOTH);
    
	glColorMaterial (GL_FRONT_AND_BACK, GL_DIFFUSE);
	glEnable (GL_COLOR_MATERIAL);
    
    Model.loadModel("cone2.dae");
   // Model.setRotation(0, 40,2, 1, 0);
    
    tex = Model.getTextureForMesh(0);
    Material = Model.getMaterialForMesh(0);
    
    
}

//--------------------------------------------------------------
void testApp::update()
{

    
}

//--------------------------------------------------------------
void testApp::draw()
{
    ofBackground(0,0,0);
    
    ofScale(universalScale.x,universalScale.y);
    
    loadScene();
    
    
    
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

    if(key=='f')
        ofToggleFullscreen();
    else if(key==OF_KEY_LEFT)
        sceneNumber--;
    else if(key==OF_KEY_RIGHT)
        sceneNumber++;
    else if(key==OF_KEY_UP)
        river_thickness+=0.1;
    else if(key==OF_KEY_DOWN)
        river_thickness-=0.1;
    else if(key==' ')
        startAnimation=!startAnimation;
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::loadScene()
{
    if(sceneNumber==1)
        scene1();
    else if(sceneNumber==4)
        scene4();
    else if(sceneNumber==5)
        scene5();
    else if(sceneNumber==7)
        scene7();
    else if(sceneNumber==10)
        scene10();
}

void testApp::scene1()
{
    
    // 2D Maps ..
    
    ofSetColor(255, 255,255);
    
    
    
    ofEnableSmoothing();
    ofFill();
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight()/2);
    drawCircle();
    
}


void testApp::scene7()
{
    //River Flowing ..
    
    static int i=0;
    
    ofBackground(0,0,0);
    
    ofSetColor(255,255,255);
    ofEnableSmoothing();
    //ofFill();

    ofCircle(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight()/2);
    drawCircle();
    
    
    //ofSetColor(0,0,255);
    ofTranslate(ofGetWidth()/2+300,ofGetHeight()/2); ///Change this ..
    
    ofRotateZ(120);
   
    
    
    
    
    ofScale(8,8);
    
    ofSetColor(0,0,255);
    
    if(startAnimation&&i<1000)
    {
    
        if(i>1)
            
        {
            for (int j=0;j<i;j++)
                ofCircle(j,10*sin(PI/25*j),river_thickness);
        }
        
        float a = PI/25*i;    //determines the wavelength .. i increases lambda increases
        //sine wave
       
                
        ofCircle(i,10*sin(a),river_thickness);
        
        ofSleepMillis(50);
       

        i++;
    }
    

}

void testApp::scene4()
{
    
    // Mountain
    
    
    static int i=0;
    
    ofBackground(0,0,0);
    
    ofSetColor(255,255,255);
    
    //ofEnableSmoothing();
    //ofFill();
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight()/2);
    drawCircle();
    
    
    
    // setting up some random parameters ..
    
    ofNoFill();
  
    ofDisableArbTex();
    
    
    glEnable (GL_DEPTH_TEST);
	glShadeModel (GL_SMOOTH);
    
	glColorMaterial (GL_FRONT_AND_BACK, GL_DIFFUSE);
	glEnable (GL_COLOR_MATERIAL);
    
    
    // setting up some position..right now in the centre of the screen
    Model.setPosition(ofGetWidth()/2, ofGetHeight()/2,0);
    
    
    
    
    tex.bind();
    Material.begin();
    Model.drawFaces();
    Material.end();
    tex.unbind();
    
    
    //ofEnableArbTex();
    
}

void testApp::scene5()
{
    static float i=0; //V.Important controls the Radius of the Circle ....
    
    
    // Scaling Circle ..
    
    ofEnableAlphaBlending();
    
    ofBackground(0,0,0);
    
    ofSetColor(255,255,255);
    
    ofFill();
    
    ofSetColor(139,131,120);
    
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight()/2);
    
    ofSetColor(255,255,255);
    
    //ofScale(i,i);
   
    //ofTranslate(ofGetWidth()/2-i, ofGetHeight()/2-i);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofNoFill();
    
    
    customDrawCircle(i);
    
    
    
    ofDisableAlphaBlending();
    if(i<0.75)
     i+=0.0005; //Parameter to control speed of Scaling The Circle ...
    
}

void testApp::scene10()
{
    // Soil Profile ..
    
    
    static int i=0;
    
    ofEnableAlphaBlending();
    
    ofBackground(0,0,0);
    
    ofSetColor(255,255,255);
    
    ofFill();
    ofSetColor(139,131,120);
    
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight()/2);
   
    ofSetColor(255,255,255);
    ofTranslate(ofGetWidth()/4, ofGetHeight()/4);
    
    ofNoFill();
    
    ofScale(0.5,0.5);
   
    drawCircle();
    
    ofDisableAlphaBlending();
    
    //ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    //ofCircle(ofGetWidth()/2,ofGetHeight()/2,ofGetHeight()/2-100);

}
void testApp::loadandConvertTexture(string imagepath)
{
 
    sqImg.loadImage(imagepath);  // LOAD THE FILES HERE
    circleTexture.allocate(sqImg.width, sqImg.height, GL_RGB);
    circleTexture.loadData(sqImg.getPixels(), sqImg.width, sqImg.height, GL_RGB);
    
    int numPts  = 64;
    float angle = 0.0;
    float step  = TWO_PI / (float)(numPts-1);
    
    
    for(int i = 0; i < numPts; i++){
        
        //get the -1 to 1 values - we will use these for drawing our pts.
        float px = cos(angle);
        float py = sin(angle);
        
        NormCirclePts.push_back( ofPoint(px, py) );
        
        //map the -1 to 1 range produced by cos/sin
        //to the dimensions of the image we need for our texture coords
        float tx = ofMap( px, -1.0, 1.0, 0, circleTexture.getWidth());
        float ty = ofMap( py, -1.0, 1.0, 0, circleTexture.getHeight());
        
        NormCircleCoords.push_back( ofPoint(tx, ty) );
        
        angle += step;
    }

}


void testApp::drawCircle()


{
    

    // Draw A texture as a circle ...
    

    
    circleTexture.bind();
    
    glBegin(GL_POLYGON);
    for(int i = 0; i < NormCirclePts.size(); i++){
        glTexCoord2f(NormCircleCoords[i].x, NormCircleCoords[i].y);
        glVertex2f( NormCirclePts[i].x * ofGetHeight()/2+ofGetWidth()/2,  NormCirclePts[i].y * ofGetHeight()/2+ofGetHeight()/2);
    }
    glEnd();
    
    circleTexture.unbind();
    
    

    
    
}


//////

void testApp::customDrawCircle(float scale)
{
    circleTexture.bind();
    
    glBegin(GL_POLYGON);
    for(int i = 0; i < NormCirclePts.size(); i++){
        glTexCoord2f(NormCircleCoords[i].x, NormCircleCoords[i].y);
        glVertex2f( NormCirclePts[i].x *scale* ofGetHeight()/2, scale* NormCirclePts[i].y * ofGetHeight()/2);
    }
    glEnd();
    
    circleTexture.unbind();
    
    
    
}





/// Useless Function
void testApp::drawPreviousStates(int i)
{
        
    for(int j=0;j<i;j++)
        ofCircle(xCoords[j], yCoords[j],river_thickness);
    

}