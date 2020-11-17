#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    //https://gist.github.com/tuxmartin/1218851b7e025f68ecc50f949c9dd332
    Poco::Net::HTTPClientSession websocket("127.0.0.1",4444);    
    Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, "/?encoding=text",Poco::Net::HTTPMessage::HTTP_1_1);
    request.set("origin", "http://www.websocket.org");
    Poco::Net::HTTPResponse response;
    
    try {
        m_psock = new Poco::Net::WebSocket(websocket, request, response);
        
    } catch (std::exception &e) {
        std::cout << "Exception " << e.what();
    }
    
    
    
}

void ofApp::exit(){
    m_psock->close();
}


//--------------------------------------------------------------
void ofApp::update(){
    
    
}



//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString("key 1 and 2 to switch between scenes", 10, 10);
}

void ofApp::switchToScene(string _scene){
    
    try {
        ofJson myJson;
        myJson["request-type"] = "SetCurrentScene";
        myJson["message-id"] = "idSetScenes";
        myJson["scene-name"] = _scene;
        
        ofLog()<<"myJson "<<myJson;
        string json_str = ofToString(myJson);
        ofLog()<<"json_str.c_str() "<<json_str.c_str();
        
        const char *testStr = json_str.c_str();
        
        int len=m_psock->sendFrame(testStr,strlen(testStr),Poco::Net::WebSocket::FRAME_TEXT);
        std::cout << "Sent bytes " << len << std::endl;
        int flags=0;
        
        char receiveBuff[256];
        int rlen=m_psock->receiveFrame(receiveBuff,256,flags);
        std::cout << "Received bytes " << rlen << std::endl;
        std::cout << receiveBuff << std::endl;
        
    } catch (std::exception &e) {
        std::cout << "Exception " << e.what();
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    
    if(key == '1'){
        
        switchToScene("cam_scene");
        
    }
    if(key == '2'){
        switchToScene("file_scene");
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

void ofApp::gotMessage(ofMessage msg)
{
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
