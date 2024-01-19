#include "pbPlots.hpp"
#include "supportLib.hpp"
int main()
{   
    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');     RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();      std::vector<double> xs{-2, -1, 0, 1, 2};     std::vector<double> ys{2, -1, -2, -1, 2};          
    DrawScatterPlot(imageReference, 600, 400, &xs, &ys, errorMessage);          
    std::vector<double> *pngdata = ConvertToPNG(imageReference->image);     
    WriteToFile(pngdata, "example1.png");      
    DeleteImage(imageReference->image);          
    return 0;
}