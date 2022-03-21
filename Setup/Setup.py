# basic setup script: @plasmarad (github) 

import os
import zipfile
import requests

class Project:
    # inputted variables
    name        = ""
    author      = ""
    description = ""
    version     = ""
    path        = ""
    # non-inputted variables
    ProjectDir  = ""

class Generate_Project(Project):
    def __init__(self, _name, _author, _description, _path):
        Project.name        = _name
        Project.author      = _author
        Project.description = _description
        Project.path        = _path
        Project.ProjectDir  = os.path.join(Project.path, Project.name)

    def create_project():
        try:
            _temp_name = Project.name + ".zip"
            os.mkdir(Project.ProjectDir)

            open (os.path.join(Project.ProjectDir, _temp_name), 'wb').write(requests.get(Generate_Project.fetch_polaris()).content)

            with zipfile.ZipFile(os.path.join(Project.ProjectDir, _temp_name), 'r') as zip_ref:
                zip_ref.extractall(Project.ProjectDir)

            os.remove(os.path.join(Project.ProjectDir, _temp_name))

        except OSError as error:
            print("Error: " + error.strerror)



    def fetch_polaris():
        fetch = requests.get("https://api.github.com/repos/PolarisEngine/Polaris/releases/latest")
        return fetch.json()['assets'][0]['browser_download_url']     

if __name__ == "__main__":
    print(  "██████╗░░█████╗░██╗░░░░░░█████╗░██████╗░██╗░██████╗\n"
            "██╔══██╗██╔══██╗██║░░░░░██╔══██╗██╔══██╗██║██╔════╝\n"
            "██████╔╝██║░░██║██║░░░░░███████║██████╔╝██║╚█████╗░\n"
            "██╔═══╝░██║░░██║██║░░░░░██╔══██║██╔══██╗██║░╚═══██╗\n"
            "██║░░░░░╚█████╔╝███████╗██║░░██║██║░░██║██║██████╔╝\n"
            "╚═╝░░░░░░╚════╝░╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝╚═════╝░\n")

    print ("[Command Line Project Setup (alpha)]\n\n")
    