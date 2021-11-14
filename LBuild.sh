#Linux


# In order to build this script please give it the execute permission:
#   sudo chmod +x LBuild.sh

cd ./Library/Linux/build


#     Linux/*.cpp   Linux/Library   X11 library
#           |             |           |
#           |             |           |
#           v             v           v
g++ -g -c ../*.cpp     -I../../     -lX11           -pthread


echo compilation has finished.