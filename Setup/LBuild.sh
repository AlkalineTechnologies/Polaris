# Compile the Polaris engine [LINUX ONLY]

echo "Compiling the Polaris engine..."

cd ./../Engine/Build/

g++ -std=c++2a ./../**/**.cpp -I.. -pthread -c

cd ./../../Setup/