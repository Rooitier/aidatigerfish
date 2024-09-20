#include <string>

std::string line;

int dssd_number;
std::string xy;
int strip_number;
int threshold;

void processAidaStrips(std::ifstream& aida_strips_file, std::map<int, int>& aida_strips)
{
    while(std::getline(aida_strips_file, line))
    {
        if(line[0] == '#') continue;

        std::istringstream iss(line);
        iss >> dssd_number >> xy >> strip_number >> threshold;
        aida_strips[strip_number] = threshold;
    }
}

int main()
{
    std::ifstream aida_strips_file("/u/jbormans/S100/analysis/aidatigerfish/AIDA_strips.txt");
    std::map<int, int> aida_strips;

    processAidaStrips(aida_strips_file, aida_strips);

    for (auto const& x : aida_strips)
    {
        std::cout << x.first  // string (key)
                  << ':'
                  << x.second // string's value 
                  << std::endl ;
    }

    return 0;
}