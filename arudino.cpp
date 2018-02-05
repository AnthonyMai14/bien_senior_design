/*sample_obj
 * Purpose: To detect a signifianct change in position/angle
 * and return to detect_obj 
 * Variable: x1, x2, 
 *            y1, y2,
 *            z1, z2, (Position)
 *            gx1, gx2,
 *            gy1, gy2,
 *            gz1 gz2 (Gyroscope)
 * Function: acceleration()
 * 
  */

//TODO: find out if need to include vector classs
#import <vector.h>
class Sample_obj{
    private:
      //put variable
      double x1, y1, y2, z1;
      double gx1, gy1, gz1;
    public:
      Sample_obj();// default constructor
      Sample_obj(double x1, double y1, double z1,
                double gx1, double gy1, double gz1);
  }
Sample_obj::Sample_obj() {
  this->x1 = 0;
  this->x2 = 0;
  this->y1 = 0;
  this->y2 = 0;
  this->z1 = 0; 
  this->z2 = 0;
  //TODO: finish
  gx1, gx2, gy1, gy2, gz1 gz2
}
Sample_obj::Sample_obj(double x1, double x2, double y1, double y2, 
                double z1, double z2, double gx1,double gx2,
                double gy1,double gy2,double gz1,double gz2){
  this->x1 = x1;
  this->x2 = x2;
  this->y1 = y1;
  this->y2 = y2;
  this->z1 = z1; 
  this->z2 = z2;
  //TODO: finish
  gx1, gx2, gy1, gy2, gz1 gz2
}

std::vector<double> Sample_obj::acceleration() {
  std::vector data(12);
  data.at(0) = x2 - x1;
  data.at(1) = y2 - y1;
  data.at(2) = z2 - z1;
  //todo till data.at(5)
  return data;
}

class Detect_obj{
  private:
    //
  public:
}l