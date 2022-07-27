// File: App.hpp
// Description: Entry Class after DiyMetric.ino
// Responsible for controlling the workflow of the App
//
//

#ifndef _APP_H_
#define _APP_H_

#include <stdio.h>
#include "include/WifiConnection.hpp"
#include "include/Time.hpp"


class App : public WifiCallback{
    private:
        bool stopRequested = false;

    public:
        App();
        virtual ~App();
        void Setup();
        void Init();
        void Update();
        void Render();
        void Loop();
        void Exit();

        // Wifi related methods - WifiConnection needs to be implemented here
         void onWifiConnectedCallback();
         void onWifiConnectingCallback();
         void onWifiActiveCallback();
};

// Default Constructor
App::App(){}
App::~App(){}

// dont touch this method unless absolutely needed
void App::Setup(){
    Serial.begin(9600);
    Init();

    Time::setupDeltaTimeCalculation();
}

// dont touch this method unless absolutely needed
void App::Loop(){
    Time::calculateDeltaTime();
    
    Update();
    Render();

    if(stopRequested){
        Exit();
    }

    delay(50); // optional

}

// Variables
WifiConnection wifiConn;

// Edit after this line:
// -------------------------------------------------------------

//
void App::Init(){
    wifiConn.Setup("SSID", "Password");
    wifiConn.Connect();
    wifiConn.setWifiCallback(this);

    // TODO: Implement own code after comment

}

void App::Update(){
    wifiConn.waitForConnection(); // mandatory

    // TODO: Implement own code after comment
    
}

void App::onWifiConnectingCallback(){
    // TODO: Implement own code after comment

    Serial.println("WIFI connecting");
}

// This method is triggered once when connection state changes to Connected.
void App::onWifiConnectedCallback(){
    // TODO: Implement own code after comment

    Serial.println("WIFI State changed to connected");
}

// This method is always called when connection is active. 
// It is equivalent of Update, but is only and always run when connection is established.
// Might cause some issues/artifacts when connection is being dropped.
void App::onWifiActiveCallback(){
// TODO: Implement own code after comment


}

void App::Render(){
    // TODO: Implement own code after comment

}


void App::Exit(){
    // TODO: Implement own code after comment

}


#endif