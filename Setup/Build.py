import os

_EngineDir = os.path.join(os.path.dirname(os.path.realpath(__file__)), "../Engine")
# g++ -std=c++2a ./../**/**.cpp -I.. -pthread -c

class OSBuildProfile:
    Compiler    = ""
    StandardVer = ""
    Files       = []
    Includes    = []
    Libs        = []
    Flags       = []
    Defines     = []

    def __init__(self, **kwargs):
        self.Compiler    = kwargs["compiler"]
        self.StandardVer = kwargs["standard"]
        self.Files       = kwargs["files"]
        self.Includes    = kwargs["includes"]
        self.Libs        = kwargs["libs"]
        self.Flags       = kwargs["flags"]
        self.Defines     = kwargs["defines"]

    def CMD(self) -> str:
        cmd = self.Compiler                 + " "
        cmd += " ".join(self.Files)         + " -I"
        cmd += " -I".join(self.Includes)    + " "
        cmd += " ".join(self.Libs)          + " "
        cmd += " ".join(self.Flags)         + " "
        cmd += " ".join(self.Defines)       + " "
        return cmd

if os.name == 'posix':
    os.makedirs(os.path.join(_EngineDir, "Build"), exist_ok=True)

    _LinuxProfile =  OSBuildProfile(compiler= "g++", standard= "c++2a", 
    
    files       = [os.path.join(_EngineDir, "**", "*.cpp"), ], 
    includes    = [_EngineDir], 
    libs        = [], 
    flags       = ["-pthread", "-c"], 
    defines     = [])

    os.chdir(os.path.join(_EngineDir, "Build"))
    os.system(_LinuxProfile.CMD())

    print("Finished.")

if os.name == 'nt':
    pass
if os.name == 'mac':
    pass