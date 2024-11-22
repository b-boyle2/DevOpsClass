#include <iostream>
#include <tinyxml2.h>
#include <string>

void printBookTitles(const std::string &filename) {
    // Create a TinyXML-2 document object
    tinyxml2::XMLDocument doc;

    // Parse the XML file
    tinyxml2::XMLError result = doc.LoadFile(filename.c_str());
    if (result != tinyxml2::XML_SUCCESS) {
        std::cerr << "Could not parse the file " << filename << std::endl;
        return;
    }

    // Get the root element
    tinyxml2::XMLElement *root = doc.RootElement();
    if (!root) {
        std::cerr << "No root element found in the XML file" << std::endl;
        return;
    }

    // Iterate over the child elements of the root
    for (tinyxml2::XMLElement *bookElement = root->FirstChildElement("book"); bookElement; bookElement = bookElement->NextSiblingElement("book")) {
        // Find the title element within each book
        tinyxml2::XMLElement *titleElement = bookElement->FirstChildElement("title");
        if (titleElement) {
            // Print the book title
            const char *title = titleElement->GetText();
            if (title) {
                std::cout << "Book Title: " << title << std::endl;
            }
        }
    }
}

int main() {
    printBookTitles("catalog.xml");
    return 0;
}
