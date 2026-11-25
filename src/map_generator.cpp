#include <opencv2/opencv.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

std::vector<int> access_data() {
    std::string token;
    std::ifstream file ("../map.json");
    std::vector<int> data (152*121);   // pre-allokeret i forhold til mappet's bredde og længde (skal laves om til en variabel)

    


    for(int i = 0 ; i < 152*121 ; i++){
        std::getline(file, token, ',');
        data[i] = std::stoi(token);

    }

    for(int& value : data){
        if (value == -1)
        value = 255;
    }

    return data;


}

int main() {
    std::vector<int> test = access_data();
    
    for(int i = 0 ; i < 10 ; i++)
        std::cout << test[i] << std::endl;

    cv::Mat raw(121, 152, CV_32SC1, test.data());
    cv::Mat img;
    cv::normalize(raw, img, 0,255, cv::NORM_MINMAX, CV_8U);
    cv::imshow("test", img);
    cv::waitKey(0);

    return 0;
}
