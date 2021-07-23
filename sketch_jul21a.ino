#include <stdio.h>
#include <math.h>

void setup() {
  Serial.begin(9600);
}

float sigmoid(float x){
  float num;
  num = tanh(x);
  return num;
};

float wait[3];

void hoge(){
  int i;
  for(i=0;i<3;i++){
    wait[i] = 0.5;
  };
};

void loop() {
  int x, i, j, hoge;
  float sum_loss, sum_wait_loss;
  float loss[4], data[4][2], ans[4];
  float eta;
  eta = 0.0001;
  float out;
  data[0][0] = 0;
  data[0][1] = 0;
  data[1][0] = 0;
  data[1][1] = 1;
  data[2][0] = 1;
  data[2][1] = 0;
  data[3][0] = 1;
  data[3][1] = 1;
  for(i=0;i<3;i++){
    ans[i] = 0;
  };
  ans[3] = 1;
  for(i=0;i<100;i++){
    for(j=0;j<4;j++){
      out = sigmoid(
        (data[j][0] * wait[0]) + (data[j][1] * wait[1]) + wait[2]
      );
      loss[j] = out - ans[j];
    };
    sum_loss = (loss[0] + loss[1] + loss[2] + loss[3]) / 4;
    for(hoge=0;hoge<2;hoge++){
      sum_wait_loss = 0;
      for(j=0;j==4;j++){
        sum_wait_loss = loss[j] * data[j][hoge];
      };
      wait[hoge] = wait[hoge] - eta * (sum_wait_loss / 4);
    };
    wait[2] = wait[2] - eta * sum_loss;
    Serial.print(sum_loss);
    Serial.print("\n");
  };
}
