// Code by Cevat Sonmez Yucel
#include "MD.h"

// Generates Markdown for normal body text
void MD::body(std::string s) {
    toPrint.push_back(s);
    userInput.push_back(s);
}

// Generates Markdown for Heading 1
void MD::headings1(std::string s) {
    toPrint.push_back("# " + s);
    userInput.push_back(s);
}

// Generates Markdown for Heading 2
void MD::headings2(std::string s) {
    toPrint.push_back("## " + s);
    userInput.push_back(s);
}

// Generates Markdown for Heading 3
void MD::headings3(std::string s) {
    toPrint.push_back("### " + s);
    userInput.push_back(s);
}

// Generates Markdown for Heading 4
void MD::headings4(std::string s) {
    toPrint.push_back("#### " + s);
    userInput.push_back(s);
}

// Generates Markdown for Heading 5
void MD::headings5(std::string s) {
    toPrint.push_back("##### " + s);
    userInput.push_back(s);
}

// Generates Markdown for Heading 6
void MD::headings6(std::string s) {
    toPrint.push_back("###### " + s);
    userInput.push_back(s);
}

// Generates Markdown for italics
void MD::italics(std::string s) {
    toPrint.push_back("*" + s + "*");
    userInput.push_back(s);
}

// Generates Markdown for strong text
void MD::strong(std::string s) {
    toPrint.push_back("**" + s + "**");
    userInput.push_back(s);
}

// Generates Markdown for strike-through text
void MD::strikeThrough(std::string s) {
    toPrint.push_back("~~" + s + "~~");
    userInput.push_back(s);
}

// Generates Markdown for horizontal rule
void MD::horizontalRule() {
    toPrint.push_back("---\n");
    userInput.push_back("Horizontal Line");
}

// Generates Markdown for block-quote text
void MD::blockQuote(std::string s) {
    toPrint.push_back(">" + s);
    userInput.push_back(s);
}

// Generates Markdown for website link
void MD::link(std::string url, std::string name) {
    toPrint.push_back("[" + name + "](" + url + ")"); 
    userInput.push_back(name + ", " + url);
}

// Generates Markdown for with hovering name
void MD::link(std::string url, std::string name, std::string hover) {
    toPrint.push_back("[" + name + "](" + url + "\"" + hover + "\")");
    userInput.push_back(name + ", " + url + ", " + hover); 
}

// Generates Markdown for unordered list
void MD::unorderedList(std::string s) {
    toPrint.push_back("* " + s);
    userInput.push_back(s);
}

// Generates Markdown for ordered list
void MD::orderedList(std::string s) {
    toPrint.push_back("1. " + s);
    userInput.push_back(s);
}

// Generates Markdown for image
void MD::image(std::string name, std::string url) {
    toPrint.push_back("![" + name + "](" + url + ")");
    userInput.push_back(name + ", " + url);
}

// Displays the Markdown created
void MD::preview() {
    for (int i = 0; i < toPrint.size(); i++) {
        std::cout << "Item" << i + 1 << " -- " << "User Input: " << userInput[i] << " | " << "Markdown: " << toPrint[i] << std::endl;
    }
}

// Removes element at specified number
void MD::removeElement(int index) {
    toPrint.erase(toPrint.begin() + index);
    userInput.erase(userInput.begin() + index);
}

// Changes element's location to specified location
void MD::changeElementLocation(int from, int to) {
    std::string temp1 = toPrint[from];
    std::string temp2 = toPrint[from];
    toPrint.erase(toPrint.begin() + from);
    userInput.erase(userInput.begin() + from);
    toPrint.insert(toPrint.begin() + to, temp1);
    userInput.insert(userInput.begin() + to, temp2);
}