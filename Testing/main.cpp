#include <Window.h>
#include <Game.h>

int main() {
    Polaris::Game *app = Polaris::Game::AllocateNew();
    Polaris::Window window("Hello, world!");
    window.show();
    app->run();
    return 0;
}
