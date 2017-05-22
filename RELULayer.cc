#include <vector>
#include <math.h>
#include "RELULayer.h"

RELULayer::RELULayer (
  const int* input_shape,
  const int* output_shape,
  const char* prev,
  const char* next
):
  Layer(input_shape,output_shape,prev,next);
  
/**
 * execute rectifier serially
 **/
  void RELULayer::forwardProp(const vector<float> input,vector<float> &output) {
    for (int i=0; i < *input_shape; i++) {
       output[i]=fmax(0,input[i]);
    }
}
     
 
 
