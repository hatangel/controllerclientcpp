// -*- coding: utf-8 -*-
#include <mujincontrollerclient/mujincontrollerclient.h>

#include <iostream>

using namespace mujinclient;

int main(int argc, char ** argv)
{
    try {
        ControllerClientPtr controller;
        if( argc >= 5 ) {
            controller = CreateControllerClient(argv[1], argv[2], argv[3], argv[4]);
        }
        if( argc == 4 ) {
            controller = CreateControllerClient(argv[1], argv[2], argv[3]);
        }
        else if( argc == 3 ) {
            controller = CreateControllerClient(argv[1], argv[2]);
        }
        else {
            controller = CreateControllerClient(argv[1]);
        }
        std::cout << "connected to controller v" << controller->GetVersion() << std::endl;

        //std::string sourcefilename = "../share/mujincontrollerclient/densowave_wincaps_data/threegoaltouch/threegoaltouch.WPJ";
        //std::string sourcefilename = "F:\\dev\\densowave\\wincaps\\rc8test\\test0\\test0.WPJ";
        std::string sourcefilename = "F:\\dev\\densowave\\wincaps\\レイアウト評価\\レイアウト評価.WPJ";
        controller->SyncUpload_UTF8(sourcefilename, "mujin:/testupload/", "wincaps");
        //SceneResourcePtr scene = controller->RegisterScene("mujin:/densowave_wincaps_data/threegoaltouch/threegoaltouch.WPJ", "wincaps");
    }
    catch(const MujinException& ex) {
        std::cout << "exception thrown: " << ex.message() << std::endl;
    }
    ControllerClientDestroy();
}