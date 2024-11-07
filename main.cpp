#include "binarytree.h"
#include "tree.h"
#include <iostream>
#include <sstream>
#include <fstream> 

using namespace std;

int main(int argc, char* argv[]){
     
     /** 
    if (argc != 2){
        //err correct usage
        cerr << "Usage: ./MAIN <I-File>\n";
        cerr << "<I-File> is the input file\n";
        //exit with error code 
        return 1;
    }
    
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << argv[1] << endl;
        return 1;
    }
   
    
    inputFile >> commandNum;

    **/

    BINARY_TREE* binary_tree = new BINARY_TREE;
    binary_tree->root = nullptr;
    int commandNum = 0;
    cin >> commandNum;
    cin.ignore();
   // cout << "\n";
    //reading number of the commands
    for (int instructions = 0; instructions <= commandNum; ++instructions){
        string command;
        getline(cin, command);
        if(command.substr(0, 6) == "INSERT"){
            stringstream s(command);
            string cmd;
            int value;
            s>>cmd>>value;
            binary_tree = insertNode(value, binary_tree);
        }
        else if(command.substr(0, 6) == "DELETE"){
            stringstream s(command);
            
            string cmd;
            int value;
           
            s>>cmd>>value;
            binary_tree = deleteNode(value, binary_tree);
        }
        else if(command.find("INORDER")!=string::npos){
            inorder(binary_tree->root);
            //cout << "\n";
        }
        else if(command.find("PREORDER")!=string::npos){
            preorder(binary_tree->root);
           // cout << "\n";
        }
        else if(command.find("POSTORDER")!=string::npos){
            postorder(binary_tree->root);
            //cout << "\n";
        }
        else if(command.find("LEVELORDER")!=string::npos) {
            levelorder(binary_tree);
           //cout << "\n";
        }
        else if(command.substr(0, 6) == "SEARCH"){
            stringstream s(command);
            string cmd;
            int value;
            s >> cmd >> value;
            searchTree(binary_tree->root, value);
           // cout << "\n";
        } 
    }
    delete binary_tree;
    //cout << "\n";
    return 0;
}