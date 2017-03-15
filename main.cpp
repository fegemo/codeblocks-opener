#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;

string removeProtocolFromURI(string uri, string protocol) {
    return uri.substr(protocol.length() + 1);
}

void loadConfigVariables(const char* configPath, map<string, string>& config) {
    string line;
    ifstream configFileStream(configPath);
    if (configFileStream.is_open()) {
        while (getline(configFileStream, line)) {
            unsigned int equalsSignPosition = line.find('=');
            if (equalsSignPosition == string::npos) {
                // não há sinal de = na linha - linha inválida
                continue;
            }

            string key = line.substr(0, equalsSignPosition);
            string value = line.substr(key.size() + 1, line.size() - key.size() + 1);
            config.insert(pair<string, string>(key, value));
        }
    }
    configFileStream.close();
}

int main(int argc, char** argv)
{
    map<string, string> config;

    // carrega a configuração - onde está o codeblocks, onde está a pasta com os projetos de exemplo
    cout << "Lendo arquivo de configuração...\n";
    loadConfigVariables("../../config.properties", config);
    string codeBlocksExecutablePath = config["caminhoParaCodeBlocks"];
    string projectsFolderPath = config["caminhoParaProjetos"];
    string codeBlocksArguments = config["argumentosCodeBlocks"];
    cout << "\t- caminho para CodeBlocks: " << codeBlocksExecutablePath << "\n";
    cout << "\t- caminho para projetos: " << projectsFolderPath << endl;


    cout << "Abrindo projeto no CodeBlocks..." << endl;
    if (argc < 2) {
        cout << "\nPrograma executado com apenas " << argc << " argumento(s). Necessario pelo menos 2.\n\n" << endl;
        system("pause");
        return -1;
    }
    string projectFolderName = removeProtocolFromURI(string(argv[1]), "codeblocks");
    cout << "\t- nome do projeto: " << projectFolderName << endl;
#ifdef LINUX
    string command = string("exec ") + codeBlocksExecutablePath + " " + codeBlocksArguments + " " + projectsFolderPath + "/" + projectFolderName;
#endif
#ifdef WINDOWS
    string command = string("start \"") + codeBlocksExecutablePath + "\" \"" + projectsFolderPath + projectFolderName + "\"";
#endif
    cout << "\t- comando: " << command << endl;

    cout << "  " << projectsFolderPath << projectFolderName << "\n" << endl;

    system(command.c_str());
    return 0;
}
