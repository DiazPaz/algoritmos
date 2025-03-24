#include <iostream>
#include <vector>
using namespace std; 

int main(void)
{
    int numPoints, x, y; 
    int minX, maxX; 
    int minY, maxY; 
    vector<int> xCoord; 
    vector<int> yCoord;

    cin >> numPoints; 
    
    for(unsigned i = 0; i < numPoints; i++)
    {
        cin >> x >> y; 
        xCoord.push_back(x);
        yCoord.push_back(y);
    }

    // sabemos que son 2 rectangulos

    // hay que sacar el área mínima donde entran todos los puntos en estos 2 rectangulos
    
    // primero puedo identificar el x más chico y el x más grande
    // luego el y más chico y el y más grande 

    // después "generar" un rectángulo con esas medidas

    minX = xCoord[0];
    maxX = xCoord[0];
    minY = yCoord[0];
    maxY = yCoord[0];

    for(unsigned i = 1; i < xCoord.size(); i++)
    {
        if(minX >= xCoord[i])
            minX = xCoord[i];

        if(maxX < xCoord[i])
            maxX = xCoord[i];
    }

    for(unsigned i = 1; i < yCoord.size(); i++)
    {
        if(minY >= yCoord[i])
            minY = yCoord[i];

        if(maxY < yCoord[i])
            maxY = yCoord[i];
    }

    // (minX, minY) y (maxX, maxY) <- en base a esto se hace el rectangulo mayor 
    // el area de este rectangulo debería de ser el área máxima

    // NOTA: cuando hay 2 puntos, el área es 0, porque se restan

    return 0;
}