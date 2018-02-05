/*sample_obj
 * Purpose: To detect a signifianct change in position/angle
 * and return to detect_obj 
 * Variable: x, y, z, (Position)
 *            gx, gy, gz (Gyroscope)
 * Function: acceleration()
 * 
 */
//TODO: find out if need to include vector classs

/*
 * Base on the index, keep adding 
 */
 
 #include <QueueArray.h>

void setup() {
 
  /*
   * Sample_obj constructor. When declaring and object of type Sample_obj
   * You will use this struct to store the coordinate data that you get from
   * the gyroscope
  */
  struct Sample_obj{
    //put variable
    double x, y, z;
    double gx, gy, gz;
    
  }
  
  
  /*
   * Storage_obj: will store 2 Sample_obj and calculate the acceleration
   * between the 2 Sample_oject
   */
  /*struct Storage_obj{
    //sample_obj 
    Sample_obj a;
    Sample_obj b;
    //acceleration vector
    vector<double> acceleration(6);
  
    Storage_obj(Sample_obj, Sample_obj);    
  }
  Storage_obj::Storage_obj(Sample_obj a, Sample_obj b) {
  
    this->Sample_obj a = Sample_obj a;
    this->Sample_obj b = Sample_obj b;
    
    acceleration.at(0) = b.x - a.x;
    acceleration.at(1) = b.y - a.y;
    acceleration.at(2) = b.z - a.z;
    acceleration.at(3) = b.gx - a.gx;
    acceleration.at(4) = b.gy - a.gy;
    acceleration.at(5) = b.gz - a.gz;
  }*/
  double avg_acceleration(Sample_obj &a, Sample_obj &b) {
    double acceleration[6];
    
    acceleration[0] = b.x - a.x;
    acceleration[1] = b.y - a.y;
    acceleration[2] = b.z - a.z;
    acceleration[3] = b.gx - a.gx;
    acceleration[4] = b.gy - a.gy;
    acceleration[5] = b.gz - a.gz;
    
    return acceleration;
  }
  
  struct Detect_obj{
    const int VECTOR_WINDOW = 5; //the size of the window
    const int COMPARE_SIZE = 4;
    const int SIGNIFICANT_THRESHOLD = 3;
    
    double acceleration_array[VECTOR_WINDOW];
    bool detect_significant();
  }
  bool Detect_obj::detect_significant() {
    //TODO: algorithm
    if (acceleration_array[VECTOR_WINDOW - 1] != NULL) {
      int num_of_sign_change = 0;
      for (int i = 0; i < VECTOR_WINDOW - 1; ++i) {
        //calculate if pos or neg for both index
        //compare if change in pos/neg
          //if yes, increase num of sign change by one
      }
      if (num_of_sign_change >= SIGNIFICANT_THRESHOLD) {
        return true;
      }
    }
    return false;
  }

  Detect_obj main_obj;
  QueueArray <Sample_obj> sample_obj_q;
  index = 0;
}

void loop() {
  //get x,y,z,gx,gy,gz data from Gyroscope
  Sample_obj data;
  
  //store the data from Gyroscope in a Storage_obj and push into sample_obj_q
  data.x = gyroscope.x;
  data.y = gyroscope.y;
  data.z = gyroscope.z;
  data.gx = gyroscope.gx;
  data.gy = gyroscope.gy;
  data.gz = gyroscope.gz;

  
  sample_obj_q.push(data);
  
  if (sample_obj_q.count == 2) {
    //take 2 value of Sample_obj
    Sample_obj a = sample_obj_q.pop();
    Sample_obj b = sample_obj_q.front();
    
    //TODO: calculate acceleration average
    double acceleration_avg = 0;
    
    //add to Detect_obj
    main_obj.acceleration_array[index];
    if (index >= 5) {
      index = 0;
    }
    else {
      ++index;
    }
    
     if (main_obj.detect_significant()) {
        //send message
        //slowdown time
        //exit program OR call 911?
     }
  }
}