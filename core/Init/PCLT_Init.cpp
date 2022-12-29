#include <Init/PCLT_Init.hpp>
#include <curl/curl.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <Libraries/json.hpp>

#include <sys/stat.h>
#include <sys/types.h>
#include <zip.h>

using namespace nlohmann;

// call back function for writing data to a string
size_t callback(char *ptr, size_t size, size_t nmemb, void *data){
    std::string *str = (std::string *)data;
    str->append(ptr, size * nmemb);
    return size * nmemb;
}

// function for getting data (as a string) from a URL
std::string GetContentsFromURL(std::string URL=""){
    CURL  *curl;
    CURLcode res;
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "PCLT_CLI_CLIENT/1.0");
    curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());

    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // printf("%s\n", response.c_str());

    res = curl_easy_perform(curl);
    res == CURLE_OK ? 0 : printf("Error: %s\n", curl_easy_strerror(res));
    curl_easy_cleanup(curl);
    return response;
}

// call back function for writing data to a file
size_t fcallback(void *ptr, size_t size, size_t nmemb, FILE *stream){
    return fwrite(ptr, size, nmemb, stream);
}

void DownloadTemplate(std::string Location){
    CURL  *curl = curl_easy_init();
    
    #define RESPONSE GetContentsFromURL("https://api.github.com/repos/AlkalineTechnologies/pclt-template/releases/latest")
    
    std::string TemplateURL = "https://github.com/AlkalineTechnologies/pclt-template/archive/refs/tags/" + json::parse(RESPONSE)["tag_name"].get<std::string>() + ".zip";
    
    curl_easy_setopt(curl, CURLOPT_URL, TemplateURL.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "deflate");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fcallback);

    // create a lambda function append "pclt-template.zip" to a string

    FILE *fp = fopen(std::string(Location += "pclt-template.zip").c_str() , "wb");
    if (fp == NULL){
        printf("Error: Directory given does not exists.\n");
        return;
    }
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    CURLcode ResCode = curl_easy_perform(curl);

    fclose(fp);
    curl_easy_cleanup(curl);
};

void extractZip(std::string ZipLocation, std::string Destination){
    // check if the destination directory exists
    struct stat statbuf;
    if (stat(Destination.c_str(), &statbuf) == -1) {
        return;
    }
    struct zip *z = zip_open(ZipLocation.c_str(), 0, NULL);
    struct zip_file *f;
    struct zip_stat st;
    char *buf;
    int err;
    zip_uint64_t i, num;
    num = zip_get_num_entries(z, 0);
    for (i = 0; i < num; i++) {
        if (zip_stat_index(z, i, 0, &st) == 0) {
            char *buf = new char[st.size];
            f = zip_fopen_index(z, i, 0);
            zip_fread(f, buf, st.size);
            zip_fclose(f);
            std::string FileName = st.name;
            FileName = FileName.substr(FileName.find("/")+1);
            std::ofstream File(Destination + FileName);
            File << buf;
            File.close();
            delete[] buf;
        }
    }
    zip_close(z);
}

void Init_Workspace(argparse::ArgumentParser& program, std::string Location){
    Location[Location.length()-1] == '/' ? 0 : Location += '/';
    
    DownloadTemplate(Location); // download the template

    extractZip(Location + "pclt-template.zip", Location); // extract the zip file
    
    remove((Location + "pclt-template.zip").c_str()); // remove the zip file
}