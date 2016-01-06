#include <iostream>
#include <cstdlib>

using namespace std;

string removeProtocolFromURI(string uri, string protocol) {
    return uri.substr(protocol.length() + 1);
}

int main(int argc, char** argv)
{

    string codeBlocks = string("C:\\Program Files (x86)\\CodeBlocks\\codeblocks.exe");
    string project = removeProtocolFromURI(string(argv[1]), "codeblocks");
    string examplesPath = string("C:\\Users\\Flavio\\Documents\\GitHub\\cefet-cg-exemplos-opengl\\");
    string command = string("start \"") + codeBlocks + "\" \"" + examplesPath + project + "\"";

    cout << "Abrindo projeto no CodeBlocks..." << endl;
    cout << "  " << examplesPath << project << endl << endl;

    system(command.c_str());
    return 0;
}
