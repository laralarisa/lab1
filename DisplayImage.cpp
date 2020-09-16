#include <stdio.h>
#include <opencv2/opencv.hpp>
// #include <cv.h>
// #include <highgui.h>

using namespace cv;



int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
//
    Mat image;
    image = imread( argv[1], 1 );

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
//    
    Mat HSV;
    cvtColor(image, HSV, COLOR_BGR2HSV);
    imshow("hsv image", HSV);
    
//
    Mat grey;
    cvtColor(image, grey, COLOR_BGR2GRAY);
    imshow("Grayscale Image", grey);
//
   Mat bin;
   threshold(image, bin, 125, 255, THRESH_BINARY);
   imshow("Binary Image", bin);
// Perform binary thresholding on the image with T = 125

   Mat cont;
   circle(image, Point(398, 421), 6, Scalar (0,0,255), 2); //там выделяется глазик у акулочки
   rectangle(image, Point(270, 98) , Point(310, 120), Scalar(0, 255, 0), 2, 8, 0);  
   imshow("D Image",image);



    waitKey(0);

    return 0;
}

