#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class Sheet
{
public:
    Sheet();
    Sheet(std::string sheetPath);

	// creates associated Sheet if empty
    void setPath(const std::string& sheetPath);
    std::vector<std::vector<float>> readAsFloat() const;

private:
    // associated sheet
    std::string path;
};
