#include <vector>
#include <cstdio>
#include <math.h>
#include "SoftmaxLayer.h"

SoftmaxLayer::SoftmaxLayer (
  const int* input_shape,
  const int* output_shape,
  const char* prev,
  const char* next,
  const char* class_names
):
  Layer(input_shape,output_shape,prev,next),
  class_names(class_names);
/**
 * execute Softmax serially
 **/
  void SoftmaxLayer::forwardProp(const vector<float> input,vector<float> &output) {
    float Z = 0;
    for (int i=0; i < *input_shape; i++) {
       Z += exp(input[i]);
    }
     
    for (int i=0; i < *input_shape; i++) {
       output[i]=exp(input[i])/Z;
    }
 /** 
  * print 10 best guesses
  */
    int largest[10]=get_largest_10(output,output_shape); // need to write this function
    for (i=0; i<10; i++) {
      cout << i << class_names(largest[i]) << "\n";
    }
  }

     
 
 
