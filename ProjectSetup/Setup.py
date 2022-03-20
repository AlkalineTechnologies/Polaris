# basic project setup script created by: @plasmarad
import os
import requests
import zipfile

print("██████╗░░█████╗░██╗░░░░░░█████╗░██████╗░██╗░██████╗\n"
      "██╔══██╗██╔══██╗██║░░░░░██╔══██╗██╔══██╗██║██╔════╝\n"
      "██████╔╝██║░░██║██║░░░░░███████║██████╔╝██║╚█████╗░\n"
      "██╔═══╝░██║░░██║██║░░░░░██╔══██║██╔══██╗██║░╚═══██╗\n"
      "██║░░░░░╚█████╔╝███████╗██║░░██║██║░░██║██║██████╔╝\n"
      "╚═╝░░░░░░╚════╝░╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝╚═════╝░\n")

print ("[Command Line Project Setup (alpha)]\n\n")

class Setup_Project():
    def __init__(self):
        self.Name           = input("Project Name:  ")
        self.Author         = input("Author:        ")
        self.Description    = input("Description:   ")
        self.Version        = input("Version:       ")
        self.Path           = input("Path:          ")
        self.ProjectDir     = os.path.join(self.Path, self.Name)

        self.Create_Project()
        
    def Create_Project(self):
        try:
            _tmp_src_name = "tmp.zip"
            os.mkdir(self.ProjectDir)
            
            fetch = requests.get("https://api.github.com/repos/PolarisEngine/Polaris/releases/latest")
            browser_download_url = fetch.json()['assets'][0]['browser_download_url']
            
            open (os.path.join(self.ProjectDir, _tmp_src_name), 'wb').write(requests.get(browser_download_url).content)
            
            with zipfile.ZipFile(os.path.join(self.ProjectDir, _tmp_src_name), 'r') as zip_ref:
                zip_ref.extractall(self.ProjectDir)
            
            os.remove(os.path.join(self.ProjectDir, _tmp_src_name))
        except OSError as error:
            print("Error in generating project: " + str(error))
