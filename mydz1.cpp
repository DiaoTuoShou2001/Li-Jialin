#include "any"
#include "ostream"
#include <cmath>
#include <string>

class guandao {

private:
  std::string name; // 管道名称
  double length;    // 管道长度
  bool underMaintenance;
  // guandao 管道
public:
  guandao(const std::string name, double length, bool underMaintenance)
      : name(name), length(length), underMaintenance(underMaintenance) {}

  guandao() : name(""), length(0.0), underMaintenance(false) {}

  void setname(const std::string newname) { name = newname; }
  void std::string getname() const { return name; }

  void setlenth(double newlenth) {
    if (newlenth > 0) {
      length = newlenth;
    } else {
      std::cerr << "cuowuchangdu" << std::endl;
    }
  }

  void getlenth() const { return length; }
  void setmaint(bool isunder) { underMaintenance = isunder; }
  void getmaint() const { return underMaintenance; }

  void displayifo() {
    std::cout << "Pipe name:" << name << "\nlength:" << length
              << "\nUnder Maintenance:" << (underMaintenance ? "yes" : "no")
              << std::endl;
  }
} class bengzhan {
private:
  std::string name;
  int number;
  int worknumber;
  double xiaolv;

public:
  bengzhan(const std::string name,shuliang(shuliang),yunxingshuliang(yunxingshuliang),xiaolv(xiaolv)) : name(name), numberinumber), worknumber(worknumber),xiaolv(xiaolv) {}

  bengzhan() : name(""), number(0), worknumber(0), xiaolv(0.0) {}

  void setname(const std::string newname) { name = newname; }
  void std::string getname() const { return name; }

  void setnumber(int newnumber) {
    if (newnumber > 0) {
      number = newnumber;
    } else {
      std::cerr << "shuliangwubunengwei 0 " << std::endl;
    }
  }
  void setworknumber(int newworknumber) { worknumber = newworknumber; }
  void setxiaolv(double newxiaolv) { xiaolv = newxiaolv; }
  void getnumber() const { return number; }
  void getworknumber() const { return worknumber; }
  void getxiaolv() const { return xiaolv; }
  void displayifo() {
    std::cout << "Pipe name:" << name << "\nlength:" << length
              << "\nUnder Maintenance:" << (underMaintenance ? "yes" : "no")
              << std::endl;
  }

}


int main() {
  guandao1 = guandao("shenzhou", 250.0, flase);
  guandao1.displayifo();

  return 0;
}
