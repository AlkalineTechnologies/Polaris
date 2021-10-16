#include <Window.h>
#include <App.h>

int main() {
    Polaris::App *app = Polaris::App::AllocateNew();
    Polaris::Window window("Hello, world!");
    window.show();
    app->run();
    return 0;
}
