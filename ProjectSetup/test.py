# from urllib import response
import requests

# download zip  assets from github releases https://api.github.com/repos/plasmarad/LoveLetter/releases/latest/ 46025963

release = requests.get("https://api.github.com/repos/plasmarad/LoveLetter/releases/latest")

# f = (requests.get('https://api.github.com/repos/plasmarad/LoveLetter/releases/latest').json()['id'])
browser_download_url = release.json()['assets'][0]['browser_download_url']
# response.json
print(browser_download_url)
# import requests
open ('src.zip','wb').write(requests.get(browser_download_url).content)
# response = requests.get("https://api.github.com/repos/v2ray/v2ray-core/releases/latest")
# print(response.json()["name"])