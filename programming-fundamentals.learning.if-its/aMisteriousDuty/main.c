// 11/29/2022, 6:39:31 PM

#include <stdio.h>
#include <math.h>

#define lf double

lf pi = 3.14159;

int main()
{
    lf bridgeLength;
    scanf (" %lf", &bridgeLength);
    
    lf cliffHeight;
    scanf (" %lf", &cliffHeight);
    
    lf bridgeHeight;
    scanf (" %lf", &bridgeHeight);
    
    lf parkParameter;
    scanf (" %lf", &parkParameter);
    
    lf bridgeDepression = cliffHeight - bridgeHeight;
    
    lf catenaryConstant = ((pow((bridgeLength / 2), 2)) - (pow(bridgeDepression, 2))) / (2 * bridgeDepression);
    
    lf cliffDistance;
    if ((bridgeLength / 2) <= bridgeDepression)
    {
        cliffDistance = 0;
    }
    else if (bridgeHeight >= cliffHeight)
    {
        cliffDistance = bridgeLength;
    }
    else
    {
        cliffDistance = 2 * ((log(((bridgeLength / 2) / catenaryConstant) + sqrt(((pow((bridgeLength / 2), 2)) / (pow(catenaryConstant, 2))) + 1))) * catenaryConstant);
    }
    
    lf parkArea;
    if (cliffDistance > (bridgeLength / 2))
    {
        parkArea = (pow((parkParameter), 2) - ((pi * (pow(parkParameter, 2))) / 4) - pow((((parkParameter * sqrt(2)) - parkParameter) / 2), 2));
    }
    else if (cliffDistance < (bridgeLength / 2))
    {
        parkArea = ((pow(parkParameter, 2)) * (pi - 2)) / 8;
    }
    
    printf ("%.2lf\n", cliffDistance);
    printf ("%.2lf", parkArea);
    
    return 0;
}


