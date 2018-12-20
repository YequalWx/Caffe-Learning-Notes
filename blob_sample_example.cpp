#include<vector>
#include<iostream>
#include<caffe/blob.hpp>
#include<windows.h>
#include<fstream>
using namespace caffe;
using namespace std;

int width=0;
int height=0;

bool readBmp(char *pic_name,int *Pic)
{
    FILE *fp=fopen(pic_name,"rb");
    if(fp==0)
    return 0;
    fseek(fp,sizeof(BITMAPFILEHEADER),0);
    BITMAPINFOHEADER head;
    fread(&head, sizeof(BITMAPINFOHEADER), 1,fp);
    width = head.biWidth;
    height = head.biHeight;
    int count = head.biBitCount;
    int lineByte = (width*count/8+3)/4*4;
    if(count == 8)
    {
        RGBQUAD *pColorTable = new RGBQUAD[256];
        fread(pColorTable,sizeof(RGBQUAD),256,fp);
    }
    Pic = new int[lineByte*height];
    fread(Pic,1,lineByte*height,fp);
    fclose(fp);
    return 1;
}

int main(void)
{
    Blob<int> pic;
    char *pic_name = "one.jpg";
    int *Picture;
    bool state = readBmp(pic_name,Picture);
    if(!state)
    {
        cout<<"Read File Error!"<<endl;
        return 0;
    }
    pic.Reshape(width,height,3,1);
    int *p = Pic.mutable_cpu_data();
    for(int i=0;i<pic.count();++i)
    {
        p[i] = Picture[i];
    }

    count<<"ASUM = "<<pic.asum_data()<<endl;
    return 0;
}