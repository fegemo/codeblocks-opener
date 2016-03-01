#include <iostream>
#include <cstdlib>

using namespace std;

string removeProtocolFromURI(string uri, string protocol) {
    return uri.substr(protocol.length() + 1);
}

int main(int argc, char** argv)
{

    cout << "Abrindo projeto no CodeBlocks..." << endl;

    string codeBlocks = string("C:\\Program Files (x86)\\CodeBlocks\\codeblocks.exe");
    cout << "\t- caminho para CodeBlocks: " << codeBlocks << endl;

    if (argc < 2) {
        cout << endl << "Programa executado com apenas " << argc << " argumento(s). Necessario pelo menos 2." << endl << endl << endl;
        system("pause");
        return -1;
    }
    string project = removeProtocolFromURI(string(argv[1]), "codeblocks");
    cout << "\t- nome do projeto: " << project << endl;

    string examplesPath = string("C:\\Users\\Flavio\\Documents\\GitHub\\cefet-cg-exemplos-opengl\\");
    cout << "\t- pasta com exemplos: " << examplesPath << endl;

    string command = string("start \"") + codeBlocks + "\" \"" + examplesPath + project + "\"";
    cout << "\t- comando: " << command << endl;

    cout << "  " << examplesPath << project << endl << endl;

    system(command.c_str());
    return 0;
}
