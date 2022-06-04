#include <fstream>
#include <sstream>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
using namespace dnn;

int main(int argc, char** argv)
{
    //����ģ��
    Net net = readNetFromTensorflow("C:\\Users\\zyh\\Desktop\\1\\model.pb");
    Mat frame = imread("C:\\Users\\zyh\\Desktop\\1\\12345.jpg", IMREAD_GRAYSCALE);
    Mat blob = blobFromImage(frame, 1.0, Size(28, 28), Scalar(), false, false);
    net.setInput(blob);
    Mat pred = net.forward();
    
    //������
    Point maxLoc;
    minMaxLoc(pred, NULL, NULL, NULL, &maxLoc);
    cout << maxLoc.x << endl;

    //��ʾͼƬ
    imshow("img", frame);
    waitKey(0);
    return 0;
}
