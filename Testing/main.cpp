// C++ standard library
#include <unistd.h>
#include <iostream>
#include <future>
//polaris library
#include <Window.h>
#include <Game.h>
#include <Inputs.h>

int main() {
    
    // instantiate a polaris window in an async thread using a future

    Polaris::Window w3("E", 800, 600, false, true);
    Polaris::Window window("A", 800, 600, false, true);

    // we need to find a way of running the window 
    std::future<void> f2 = std::async(std::launch::async,  &Polaris::Window::EventLoop, &w3);
    std::future<void> f3 = std::async(std::launch::async,  &Polaris::Window::EventLoop, &window);


    Polaris::Game *game = Polaris::Game::CreateNew();

    Polaris::InputHandler input(w3.getInputStream(), Polaris::InputHandler::INPUT_TYPE::KEYBOARD);
    game->frameCap = 60;
    game->run();
}