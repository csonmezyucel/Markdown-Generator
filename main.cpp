// Code by Cevat Sonmez Yucel
#include <iostream>
#include <fstream>
#include <string>
#include "MD.h"

using std::cout;
using std::string;
using std::cin;
using std::ws;

int main() {
    MD myMD;
    cout << "Welcome to Markdown Generator.\n";

    // Interface to generate Markdown
    while (true) {
        cout << "---------------------------------------\n";
        cout << "nb -- Type in default formatted text\n";
        cout << "h -- Type a heading\n";
        cout << "i -- Type in italics\n";
        cout << "s -- Type strong (usually bold) text\n";
        cout << "st -- Type strikethrough ( ̶e̶x̶a̶m̶p̶l̶e̶) text\n";
        cout << "hl -- Add a horizontal line\n";
        cout << "bq -- Type inside a blockquote\n";
        cout << "l -- Type a link\n";
        cout << "ul -- Type an unordered list\n";
        cout << "ol -- Type an ordered list\n";
        cout << "im -- Add an image\n";
        cout << "p -- Preview contents\n";
        cout << "r -- Remove item\n";
        cout << "cl -- Change location of item\n";
        cout << "done -- Generate Markdown\n";
        cout << "---------------------------------------\n";
        string command;
        cin >> command;
        if (command == "done") {
            break;
        }
        if (command == "nb") {
            cout << "Please type in desired text: ";
            string userInput;
            getline(cin >> ws, userInput);
            myMD.body(userInput);
        }
        if (command == "h") {
            cout << "1 being largest and 6 being smallest, choose size of heading: ";
            string size;
            cin >> size;
            cout << "Please type in desired text: ";
            string userInput;
            getline(cin >> ws, userInput);
            if (size == "1") {
                myMD.headings1(userInput);
            }
            else if (size == "2") {
                myMD.headings2(userInput);
            }
            else if (size == "3") {
                myMD.headings3(userInput);
            }
            else if (size == "4") {
                myMD.headings4(userInput);
            }
            else if (size == "5") {
                myMD.headings5(userInput);
            }
            else if (size == "6") {
                myMD.headings6(userInput);
            }
            else {
                cout << "INVALID SIZE\n";
            }
        }

        if (command == "i") {
            cout << "Please type in desired text: ";
            string userInput;
            getline(cin >> ws, userInput);
            myMD.italics(userInput);
        }

        if (command == "s") {
            cout << "Please type in desired text: ";
            string userInput;
            getline(cin >> ws, userInput);
            myMD.strong(userInput);
        }

        if (command == "st") {
            cout << "Please type in desired text: ";
            string userInput;
            getline(cin >> ws, userInput);
            myMD.strikeThrough(userInput);
        }

        if (command == "hl") {
            myMD.horizontalRule();
        }

        if (command == "bq") {
            cout << "Please type in desired text: ";
            string userInput;
            getline(cin >> ws, userInput);
            myMD.blockQuote(userInput);
        }

        if (command == "l") {
            cout << "URL: ";
            string url;
            cin >> url;
            cout << "Name: ";
            string name;
            getline(cin >> ws, name);
            cout << "Add hovering name to link? (y/n) ";
            string option;
            cin >> option;
            if (option == "y") {
                cout << "Hovering Name: ";
                string hover;
                cin >> hover;
                myMD.link(url, name, hover);
            }
            if (option == "n") {
                myMD.link(url, name);
            }
            else {
                cout << "Invalid option\n";
            }
        }

        if (command == "ul") {
            cout << "Number of elements: ";
            int numberOfElements;
            cin >> numberOfElements;
            for (int i = 0; i < numberOfElements; i++) {
                cout << "Please type in desired text for element " << i + 1 << ": ";
                string userInput;
                getline(cin >> ws, userInput);
                myMD.unorderedList(userInput);
            }
        }

        if (command == "ol") {
            cout << "Number of elements: ";
            int numberOfElements;
            cin >> numberOfElements;
            for (int i = 0; i < numberOfElements; i++) {
                cout << "Please type in desired text for element " << i + 1 << ": ";
                string userInput;
                getline(cin >> ws, userInput);
                myMD.orderedList(userInput);
            }
        }

        if (command == "im") {
            cout << "Link to image: ";
            string url;
            cin >> url;
            cout << "Name: ";
            string name;
            getline(cin >> ws, name);
            myMD.image(name, url);
        }

        if (command == "p") {
            myMD.preview();
        }

        if (command == "r") {
            cout << "Item to remove: ";
            int index;
            cin >> index;
            index--;
            myMD.removeElement(index);
        }

        if (command == "cl") {
            cout << "Item to move: ";
            int itemIndex;
            cin >> itemIndex;
            cout << "Location to move to: ";
            int targetIndex;
            cin >> targetIndex,
            itemIndex--;
            targetIndex--;
            myMD.changeElementLocation(itemIndex, targetIndex); 
        }
    }

    // Generates file with user specified name and places it in the same directory as the code
    cout << "File name (without .md): ";
    string fileName;
    getline(cin >> ws, fileName);
    fileName += ".md";
    std::ofstream myfile;
    myfile.open(fileName);
    for (int i = 0; i < myMD.toPrint.size(); i++) {
        myfile << myMD.toPrint[i];
        myfile << "\n";
        myfile << "\n";
    }
    myfile.close();
    return 0;
}