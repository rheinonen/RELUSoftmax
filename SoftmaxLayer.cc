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

/*
* sort through and find indices of 10 most probable classes
*/

void get_largest_10(vector<float> probs,int (&largest)[10]){
int N=size(probs);
float last=100;
int temp_id;
float temp=-1;
for (int i=0; i < 10; i++){
   for (int j=0; j < N; i++){
       if (probs[j] < last && probs[j] > temp){
          temp=probs[j];
          temp_id=j;
          }
       }
       largest[i]=temp_id;
       last=temp;
   }
}


/**
 * execute Softmax serially
 **/
  void SoftmaxLayer::forwardProp(const vector<float> input,vector<float> &output) {
  int N=size(input);  
  float Z = 0;
    for (int i=0; i < N; i++) {
       Z += exp(input[i]);
    }
     
    for (int i=0; i < N; i++) {
       output[i]=exp(input[i])/Z;
    }
 /** 
  * print 10 best guesses
  */
    int largest[10];
    get_largest_10(output,largest);
    for (i=0; i<10; i++) {
      cout << i << class_names(largest[i]) << "\n";
    }
  }

     
 
 
