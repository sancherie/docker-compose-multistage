#include <iostream>
#include "app/ConfigBuilder.hpp"
#include "app/Application.hpp"

int main(int ac, char **av)
{
    Config config = ConfigBuilder(ac, av).build();
    Application application(config);

    application.start();
    return 0;
}