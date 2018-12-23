#include<vector>
#include<iostream>
#include<caffe/blob.hpp>
#include<fstream>
using namespace caffe;
using namespace std;

int main(void)
{
    Blob<float> pic;
    cout<<"Size:"<<pic.shape_string()<<endl;
    pic.Reshape(4,4,3,1);
    cout<<"Size:"<<pic.shape_string()<<endl;
    return 0;
}