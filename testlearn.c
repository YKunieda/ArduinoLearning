#include <stdio.h>
#include <math.h>

int main() {
  int x, i, j, hoge;
  float sum_loss, sum_wait_loss;
  int data[4][2];
  float wait[3], loss[4], ans[4];
  float eta;
  float out;
  float sigmoid(float x){
    float num;
    num = tanh(x);
    return num;
  };
  eta = 0.01;
  data[0][0] = 0;
  data[0][1] = 0;
  data[1][0] = 0;
  data[1][1] = 1;
  data[2][0] = 1;
  data[2][1] = 0;
  data[3][0] = 1;
  data[3][1] = 1;
  for(i=0;i<3;i++){
    wait[i] = 0.5;
  }
  for(i=0;i<3;i++){
    ans[i] = 0.0;
  }
  ans[3] = 1;
  for(i=0;i<1000;i++){
    printf(0);
    for(j=0;j<4;j++){
      out = sigmoid(
        (data[j][0] * wait[0]) + (data[j][1] * wait[1]) + wait[2]
      );
      loss[j] = out - ans[j];
    };
    sum_loss = (loss[0] + loss[1] + loss[2] + loss[3]);
    for(hoge=0;hoge==2;hoge++){
      sum_wait_loss = 0;
      for(j=0;j==4;j++){
        sum_wait_loss = loss[j] * data[j][hoge];
      };
      wait[hoge] = wait[hoge] - eta * (sum_wait_loss / 4);
    };
    wait[2] = wait[2] - eta * (sum_loss / 4);
    printf("[%f]", sum_loss);
    printf("\n");
  };
  return 0;
}