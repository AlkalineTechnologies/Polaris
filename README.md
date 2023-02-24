> ![polaris_banner.png](assets/polaris_LOGO_white_strip.png)


# ***P O L A R I S***
*Realiable application framework for easier development*

> **Warning**
> As of currently, developedment has been halted due to insuficient resources.

## ***Introducing PCLT***
`PCLT` is a command line tool that allows you to manage your polaris project, and swap components/modules.
`PCLT` also doubles as a ***(future)*** package manager which (plans to) deal with dependencies  ~~(and licensing)~~

# ***How To Build***
```shell
cd      bin
cmake   ..
make    .
```
> ```make``` is optional, you can use ```cmake --build .``` instead
> You can also (to speed up build times) use ```cmake --build . --parallel```
> or even use mold as the linker (if you have it installed, in order to speed up build times even more)
# Libraries used in this project
In order to make PCLT, these wonderful opensource libraries have been used.
although their licenses are included, I want to give more credit to these project 


## Libraries and their repository
| name | url |
|------|-----|
| nlohmann/json | https://github.com/nlohmann/json |
| p-ranav/argparse | https://github.com/p-ranav/argparse |
| libcurl | https://curl.se/libcurl/ |
| libzip | https://libzip.org |

> **Note**
> Please raise an issue if the dependencies are outdated
