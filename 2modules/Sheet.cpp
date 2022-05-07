#include "Sheet.h"

Sheet::Sheet()
{
    path = "";
}

Sheet::Sheet(std::string sheetPath)
{
    setPath(sheetPath);
}

void Sheet::setPath(const std::string& sheetPath)
{
    path = sheetPath;
}

std::vector<std::vector<float>> Sheet::readAsFloat() const
{
    auto* data = new std::vector<std::vector<float>>;
    std::fstream file;
    file.open(path, std::ios::in);

    std::vector<float> row;
    std::string word, line;

    while (file >> line) 
    {
        row.clear();
        std::stringstream s(line);
  
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ';'))
        {
            if(word.empty())
            {
	            row.push_back(0);
            }
            else
            {
                float num = std::stof(word);
                row.push_back(num);
            }
        }

        // add current row to data vector
    	data->push_back(row);
    }

    file.close();

    return *data;
}

