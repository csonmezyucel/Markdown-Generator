// Code by Cevat Sonmez Yucel
#ifndef MD_H
#define MD_H
#include <string>
#include <vector>
#include <iostream>

class MD {
public:
    void body(std::string s);
    void headings1(std::string s);
    void headings2(std::string s);
    void headings3(std::string s);
    void headings4(std::string s);
    void headings5(std::string s);
    void headings6(std::string s);
    void italics(std::string s);
    void strong(std::string s);
    void strikeThrough(std::string s);
    void horizontalRule();
    void blockQuote(std::string s);
    void link(std::string url, std::string name);
    void link(std::string url, std::string name, std::string hover);
    void unorderedList(std::string s);
    void orderedList(std::string s);
    void image(std::string name, std::string url);
    void preview();
    void removeElement(int index);
    void changeElementLocation(int from, int to);

    // String vector containing generated Markdown
    std::vector<std::string> toPrint;

private:
    // String vector containing user input
    std::vector<std::string> userInput;
};

#endif