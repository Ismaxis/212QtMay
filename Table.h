#ifndef TABLE_H
#define TABLE_H

#include <QDir>
#include "Sheet.h"
#include "2modules/tableData.h"

class Table
{
public:
    Table()
    {
        Sheet reader;
        QDir dir("../212QtMay/tables");
        reader.setPath(dir.absoluteFilePath("air.csv").toStdString());
        tables.push_back(reader.readAsFloat());
        reader.setPath(dir.absoluteFilePath("fuel.csv").toStdString());
        tables.push_back(reader.readAsFloat());
    }

    TableData getData(float temp, int tableId, int pmiOrPms = 2)
    {
        // 0 - air, 1 - fuel
        // 2 - pmi, 3 - pms;
        TableData result;

        for(int i = 1; i < tables[tableId].size(); i++)
        {
            if(tables[tableId][i][0] > temp)
            {
                result.tLow = tables[tableId][i - 1][0];
                result.cLow = tables[tableId][i - 1][pmiOrPms];
                result.tHigh = tables[tableId][i][0];
                result.cHigh = tables[tableId][i][pmiOrPms];
                break;
            }
        }
        return result;
    }

private:
    std::vector<std::vector<std::vector<float>>> tables;
};

#endif // TABLE_H
