#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Load the image
    Mat image = imread("paper.jpg");

    // Check if the image is loaded
    if(image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // Display the original image
    namedWindow("image", WINDOW_FREERATIO);
    imshow("image", image);
    waitKey(0);

    // Define the rectangle to crop
    Rect croppedRectangle = Rect(537, 561, 450, 140);
    // Crop the image
    Mat CroppedImage = image(croppedRectangle);

    // Display the cropped image
    namedWindow("Cropped", WINDOW_FREERATIO);
    imshow("Cropped", CroppedImage);

    // Output the size of the cropped image
    cout << CroppedImage.size() << endl;
    waitKey(0);

    return 0;
}

/* --OPEN FILE EXPLORER, LET USER IMPORT IMAGE TO CONVERT
#include <iostream>
#include <Windows.h>

using namespace std;

string fileDialog(LPCSTR fileType) {
    OPENFILENAMEA ofn;
    char szFile[300];
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = '\0';
    ofn.nFilterIndex = 1;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = fileType;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    if (GetOpenFileNameA(&ofn)) {
        return ofn.lpstrFile;
    }
    return "";
}

int main()
{
    cout << fileDialog("Any File\0*") << endl;
    cout << fileDialog("EXE File\0*.exe") << endl;
    cout << fileDialog("MP4 File\0*.mp4") << endl;
    return 0;
}