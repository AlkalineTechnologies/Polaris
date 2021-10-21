// use the event loop in here from XLib

//
// Created by Lysander Mealy on 10/16/21.
//


#include <Game.h>


#include <thread>
//I removed everything cocoa related
namespace Polaris {
     app;

    Game::~Game() = default;

    Game::Game() {
        delete _instance;

        
        _native = 
        

        app = _native;

        _instance = this;
    }

    Game *Game::AllocateNew() {
        return new Game();
    }

    void Game::run() {
        
    }

    Game *Game::getInstance() {
        return _instance;
    }

    void *Game::getNative() {
        return _native;
    }

    Game *Game::_instance = nullptr;
}

