#include <fstream>
#include "DataAsFormat.h"

int main()
{
    std::ofstream fout("ini.txt");
    Printable* dataAsJSON = new DataAsJSON("data", Format::kJSON);
    SaveToAsHTML staHTML;
    staHTML.save(fout, dataAsJSON);
}