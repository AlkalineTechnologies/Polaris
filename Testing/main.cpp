// C++ standard library
#include <unistd.h>
#include <iostream>
#include <future>
//polaris library
#include <Window.h>
#include <Game.h>
#include <Inputs.h>

int main() {
    
    //make two polaris windows
    Polaris::Window     w3("(1) Window", 800, 600, false, true);
    Polaris::Window window("(2) Window", 800, 600, false, true);

    // each window has an event loop, in order for multiple windows to appear on screen each window's event loop must run asynchronously...
    // below is a primitive example as to what i am refering.
    std::future<void>   f2 = std::async(std::launch::async,  &Polaris::Window::EventLoop, &w3);
    std::future<void>   f3 = std::async(std::launch::async,  &Polaris::Window::EventLoop, &window);


    Polaris::Game *game = Polaris::Game::CreateNew();

    //Each window has an input stream (like how each window has an event loop), The input handler object is a way of interpreting the Input Stream from
    // each window...
    
    //in the case below we are reading the input from the w3 window. and we read the keyboard input.
    Polaris::InputHandler input(w3.getInputStream(), Polaris::InputHandler::INPUT_TYPE::KEYBOARD);
    
    // initalize the game object (there will be an APP object in the future too)
    game->frameCap = 60;
    game->run();
}
