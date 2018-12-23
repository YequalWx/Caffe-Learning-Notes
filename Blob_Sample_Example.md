# Sample Example of using Blob
Using Blob to storage a picture and make some sample functions.

The blob_sample_example.cpp has some sample function on blob, we can do some operation.

+ Definition
```
Blob<float> pic;
```
+ Get the shape of Blob
```
pic.shape_string()
```
 + Reshape Blob
 ```
 pic.Reshape(4,4,3,1);
 ```
 ***
## How to compiler caffe code? Use these order to compiler blob_sample_example.cpp :
1. **export LD_LIBRARY_PATH=$CAFFE_ROOT/build/lib/:$LD_LIBRARY_PATH**
2. **g++ -o blobexam blob_sample_example.cpp -I $CAFFE_ROOT/include/ -D CPU_ONLY -I $CAFFE_ROOT/.build_release/src/ -L $CAFFE_ROOT/build/lib/ -lcaffe**
***